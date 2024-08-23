cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(RayTracingInOneWeek)

add_executable(CreatePPM src/create_ppm_image.cpp)
add_executable(FirstRay src/first_raytraced_image.cpp)