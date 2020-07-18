# Cmake Version
cmake_minimum_required(VERSION 3.1)

# Variables
set(PROJ_NAME mmg_simulator)
set(INCLUDE_DIR include)
set(PROJ_SRC src)


project(${PROJ_NAME} CXX)
include_directories(${PROJ_SRC}/../${INCLUDE_DIR})
add_subdirectory(${INCLUDE_DIR}/eigen/)


add_library(mmg_models STATIC src/mmg_models.cpp)


add_executable(simulator ${PROJ_SRC}/simulator.cpp)
target_link_libraries(simulator mmg_models)
