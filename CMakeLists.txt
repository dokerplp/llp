cmake_minimum_required(VERSION 3.23)
project(lab1_)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET (CMAKE_CXX_COMPILER "/usr/bin/clang++")

include(ExternalProject)
ExternalProject_Add(cereal
        GIT_REPOSITORY https://github.com/USCiLab/cereal.git
        PREFIX cereal
        SOURCE_DIR "${CMAKE_BINARY_DIR}/third-party/cereal"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        )
include_directories(${CMAKE_BINARY_DIR}/third-party/cereal/include)

file(GLOB SRC "src/*/*.h" "src/*/*.cpp" "test/*.h" "test/*.cpp")
add_executable(lab1_ src/main.cpp ${SRC})