cmake_minimum_required(VERSION 3.16)

set(PROJECT "BattleSnake")

project("${PROJECT}_Project" VERSION 0.0.1 LANGUAGES CXX)

# Global CMake variables are set here
set(CMAKE_CXX_STANDARD              17)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS   ON)

# options for generating/building (user inputs)
option(ENABLE_WARNINGS      "Enable to add warnings to a target."   ON)
option(ENABLE_TESTING       "Enable a Unit Testing build."          ON)
option(ENABLE_COVERAGE      "Enable a Code Coverage build."         OFF)
option(ENABLE_LTO           "Enable Link Time Optimization (LTO)."  OFF)
option(ENABLE_CCACHE        "Enable the usage of Ccache."           OFF)

# Cmake modules
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)

include(ConfigSafeGuards)
include(Warnings)

if (ENABLE_TESTING OR ENABLE_COVERAGE)
    include(CTest)
endif()
if (ENABLE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        include(CodeCoverage)
    else()
        message("Coverage only for GNU|Clang")
        set(ENABLE_COVERAGE OFF)
    endif()
endif()

if (ENABLE_LTO)
    include(LTO)
    find_lto(CXX)
endif()

if (ENABLE_CCACHE)
    include(Ccache)
endif()


# Project and lib names
set(LIBRARY_NAME    ${PROJECT}_Lib)
set(EXECUTABLE_NAME ${PROJECT}_Executable)
set(TEST_MAIN       ${PROJECT}_unit_tests)
set(COVERAGE_MAIN   ${PROJECT}_coverage)

# Cmake modules
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)
# include(Documentation)
if (ENABLE_TESTING)
    include(CTest)
endif()

# Add conan libraries
include(${PROJECT_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()

# Add external libraries
find_package(Git QUIET)

if(GIT_FOUND)
    message(STATUS "Submodule update")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE GIT_SUBMOD_RESULT)
endif()

add_subdirectory(${PROJECT_SOURCE_DIR}/external)

# Add first-party libraries
add_subdirectory(${PROJECT_SOURCE_DIR}/src)

# Add executables
add_subdirectory(${PROJECT_SOURCE_DIR}/app)

# Add unit tests
if (ENABLE_TESTING OR ENABLE_COVERAGE)
    enable_testing()
    add_subdirectory(${PROJECT_SOURCE_DIR}/tests)
endif()

