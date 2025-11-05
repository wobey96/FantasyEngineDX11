cmake_minimum_required (VERSION 3.20)

# PROJECT NAME
project ("FantasyEngineDX11")

# SETTING CMAKE OPTIONS
set(CMAKE_CXX_STANDARD 20)

# COMPILER VERSION CHECK 
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	message(STATUS "Using MSVS Version, ${MSVC_VERSION}")
	else()
	message(FATAL_ERROR "Compiler not supported")
endif()

# SETTING OUTPUT DIRECTORY
add_subdirectory ("Source")
