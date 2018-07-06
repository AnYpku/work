#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(main)
#option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
#if(WITH_GEANT4_UIVIS)
#    find_package(Geant4 REQUIRED ui_all vis_all)
#else()
#    find_package(Geant4 REQUIRED)
#endif()

#include(${Geant4_USE_FILE})
# Find ROOT (required package)
find_package(ROOT REQUIRED) 
file(GLOB sources ${PROJECT_SOURCE_DIR}/*.C)
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.h)

add_executable(main main.cpp ${sources} ${headers})
target_link_libraries(main ${Geant4_LIBRARIES} ${ROOT_LIBRARIES})
set(EXAMPLEB1_SCRIPTS
runmust20092.root        
)

foreach(_script ${EXAMPLEB1_SCRIPTS})
    configure_file(
            ${PROJECT_SOURCE_DIR}/${_script}
            ${PROJECT_BINARY_DIR}/${_script}
            COPYONLY
    )
endforeach()


#---Set Link and include directories--------------------------------------------------------------
include_directories(${ROOT_INCLUDE_DIRS})
link_directories(${ROOT_LIBRARY_DIR})

#---Set Flags-------------------------------------------------------------------------------------
add_definitions(${ROOT_DEFINITIONS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ROOT_CXX_FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${ROOT_C_FLAGS}")
set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} ${ROOT_fortran_FLAGS}")

