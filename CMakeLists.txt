cmake_minimum_required(VERSION 3.4)
project(PyBindMersenneTwister
        VERSION 1.0
        LANGUAGES C CXX
        DESCRIPTION "Build a Python module for Mersenne Twister with pybind11")

# Download pybind11 if needed
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
  # Update submodules as needed
  option(GIT_SUBMODULE "Check submodules during build" ON)
  if(GIT_SUBMODULE)
    message(STATUS "Submodule update")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                    RESULT_VARIABLE GIT_SUBMOD_RESULT)
    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
      message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
    endif()
  endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/pybind11/CMakeLists.txt")
  message(FATAL_ERROR "Failed to download pybind11! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

# Add external libraries: Mersenne Twister and pybind11
add_subdirectory(extern/mt)
add_subdirectory(extern/pybind11)

# Build the Python module
pybind11_add_module(pymt src/pymt19937ar.cpp)
target_link_libraries(pymt PRIVATE mt19937ar)
