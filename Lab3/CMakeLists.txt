cmake_minimum_required(VERSION 3.13)
project(Meth_Opt_Lab3)

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

set(UtilsSource Utils/file_utils.h Utils/file_utils.cpp
        Utils/print_utils.h Utils/print_utils.cpp)

set(SolverSource
        Solver/solver.h
        Solver/LU_solver.cpp
        Solver/Conjugate_solver.cpp
        Solver/Gauss_solver.cpp)

set(TestGeneratorSource
        TestGenerator/matrix_generator.h
        TestGenerator/regular_matrix_generator.cpp
        TestGenerator/profile_matrix_generator.cpp
        TestGenerator/sparse_matrix_generator.cpp
        TestGenerator/generator.cpp)

set(TestRunnerSource
        TestRunner/runner.h TestRunner/runner.cpp
        TestRunner/regular_runner.cpp
        TestRunner/sparse_runner.cpp
        TestRunner/profile_runner.cpp)

set(MatrixSource Matrix/matrix.h
        Matrix/profile_matrix.h Matrix/profile_matrix.cpp
        Matrix/sparse_matrix.h Matrix/sparse_matrix.cpp
        Matrix/regular_matrix.h)


find_package(Boost "1.40.0" COMPONENTS system REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
endif ()

add_executable(Meth_Opt_Lab3 main.cpp ${TestGeneratorSource}
        ${UtilsSource}
        ${MatrixSource}
        ${SolverSource}
        ${TestRunnerSource})

target_include_directories(Meth_Opt_Lab3
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/Matrix>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/Solver>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/TestGenerator>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/TestRunner>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/Utils>)

target_link_libraries(Meth_Opt_Lab3 PUBLIC logger ${Boost_LIBRARIES})

