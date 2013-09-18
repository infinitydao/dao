cmake_minimum_required( VERSION 2.8 )

set( PROJECT_NAME gelib )
set( PROJECT_LANGUAGES CXX C )
set( ROOT_PATH "../../" )

project( ${PROJECT_NAME} ${PROJECT_LANGUAGES} )

include_directories(
	include
	../../maplib/0.1/include
)

if( MSVC )
	include_directories(
		./win32	
)
endif( MSVC )

find_package( Qt4 REQUIRED QtCore QtGui )
include( ${QT_USE_FILE} )

set( HEADERS
	include/gelib.h
	include/imapitem.h
	include/idrawitem.h
	include/istaticitem.h
	include/idynamicitem.h
	include/emptyitem.h
	include/blockitem.h
	include/enemyitem.h
	include/homeitem.h
	include/moneyitem.h
	include/playeritem.h
	include/staticitemfactory.h
	include/dynamicitemfactory.h
)

set( SOURCES	
	src/gelib.cpp
	src/imapitem.cpp
	src/idrawitem.cpp
	src/istaticitem.cpp
	src/idynamicitem.cpp
	src/emptyitem.cpp
	src/blockitem.cpp
	src/enemyitem.cpp
	src/homeitem.cpp
	src/moneyitem.cpp
	src/playeritem.cpp
	src/staticitemfactory.cpp
	src/dynamicitemfactory.cpp
)

set( UI_SOURCES
#	resources/uis/mainwindow.ui
)

set( RESOURCES
	resources/gelib.qrc
)

set( MOC_HEADERS
#	include/mainwindow.h
)

qt4_wrap_cpp( MOC_SOURCES ${MOC_HEADERS} )
qt4_wrap_ui( UI_HEADERS ${UI_SOURCES} )
qt4_add_resources( QRC_SOURCES ${RESOURCES} )

add_library( ${PROJECT_NAME} ${HEADERS} ${SOURCES}  )
target_link_libraries( ${PROJECT_NAME} ${QT_LIBRARIES} ${QT_QTMAIN_LIBRARY} ${MOC_SOURCES} ${UI_HEADERS} ${QRC_SOURCES} maplib)


