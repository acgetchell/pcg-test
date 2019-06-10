cmake_minimum_required(VERSION 3.14)
project(pcg_test)

set(CMAKE_CXX_STANDARD 17)

find_package(pcg REQUIRED)

find_package(ms-gsl REQUIRED)

add_executable(pcg_test ${PROJECT_SOURCE_DIR}/main.cpp)
target_link_libraries(pcg_test PRIVATE pcg::pcg ms-gsl::gsl)
