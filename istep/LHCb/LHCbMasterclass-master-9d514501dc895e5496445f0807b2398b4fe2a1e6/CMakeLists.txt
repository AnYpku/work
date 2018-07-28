# (C) Copyright 2013  CERN
#
# This software is distributed under the terms of the GNU General Public
# License version 3 (GPL Version 3), copied verbatim in the file "COPYING".
#
# In applying this license, CERN does not waive the privileges and immunities
# granted to it by virtue of its status as an Intergovernmental Organization
# or submit itself to any jurisdiction.

cmake_minimum_required(VERSION 2.6.4)

if(CMAKE_VERSION VERSION_GREATER 2.8.3)
  cmake_policy(VERSION 2.8.4)
endif()

project(LHCbMasterclass)

# ---- Options ----
if(WIN32)
    option(BUILD_NSIS_INSTALLER "Produce a native Windows installer using NSIS" ON)
    option(ALLOW_PRIVATE_ROOT "Allow usage of an embedded copy of ROOT" ON)
endif()


# ---- Load macros ----
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
include(GetMasterclassResourceMacro)

# ---- Get resources ----
GetMasterclassResource(MasterclassData.root)
if(NOT CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  # copy the LHCb logo to the build directory (for testing)
  #file(COPY share/LHCbMasterclass/lhcb-logo.png
  #     DESTINATION share/LHCbMasterclass)
  configure_file(share/LHCbMasterclass/lhcb-logo.png share/LHCbMasterclass COPYONLY)
endif()

#file(COPY data/lhcbfull.root 
#    DESTINATION share/LHCbMasterclass)
configure_file(data/lhcbfull.root share/LHCbMasterclass COPYONLY)


# ---- Check for ROOT ----
if(ALLOW_PRIVATE_ROOT)
    # try to find ROOT
    find_package(ROOT COMPONENTS Eve Core Gui Graf Hist Ged Gpad RIO )
    if(NOT ROOT_FOUND)
        # we can download it if we are on Windows
        message(STATUS "Using a private copy of ROOT")
        include(GetROOTBinaries)
        set(EMBEDDED_ROOT ON)
    endif()
endif()

# now we must have ROOT
find_package(ROOT REQUIRED Table Eve EG TreePlayer Geom Ged RGL Gui Core
RIO Net Hist Graf Graf3d Gpad Tree Rint Postscript Matrix Physics
MathCore Thread)

# ---- Configuration ----
include_directories(${ROOT_INCLUDE_DIRS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# set the macro pointing to the data directory
if(NOT WIN32)
  set(DATA_DIR ${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME})
  add_definitions(-DDATA_DIR="${DATA_DIR}")
endif()

add_subdirectory(src/D0_Lifetime)
#add_subdirectory(src/Display)

get_property(exercises GLOBAL PROPERTY exercises)

# ---- Utilities ----
if(UNIX)
    # Create symlinks to be able to run from the build directory
    set(exercises_shortcuts)
    foreach(ex ${exercises})
        add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/${ex}
                           COMMAND ${CMAKE_COMMAND} -E
                               create_symlink bin/${ex}
                                              ${CMAKE_BINARY_DIR}/${ex}
                           DEPENDS ${ex}
                           COMMENT "Create symlink to ${ex}")
        list(APPEND exercises_shortcuts ${CMAKE_BINARY_DIR}/${ex})
    endforeach()
    if(exercises_shortcuts)
        add_custom_target(symlinks ALL DEPENDS ${exercises_shortcuts})
    endif()
elseif(WIN32)
    # Create batch wrappers to be able to run from the build directory
    # (they are also used for installation)
    foreach(ex ${exercises})
        configure_file("templates/exercise_wrapper.bat.in"
                       "${CMAKE_BINARY_DIR}/${ex}.bat"
                       NEWLINE_STYLE WIN32)
    endforeach()
endif()

# ---- Installation ----
install(DIRECTORY
            share/${CMAKE_PROJECT_NAME}
            ${CMAKE_BINARY_DIR}/share/${CMAKE_PROJECT_NAME}
        DESTINATION share)

if(EMBEDDED_ROOT)
  install(DIRECTORY
          ${CMAKE_BINARY_DIR}/contrib/root
          DESTINATION contrib)
endif()

# ---- Packaging ----
#set(generators ZIP)
set(generators)

set(CPACK_PACKAGE_VERSION 1.0.0)

set(CPACK_PACKAGE_VENDOR "CERN/LHCb")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_CONTACT "Marco Clemencic <marco.clemencic@cern.ch>")

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY
    "Masterclass exercises of the LHCb experiment.")

# Windows-specific
if(WIN32)
    if(BUILD_NSIS_INSTALLER)
        set(generators NSIS ${generators})
        #set(CPACK_PACKAGE_ICON "${CMAKE_SOURCE_DIR}/share/LHCbMasterclass/lhcb-logo.png")
    endif()

    # Prepare batch wrappers
    foreach(ex ${exercises})
        install(FILES "${CMAKE_BINARY_DIR}/${ex}.bat" DESTINATION .)

        if(NOT ${ex}_name)
            set(${ex}_name "${ex}")
        endif()
        if(BUILD_NSIS_INSTALLER)
            set(CPACK_NSIS_MENU_LINKS "${ex}.bat" "${${ex}_name}")
        endif()
    endforeach()

    # install VisualC++ runtime
    include(InstallRequiredSystemLibraries)
endif()

# Linux-specific
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  set(generators RPM ${generators})

  # --- RPM settings
  set(CPACK_RPM_PACKAGE_LICENSE GPLv3)
  # I would prefer "education" or "science"... but that's what I found in
  #   /usr/share/doc/rpm-4.8.0/GROUPS
  # on SLC6
  set(CPACK_RPM_PACKAGE_GROUP Applications/Engineering)
endif()

# Enable packaging
if(generators)
  set(CPACK_GENERATOR ${generators})
  include(CPack)
endif()
