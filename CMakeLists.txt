cmake_minimum_required(VERSION 3.7)
project(PW_AudioLED)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c udp.c udp.h BBB_P10.c BBB_P10.h Images)

add_executable(PW_AudioLED ${SOURCE_FILES})
target_link_libraries(PW_AudioLED jack m)
# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK2 REQUIRED gtk+-2.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK2_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK2_LIBRARY_DIRS})

TARGET_LINK_LIBRARIES(PW_AudioLED ${GTK2_LIBRARIES})
