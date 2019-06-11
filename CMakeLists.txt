cmake_minimum_required(VERSION 3.14)
project(pcg_test)

set(CMAKE_CXX_STANDARD 17)

#find_package(pcg REQUIRED)

#find_package(ms-gsl REQUIRED)

add_executable(pcg_test ${PROJECT_SOURCE_DIR}/main.cpp)

find_path(PCG_INCLUDE_DIR pcg_random.hpp
          PATHS ${_VCPKG_ROOT_DIR}/installed/${VCPKG_TARGET_TRIPLET}/include
          NO_DEFAULT_PATH)

add_library(pcg::pcg INTERFACE IMPORTED)
set_target_properties(pcg::pcg
                      PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
                                 "${PCG_INCLUDE_DIR}"
                                 INTERFACE_COMPILE_DEFINITIONS
                                 "PCG_LITTLE_ENDIAN=1")

target_link_libraries(pcg_test PRIVATE pcg::pcg)
