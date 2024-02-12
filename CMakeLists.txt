cmake_minimum_required(VERSION 3.27)
project(Tutorial)

set(CMAKE_CXX_STANDARD 23)

find_package(Catch2 3 REQUIRED)

add_executable(Tutorial
        mujin-test.cpp
        divar-test.cpp
        digikala-test.cpp
        interviews.cpp)
target_link_libraries(Tutorial Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(Tutorial)
