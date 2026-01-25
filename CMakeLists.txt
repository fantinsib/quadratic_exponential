####################################################
#       ROOT CMAKE
####################################################

cmake_minimum_required(VERSION 3.20)
project(quadratic_exponential LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(quadratic_exponential
            src/schemes/qe/qe.cpp
            src/schemes/euler/eulerblackscholes.cpp
            src/schemes/euler/eulerheston.cpp
            src/engine/montecarlo.cpp)

target_include_directories(quadratic_exponential
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_compile_options(quadratic_exponential PRIVATE -Wall -Wextra -Wpedantic)

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.0
)

FetchContent_MakeAvailable(Catch2)


enable_testing()

add_executable(quadratic_exponential_tests
    tests/test_cpp/test_models.cpp
    tests/test_cpp/test_schemes/test_euler.cpp
)

target_link_libraries(quadratic_exponential_tests
    PRIVATE
        quadratic_exponential
        Catch2::Catch2WithMain
)

add_test(NAME quadratic_exponential_tests COMMAND quadratic_exponential_tests)