# Configuration for the Event Display

include_directories(${CMAKE_CURRENT_SOURCE_DIR} "${PROJECT_SOURCE_DIR}/src/D0_Lifetime")

# ---- Get resources ----
SET( number 1 )
WHILE( number GREATER 0 AND number LESS 33 )
   GetMasterclassResource("mclasseventv2_D0_${number}.root")
  MATH( EXPR number "${number} + 1" ) # increment number
ENDWHILE( number GREATER 0 AND number LESS 33 )

# Prepare ROOT dictionary
add_custom_command(OUTPUT Dict.h Dict.cxx
                   COMMAND ${ROOT_rootcint_CMD} -v4 
		   -f ${CMAKE_CURRENT_BINARY_DIR}/Dict.cxx -c
                           LbMclassTrack.h Frame.h LinkDef.h
                   DEPENDS LbMclassTrack.h Frame.h LinkDef.h
		   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_command(OUTPUT LibDict.h LibDict.cpp
                   COMMAND ${ROOT_rootcint_CMD} -v4 
		   -f ${CMAKE_CURRENT_BINARY_DIR}/LibDict.cpp -c
                           LbMclassTrack.h LibLinkDef.h
                   DEPENDS LbMclassTrack.h LibLinkDef.h
		   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_library(LbMclass SHARED LbMclassTrack.cpp LibDict.cpp)
target_link_libraries(LbMclass ${ROOT_LIBRARIES})

add_executable(LHCb_Display LHCbMasterclassDisplay.cpp
               LbMclassTrack.cpp Dict.cxx
               Frame.cpp)
target_link_libraries(LHCb_Display ${ROOT_LIBRARIES})

add_library(LHCb_DisplayLib LHCbMasterclassDisplay.cpp
               LbMclassTrack.cpp Dict.cxx
               Frame.cpp)
target_link_libraries(LHCb_DisplayLib ${ROOT_LIBRARIES})


# Install
install(TARGETS LHCb_Display DESTINATION bin)
install(TARGETS LHCb_DisplayLib DESTINATION lib)

set(LHCb_Display "Display")

# Add the exercise to the list of built exercises
set_property(GLOBAL APPEND PROPERTY exercises LHCb_Display)
