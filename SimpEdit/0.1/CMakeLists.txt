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

add_executable( ${PROJECT_NAME} ${HEADERS} ${SOURCES} )
target_link_libraries( ${PROJECT_NAME} ${QT_LIBRARIES} ${QT_QTMAIN_LIBRARY} )
