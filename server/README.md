# Rocket Telemetry Server

Dieses Repository enthält den Rocket Telemetry Server, die dazugehörigen Unit-Tests und Dockerfiles für den Bau und die Ausführung.

---

## CMake build process

mkdir -p build  
cd build  
  
cmake .. 
make

### run server and test executables separately
./bin/rocket_server  
./bin/unit_tests

--- 

## Build server container and run it
docker build -f Dockerfile.server -t rocket_server .  
docker run --rm rocket_server

## Build unit test container and run all tests
docker build -f Dockerfile.tests -t rocket_tests .  
docker run --rm rocket_tests

