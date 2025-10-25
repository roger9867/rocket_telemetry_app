#####################################################################################
# General project setup
#####################################################################################
cmake_minimum_required(VERSION 3.18)
project(RocketTelemetry LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#####################################################################################
# Compiled binaries to build -> bin
#####################################################################################
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#####################################################################################
# Declare external cmake resource folder in src/
#####################################################################################
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")



######################################################################################
# Server executable
######################################################################################

# Domain files
file(GLOB DOMAIN_SOURCES
        "src/domain/*.cpp"
        "src/domain/*.h"
)
add_library(domain ${DOMAIN_SOURCES}
        src/domain/rocket_design.cpp
        src/domain/rocket_design.h
        src/domain/flight_log.cpp
        src/domain/flight_log.h
        src/domain/rocket_image.h
)
target_include_directories(domain PUBLIC "src/domain")

# Infrastructure files
file(GLOB_RECURSE INFRA_SOURCES
        "src/infrastructure/*.cpp"
        "src/infrastructure/*.h"
)
add_library(infrastructure ${INFRA_SOURCES})
target_include_directories(infrastructure PUBLIC "src/infrastructure")

# Service files
file(GLOB_RECURSE SERVICE_SOURCES
        "src/service/*.cpp"
        "src/service/*.h"
)
add_library(service ${SERVICE_SOURCES}
        src/service/flightlog_service.cpp
        src/service/flightlog_service.h)
target_include_directories(service PUBLIC "src/service")
target_link_libraries(service PUBLIC domain infrastructure)

# API files
file(GLOB_RECURSE API_SOURCES
        "src/api/*.cpp"
        "src/api/*.hpp"
)

# Zuerst die Library erstellen
add_library(api ${API_SOURCES}
        src/api/dto/json_serializable.h
        src/api/controller/flight/flight_create_command.cpp
        src/api/controller/flight/flight_create_command.h
        src/api/controller/flight/flight_delete_command.cpp
        src/api/controller/flight/flight_delete_command.h
        src/api/controller/flight/flight_read_command.cpp
        src/api/controller/flight/flight_read_command.h
        src/api/controller/rocket_design/rocket_create_command.cpp
        src/api/controller/rocket_design/rocket_create_command.h
        src/api/controller/rocket_design/rocket_delete_command.cpp
        src/api/controller/rocket_design/rocket_delete_command.h
        src/api/controller/rocket_design/rocket_update_command.cpp
        src/api/controller/rocket_design/rocket_update_command.h
        src/api/controller/rocket_design/rocket_read_command.cpp
        src/api/controller/rocket_design/rocket_read_command.h
        src/api/controller/command_handler.h
        src/api/controller/command_handler.cpp
        src/api/controller/connection_handler.cpp
        src/api/controller/connection_handler.h
        src/api/dto/json_serializable.cpp
        src/api/dto/flightlog_serializable.cpp
        src/api/dto/flightlog_serializable.h
        src/infrastructure/persistence/db/postgres_database.cpp
        src/infrastructure/persistence/db/postgres_database.h
        src/infrastructure/persistence/repository/rocket_design_repository.cpp
        src/infrastructure/persistence/repository/rocket_design_repository.h
        src/infrastructure/persistence/repository/i_repository.h
        src/api/dto/rocket_design_serializable.cpp
        src/api/dto/rocket_design_serializable.h)

# Dann Include-Pfade setzen
target_include_directories(api PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/httplib
        ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

# Server executable bauen
add_executable(rocket_server src/main.cpp)
target_link_libraries(rocket_server PRIVATE api service domain infrastructure)

#############################################################################
# Libpqxx einbinden
#############################################################################

# pqxx (PostgreSQL) einbinden
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBPQXX REQUIRED libpqxx)

if(LIBPQXX_FOUND)
    message(STATUS "Found libpqxx: ${LIBPQXX_LIBRARIES}")
    target_include_directories(rocket_server PRIVATE ${LIBPQXX_INCLUDE_DIRS})
    target_link_libraries(rocket_server PRIVATE ${LIBPQXX_LIBRARIES})
else()
    message(FATAL_ERROR "libpqxx not found!")
endif()

target_link_libraries(rocket_server PRIVATE uuid)


########################################################################################
# build Google Test
########################################################################################

# force static libraries for Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(lib/googletest)

####################
# GTest executable
####################

# GTest und Test-Executable
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

add_executable(unit_tests ${TEST_SOURCES})

# Link auf GTest, pthread und dein Projekt
target_link_libraries(unit_tests
        PRIVATE
        gtest_main
        domain
        infrastructure
        service
        api
)

# Include-Pfade für Tests
target_include_directories(unit_tests PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Aktiviert CTest integration
enable_testing()
include(GoogleTest)
gtest_discover_tests(unit_tests)
