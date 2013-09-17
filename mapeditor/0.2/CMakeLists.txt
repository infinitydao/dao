cmake_minimum_required( VERSION 2.8 )

set( PROJECT_NAME maplibgui_test )
set( PROJECT_LANGUAGES CXX C )
set( ROOT_PATH "../" )

project( ${PROJECT_NAME} ${PROJECT_LANGUAGES} )

include_directories(
	include/
	../maplib/0.1/include
)

if( MSVC )
	include_directories(
		./win32	
)
endif( MSVC )

find_package( Qt4 REQUIRED QtCore QtGui )
include( ${QT_USE_FILE} )

set( HEADERS
	include/mainwindow.h
	include/newmapdialog.h
	include/mapgraphicsview.h
)

set( SOURCES	
	src/main.cpp
	src/mainwindow.cpp
	src/newmapdialog.cpp
	src/mapgraphicsview.cpp
)

set( UI_SOURCES
	resources/mainwindow.ui
	resources/newdialog.ui
	#resources/opendialog.ui
)

set( RESOURCES
	resources/maplibgui_test.qrc
)

set( MOC_HEADERS
	include/mainwindow.h
	include/newmapdialog.h
	include/mapgraphicsview.h
)

qt4_wrap_cpp( MOC_SOURCES ${MOC_HEADERS} )
qt4_wrap_ui( UI_HEADERS ${UI_SOURCES} )
qt4_add_resources( QRC_SOURCES ${RESOURCES} )
 
add_executable( ${PROJECT_NAME}  ${HEADERS} ${SOURCES} ${MOC_SOURCES} ${UI_HEADERS} ${QRC_SOURCES} )
target_link_libraries( ${PROJECT_NAME} ${QT_LIBRARIES} ${QT_QTMAIN_LIBRARY} maplib)

set( DEPENDS_MODULE
	maplib
)

