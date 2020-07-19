# Cmake Version
cmake_minimum_required(VERSION 3.1)

# Variables
set(PROJ_NAME mmg_simulator)
set(INCLUDE_DIR include)
set(PROJ_SRC src)


project(${PROJ_NAME} CXX)
include_directories(${PROJ_SRC}/../${INCLUDE_DIR})
add_subdirectory(${INCLUDE_DIR}/eigen/)


add_library(mmg_parameter STATIC src/mmg_parameter.cpp)

add_library(mmg_models STATIC src/mmg_models.cpp)
target_link_libraries(mmg_models INTERFACE mmg_parameter)

add_executable(simulator ${PROJ_SRC}/simulator.cpp)
target_link_libraries(simulator mmg_models)


target_compile_features(simulator PUBLIC cxx_std_17)
