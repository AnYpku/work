# Configuration for the D0 Lifetime exercise

include_directories(${CMAKE_CURRENT_SOURCE_DIR} "${PROJECT_SOURCE_DIR}/src/D0_Lifetime" "${PROJECT_SOURCE_DIR}/src/Display")

# ---- Get resources ----
set(NB_DATA_FILES 32 CACHE STRING "Number of data files to download")
set(maxnum 0)
MATH(EXPR maxnum "${NB_DATA_FILES} + 1" )
SET(number 1 )
WHILE( number GREATER 0 AND number LESS ${maxnum})
   GetMasterclassResource("mclasseventv2_D0_${number}.root")
  MATH( EXPR number "${number} + 1" ) # increment number
ENDWHILE( number GREATER 0 AND number LESS ${maxnum} )

# ---- Now updating the source file with the actual number downloaded
# Should be fixed with opendir, readdir etc...
# Extra quick hack for the moment
configure_file(launcher.cpp.template launcher.cpp)

# Prepare ROOT dictionary
add_custom_command(OUTPUT Dict.h Dict.C
                   COMMAND ${ROOT_rootcint_CMD}
                           -f ${CMAKE_CURRENT_BINARY_DIR}/Dict.C -c
                           LHCb_D0_Exercise.h LinkDef.h
                   DEPENDS LHCb_D0_Exercise.h LinkDef.h
                   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_command(OUTPUT LaunchDict.h LaunchDict.C
                   COMMAND ${ROOT_rootcint_CMD}
                           -f ${CMAKE_CURRENT_BINARY_DIR}/LaunchDict.C -c
                           launcher.h LHCb_D0_Exercise.h LbMclassTrack.h Frame.h LauncherLinkDef.h 
                   DEPENDS  launcher.h LauncherLinkDef.h LHCb_D0_Exercise.h Frame.h LbMclassTrack.h
                   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Build executable
#add_executable(LHCb_D0_Exercise LHCb_D0_Exercise.C Dict.C LHCb_D0_ExerciseMain.C)
#target_link_libraries(LHCb_D0_Exercise ${ROOT_LIBRARIES})

add_executable(LHCb_launcher LHCb_launcher.C launcher.cpp LaunchDict.C  LHCb_D0_Exercise.C Frame.cpp LbMclassTrack.cpp)
target_link_libraries(LHCb_launcher ${ROOT_LIBRARIES})

# Install
#install(TARGETS LHCb_D0_Exercise DESTINATION bin)
install(TARGETS LHCb_launcher DESTINATION bin)

#set(LHCb_D0_Exercise_name "D0 Lifetime")

# Add the exercise to the list of built exercises
#set_property(GLOBAL APPEND PROPERTY exercises LHCb_D0_Exercise)
set_property(GLOBAL APPEND PROPERTY exercises LHCb_launcher)

