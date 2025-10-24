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
add_library(domain ${DOMAIN_SOURCES})
target_include_directories(domain PUBLIC "src/domain")

# Infrastructure files
file(GLOB INFRA_SOURCES
        "src/infrastructure/*.cpp"
        "src/infrastructure/*.h"
)
add_library(infrastructure ${INFRA_SOURCES})
target_include_directories(infrastructure PUBLIC "src/infrastructure")

# Service files
file(GLOB SERVICE_SOURCES
        "src/service/*.cpp"
        "src/service/*.h"
)
add_library(service ${SERVICE_SOURCES})
target_include_directories(service PUBLIC "src/service")
target_link_libraries(service PUBLIC domain infrastructure)

# API files
file(GLOB_RECURSE API_SOURCES
        "src/api/*.cpp"
        "src/api/*.hpp"
)
add_library(api ${API_SOURCES})
add_executable(rocket_server src/main.cpp)
target_link_libraries(rocket_server PRIVATE api service domain infrastructure)



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
