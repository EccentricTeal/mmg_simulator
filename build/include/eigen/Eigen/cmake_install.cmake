# Install script for directory: /home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen" TYPE FILE FILES
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/Cholesky"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/CholmodSupport"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/Core"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/Dense"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/Eigen"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/Eigenvalues"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/Geometry"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/Householder"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/IterativeLinearSolvers"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/Jacobi"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/LU"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/MetisSupport"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/OrderingMethods"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/PaStiXSupport"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/PardisoSupport"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/QR"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/QtAlignedMalloc"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/SPQRSupport"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/SVD"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/Sparse"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/SparseCholesky"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/SparseCore"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/SparseLU"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/SparseQR"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/StdDeque"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/StdList"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/StdVector"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/SuperLUSupport"
    "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/UmfPackSupport"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen" TYPE DIRECTORY FILES "/home/suisei/projects/research/mmg_simulator/mmg_simulator/include/eigen/Eigen/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

