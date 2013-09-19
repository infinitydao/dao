cmake_minimum_required( VERSION 2.8 )

set( PROJECT_NAME mushroomer )
set( PROJECT_LANGUAGES CXX C )
set( ROOT_PATH "../.." )

project( ${PROJECT_NAME} ${PROJECT_LANGUAGES} )

include_directories(
	include/
	../../maplib/0.2/include
	../../gelib/0.2/include
)

if( MSVC )
	include_directories(
		./win32	
)
endif( MSVC )

find_package( Qt4 REQUIRED QtCore QtGui )
include( ${QT_USE_FILE} )

set( HEADERS
	include/mushroomer.h
	include/mainwindow.h
	include/newgamedialog.h
)

set( SOURCES	
	src/mushroomer.cpp
	src/mainwindow.cpp
	src/newgamedialog.cpp
)

set( UI_SOURCES
	resources/mushroomer.ui
	resources/newgamedialog.ui
)

set( RESOURCES
	resources/mushroomer.qrc
)

set( MOC_HEADERS
	include/mainwindow.h
	include/newgamedialog.h
)

qt4_wrap_cpp( MOC_SOURCES ${MOC_HEADERS} )
qt4_wrap_ui( UI_HEADERS ${UI_SOURCES} )
qt4_add_resources( QRC_SOURCES ${RESOURCES} )
 
add_executable( ${PROJECT_NAME}  ${HEADERS} ${SOURCES} ${MOC_SOURCES} ${UI_HEADERS} ${QRC_SOURCES} )
target_link_libraries( ${PROJECT_NAME} ${QT_LIBRARIES} ${QT_QTMAIN_LIBRARY} maplib gelib )
