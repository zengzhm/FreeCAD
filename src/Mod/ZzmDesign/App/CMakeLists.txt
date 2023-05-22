
include_directories(
    ${Boost_INCLUDE_DIRS}
    ${OCC_INCLUDE_DIR}
    ${PYTHON_INCLUDE_DIRS}
    ${ZLIB_INCLUDE_DIR}
    ${XercesC_INCLUDE_DIRS}
)

link_directories(${OCC_LIBRARY_DIR})

set(ZzmDesign_LIBS
	Part
    FreeCADApp
)

SET(ZzmDesign_SRCS
    AppZzmDesign.cpp
    PreCompiled.cpp
    PreCompiled.h
)

add_library(ZzmDesign SHARED ${ZzmDesign_SRCS})
target_link_libraries(ZzmDesign ${ZzmDesign_LIBS})


SET_BIN_DIR(ZzmDesign ZzmDesign /Mod/ZzmDesign)
SET_PYTHON_PREFIX_SUFFIX(ZzmDesign)

install(TARGETS ZzmDesign DESTINATION ${CMAKE_INSTALL_LIBDIR})
