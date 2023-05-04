
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
    ${Boost_INCLUDE_DIRS}
    ${COIN3D_INCLUDE_DIRS}
    ${ZLIB_INCLUDE_DIR}
    ${PYTHON_INCLUDE_DIRS}
    ${XercesC_INCLUDE_DIRS}
)

set(ZzmDesignGui_LIBS
    ZzmDesign
    FreeCADGui
)

if (BUILD_QT5)
    qt5_add_resources(ZzmDesign_QRC_SRCS Resources/ZzmDesign.qrc)
else()
    qt4_add_resources(ZzmDesign_QRC_SRCS Resources/ZzmDesign.qrc)
endif()

SET(ZzmDesignGui_SRCS
    ${ZzmDesign_QRC_SRCS}
    AppZzmDesignGui.cpp
    Command.cpp
    PreCompiled.cpp
    PreCompiled.h
    Workbench.cpp
    Workbench.h
)

add_library(ZzmDesignGui SHARED ${ZzmDesignGui_SRCS})
target_link_libraries(ZzmDesignGui ${ZzmDesignGui_LIBS})

SET_BIN_DIR(ZzmDesignGui ZzmDesignGui /Mod/ZzmDesign)
SET_PYTHON_PREFIX_SUFFIX(ZzmDesignGui)
    
install(TARGETS ZzmDesignGui DESTINATION ${CMAKE_INSTALL_LIBDIR})
