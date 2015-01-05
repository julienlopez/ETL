cmake_minimum_required(VERSION 2.8)

set(BIN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin/)
message(STATUS "bin dir: " ${BIN_DIR})

#set(LIBRARY_OUTPUT_PATH ${BIN_DIR})
set(EXECUTABLE_OUTPUT_PATH ${BIN_DIR})

add_subdirectory(tests)
