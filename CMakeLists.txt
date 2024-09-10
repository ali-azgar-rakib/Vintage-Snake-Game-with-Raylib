cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(snake)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(PLATFORM "Desktop" CACHE STRING "Platform to build for.")

# Dependencies
set(RAYLIB_VERSION 5.5)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED

# Our Project

add_executable(${PROJECT_NAME} 
                            ./main.cpp
                            ./src/body/food.cpp
                            )
#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} raylib)

