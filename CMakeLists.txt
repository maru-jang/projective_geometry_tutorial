cmake_minimum_required(VERSION 3.22)
project(projective_geometry_tutorial)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Eigen3 REQUIRED HINTS ${CMAKE_SOURCE_DIR}/thirdparty/Eigen3/install/share/eigen3/cmake)

if (Eigen3_FOUND)
    message(STATUS "Eigen3 Found! - ${Eigen3_DIR}")
endif()

find_package(Pangolin REQUIRED HINTS ${CMAKE_SOURCE_DIR}/thirdparty/Pangolin/install/lib/cmake/Pangolin)

if (Pangolin_FOUND)
    message(STATUS "Pangolin Found! - ${Pangolin_DIR}")
endif()

include_directories(
        ${Eigen3_INCLUDE_DIRS}
        ${Pangolin_INCLUDE_DIRS}
        )

link_libraries(
        ${EIGEN3_LIBS}
        ${Pangolin_LIBRARIES}
        )

add_executable(projective_geometry_tutorial examples/example.cpp)
add_executable(plot_trajectory examples/plotTrajectory.cpp)
