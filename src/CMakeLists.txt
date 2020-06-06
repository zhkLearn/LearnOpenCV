cmake_minimum_required(VERSION 3.5)

option(BUILD_SHARED_LIBS "BUILD_SHARED_LIBS" ON)

if(NOT CMAKE_TOOLCHAIN_FILE)
    if(WIN32 AND NOT CYGWIN)
        set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Installation Directory")
    else()
        set(CMAKE_INSTALL_PREFIX "/usr/local" CACHE PATH "Installation Directory")
    endif()
else()
    # any cross-compiling
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Installation Directory")
endif()

project(LearnOpenCV)

set(CMAKE_DEBUG_POSTFIX "D")

add_subdirectory(2_1)
add_subdirectory(2_3)
add_subdirectory(2_5)