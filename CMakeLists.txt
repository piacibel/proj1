cmake_minimum_required(VERSION 2.4)


PROJECT(proj1)
set(CMAKE_CXX_STANDARD 14)
message("Project source directory set to ${PROJECT_SOURCE_DIR}")

# Include directories (hpp visible to everyone)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -O0")
message("Debug messages : ${CMAKE_CXX_FLAGS_DEBUG}")
