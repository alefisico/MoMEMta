# Install script for directory: /mnt/t3nfs01/data01/shome/algomez/work/ttH/CMSSW_9_4_9/src/MoMEMta/Tutorials

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
    set(CMAKE_INSTALL_CONFIG_NAME "")
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
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/mnt/t3nfs01/data01/shome/algomez/work/ttH/CMSSW_9_4_9/src/MoMEMta/Tutorials/build/TTbar_FullyLeptonic/cmake_install.cmake")
  include("/mnt/t3nfs01/data01/shome/algomez/work/ttH/CMSSW_9_4_9/src/MoMEMta/Tutorials/build/WW_FullyLeptonic/cmake_install.cmake")
  include("/mnt/t3nfs01/data01/shome/algomez/work/ttH/CMSSW_9_4_9/src/MoMEMta/Tutorials/build/ttbb_FullyLeptonic/cmake_install.cmake")
  include("/mnt/t3nfs01/data01/shome/algomez/work/ttH/CMSSW_9_4_9/src/MoMEMta/Tutorials/build/ttH_FullyLeptonic/cmake_install.cmake")
  include("/mnt/t3nfs01/data01/shome/algomez/work/ttH/CMSSW_9_4_9/src/MoMEMta/Tutorials/build/mem_dileptonic/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/mnt/t3nfs01/data01/shome/algomez/work/ttH/CMSSW_9_4_9/src/MoMEMta/Tutorials/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")