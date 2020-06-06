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

project(2_1)

set(OpenCV_STATIC True)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(2_1 2_1.cpp)
target_link_libraries(2_1 ${OpenCV_LIBS})
set_property(TARGET 2_1 APPEND PROPERTY DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

install(
   TARGETS 2_1
   LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
   ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
   RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
   INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
   FRAMEWORK DESTINATION ${CMAKE_INSTALL_BINDIR}
)

