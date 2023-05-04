
add_subdirectory(App)
if(BUILD_GUI)
    add_subdirectory(Gui)
endif(BUILD_GUI)

set(ZzmDesign_Scripts
    Init.py
)

if(BUILD_GUI)
    list (APPEND ZzmDesign_Scripts InitGui.py)
endif(BUILD_GUI)

add_custom_target(ZzmDesignScripts ALL
    SOURCES ${ZzmDesign_Scripts}
)

fc_target_copy_resource_flat(ZzmDesignScripts
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}/Mod/ZzmDesign
    ${ZzmDesign_Scripts}
)

install(
    FILES
        ${ZzmDesign_Scripts}
    DESTINATION
        Mod/ZzmDesign
)
