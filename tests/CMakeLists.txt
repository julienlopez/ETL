cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11 -g -O0 --coverage -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align -Wwrite-strings -Wmissing-declarations -Wredundant-decls -Winline -Wno-long-long -Wuninitialized -Wconversion)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -g --coverage")

find_package(GTest REQUIRED)

include_directories(../)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB_RECURSE sources ./*)

add_executable(tests ${sources})

target_link_libraries(tests
		pthread
        ${GTEST_LIBRARIES}
		gmock
)
