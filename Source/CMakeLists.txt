cmake_minimum_required (VERSION 3.20)

# INCLUDE 3RD PARTY LIBRARIES
include("${CMAKE_SOURCE_DIR}/Scripts/FetchLibraries.cmake")

# POPULATE 3RD PARTY LIBRARIES 
FetchContent_MakeAvailable(glfw)

# Add source to this project's executable.
file(GLOB_RECURSE SUBDIRECTORIES "${CMAKE_SOURCE_DIR}/Source/*.h" "${CMAKE_SOURCE_DIR}/Source/*.cpp")
source_group("Source" "${CMAKE_SOURCE_DIR}/Source" ${SUBDIRECTORIES}) 
add_executable ("Source" main.cpp ${SUBDIRECTORIES})

target_include_directories("Source" PRIVATE "${CMAKE_SOURCE_DIR}/Source")

target_link_libraries("Source" PRIVATE glfw)

# TODO: Add tests and install targets if needed.
