cmake_minimum_required(VERSION 3.19)
project(Meth_Opt_Lab4)

set(CMAKE_CXX_STANDARD 17)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(suffix -release)
else()
    set(suffix -debug)
endif ()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build${suffix}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build${suffix}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build${suffix}/bin)


configure_file(CMakeLists.txt.in Excel-Logger-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Excel-Logger-download )

if(result)
    message(FATAL_ERROR "CMake step for Excel-Logger failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Excel-Logger-download )

if(result)
    message(FATAL_ERROR "Build step for Excel-Logger failed: ${result}")
endif()

add_subdirectory(
        ${CMAKE_CURRENT_BINARY_DIR}/Excel-Logger-src
        ${CMAKE_CURRENT_BINARY_DIR}/Excel-Logger-build
)


set(Methods_Sources
        Methods/method.h
        Methods/method.cpp
        Methods/Newton.h
        Methods/Newton.cpp
        Methods/NewtonDirectionDescent.h
        Methods/NewtonDirectionDescent.cpp
        Methods/NewtonOneDimension.h
        Methods/NewtonOneDimension.cpp
        Methods/BroadenFletcherChen.h
        Methods/BroadenFletcherChen.cpp
        Methods/Powell.h
        Methods/Powell.cpp)


set(Utils_Sources Utils/point.h
        Utils/extended_function.h
        Utils/utils.h
        Utils/utils.cpp)

add_executable(Meth_Opt_Lab4 main.cpp Source.h Source.cpp ${Utils_Sources} ${Methods_Sources})


target_link_libraries(Meth_Opt_Lab4 PUBLIC logger)
