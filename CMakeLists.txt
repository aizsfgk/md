cmake_minimum_required(VERSION 2.6)

project(md CXX)

include_directories(${PROJECT_SOURCE_DIR})
add_subdirectory(md/base)
add_subdirectory(md/net)
