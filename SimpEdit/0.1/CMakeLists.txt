cmake_minimum_required( VERSION 2.8 )

set( PROJECT_NAME SimpEdit )
set( PROJECT_LANGUAGES CXX C )
set( ROOT_PATH "." )

project( ${PROJECT_NAME} ${PROJECT_LANGUAGES} )
include_directories(
	include/ 
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
)

set( SOURCES	
	src/main.cpp
)

set( UI_SOURCES
	resources/uis/mainwindow.ui
)

set( RESOURCES
	resources/simpedit.qrc
)

set( MOC_HEADERS
	include/mainwindow.h
)

qt4_wrap_cpp( MOC_SOURCES ${MOC_HEADERS} )
qt4_wrap_ui( UI_HEADERS ${UI_SOURCES} )
qt4_add_resources( QRC_SOURCES ${RESOURCES} )

add_executable( ${PROJECT_NAME} ${HEADERS} ${SOURCES} ${MOC_SOURCES} ${UI_HEADERS} ${QRC_SOURCES} )
target_link_libraries( ${PROJECT_NAME} ${QT_LIBRARIES} ${QT_QTMAIN_LIBRARY} )
