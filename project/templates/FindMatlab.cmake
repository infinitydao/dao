# - this module looks for Matlab
# Defines:
#  MATLAB_INCLUDE_DIR: include path for mex.h, engine.h
#  MATLAB_LIBRARIES:   required libraries: libmex, etc
#  MATLAB_MEX_LIBRARY: path to libmex.lib
#  MATLAB_MX_LIBRARY:  path to libmx.lib
#  MATLAB_ENG_LIBRARY: path to libeng.lib

#=============================================================================
# Copyright 2005-2009 Kitware, Inc.
#
# Distributed under the OSI-approved BSD License (the "License");
# see accompanying file Copyright.txt for details.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================
# (To distribute this file outside of CMake, substitute the full
#  License text for the above reference.)

# Typical usage could be something like:
#   find_package(Matlab 7.6 REQUIRED)

SET(MATLAB_FOUND 0)
SET(MATLAB_ROOT_FOUND 0)

IF(WIN32)
  IF(CMAKE_SIZEOF_VOID_P EQUAL 4)
	SET( MATLAB_ADD_PATH win32 )
  ELSE(CMAKE_SIZEOF_VOID_P EQUAL 4)
    SET( MATLAB_ADD_PATH win64 )
  ENDIF(CMAKE_SIZEOF_VOID_P EQUAL 4)

  IF (DEFINED Matlab_FIND_VERSION)
   GET_FILENAME_COMPONENT( MATLAB_ROOT  [HKEY_LOCAL_MACHINE\\SOFTWARE\\MathWorks\\MATLAB\\${Matlab_FIND_VERSION};MATLABROOT] ABSOLUTE)
   IF  (NOT ${MATLAB_ROOT} STREQUAL "/registry")
      SET(MATLAB_ROOT_FOUND 1)
   ENDIF  (NOT ${MATLAB_ROOT} STREQUAL "/registry")
  ELSE(DEFINED Matlab_FIND_VERSION)
    SET( LIST_PATH_ENV $ENV{Path} )
    FOREACH(CURRENT_PATH_ENV ${LIST_PATH_ENV})
      UNSET( PATH_PROGRAM_MATLAB CACHE)
      FIND_PROGRAM( PATH_PROGRAM_MATLAB matlab ${CURRENT_PATH_ENV} NO_DEFAULT_PATH )
      GET_FILENAME_COMPONENT( NAME_PROGRAM_MATLAB ${PATH_PROGRAM_MATLAB} NAME )
      STRING(REPLACE "/bin/${NAME_PROGRAM_MATLAB}" "" MATLAB_ROOT ${PATH_PROGRAM_MATLAB})
      IF( IS_DIRECTORY "${MATLAB_ROOT}/extern/lib/${MATLAB_ADD_PATH}/microsoft/" )
        SET(MATLAB_ROOT_FOUND 1)
        SET(CURRENT_MATLAB_LIB_PATH "${MATLAB_ROOT}/extern/lib/${MATLAB_ADD_PATH}/microsoft")
        BREAK()
      ENDIF( IS_DIRECTORY "${MATLAB_ROOT}/extern/lib/${MATLAB_ADD_PATH}/microsoft/" )
    ENDFOREACH(CURRENT_PATH_ENV ${LIST_PATH_ENV})
  ENDIF (DEFINED Matlab_FIND_VERSION)
  set( LIB_PREFIX lib )
ELSE( WIN32 )
  IF(CMAKE_SIZEOF_VOID_P EQUAL 4)
    # Regular x86
    SET(MATLAB_ADD_PATH glnxa32 )
  ELSE(CMAKE_SIZEOF_VOID_P EQUAL 4)
    # AMD64:
    SET(MATLAB_ADD_PATH glnxa64 )
  ENDIF(CMAKE_SIZEOF_VOID_P EQUAL 4)
  FILE(GLOB MATLAB_ROOT "/usr/local/MATLAB/*" )
  FOREACH(CURRENT_MATLAB_PATH ${MATLAB_ROOT})
    FIND_PATH( MATLAB_LIB_PATH ${MATLAB_ADD_PATH} "${MATLAB_ROOT}/bin" NO_DEFAULT_PATH )
    IF( NOT ${MATLAB_LIB_PATH} STREQUAL "MATLAB_LIB_PATH-NOTFOUND" )
      SET( CURRENT_MATLAB_LIB_PATH "${MATLAB_ROOT}/bin/${MATLAB_ADD_PATH}/" )
      SET(MATLAB_ROOT_FOUND 1)
      BREAK()
    ENDIF( NOT ${MATLAB_LIB_PATH} STREQUAL "MATLAB_LIB_PATH-NOTFOUND" )
  ENDFOREACH(CURRENT_MATLAB_PATH ${MATLAB_ROOT})
  set( LIB_PREFIX "" )
ENDIF(WIN32)

IF(NOT MATLAB_ROOT_FOUND)
  MESSAGE(FATAL_ERROR "Matlab version ${Matlab_FIND_VERSION} nod found")
	return()
ENDIF(NOT MATLAB_ROOT_FOUND)

FIND_LIBRARY(MATLAB_MEX_LIBRARY
  "${LIB_PREFIX}mex"
  "${CURRENT_MATLAB_LIB_PATH}/"
  )
FIND_LIBRARY(MATLAB_MX_LIBRARY
  "${LIB_PREFIX}mx"
  "${CURRENT_MATLAB_LIB_PATH}/"
  )
FIND_LIBRARY(MATLAB_ENG_LIBRARY
  "${LIB_PREFIX}eng"
  "${CURRENT_MATLAB_LIB_PATH}/"
  )
FIND_PATH(MATLAB_INCLUDE_DIR
  "mex.h"
  "${MATLAB_ROOT}/extern/include/"
  )

# This is common to UNIX and Win32:
SET(MATLAB_LIBRARIES
  ${MATLAB_MEX_LIBRARY}
  ${MATLAB_MX_LIBRARY}
  ${MATLAB_ENG_LIBRARY}
)

IF(MATLAB_INCLUDE_DIR AND MATLAB_LIBRARIES)
  SET(MATLAB_FOUND 1)
ENDIF(MATLAB_INCLUDE_DIR AND MATLAB_LIBRARIES)

MARK_AS_ADVANCED(
  MATLAB_LIBRARIES
  MATLAB_MEX_LIBRARY
  MATLAB_MX_LIBRARY
  MATLAB_ENG_LIBRARY
  MATLAB_INCLUDE_DIR
  MATLAB_FOUND
  MATLAB_ROOT
)

macro( rename_matlab_suffix projectname)

  if(${CMAKE_SYSTEM_NAME} STREQUAL Linux)
    IF(CMAKE_SIZEOF_VOID_P EQUAL 4)
      # Regular x86
      SET(MATLAB_POSTFIX mexglx )
    ELSE(CMAKE_SIZEOF_VOID_P EQUAL 4)
      # AMD64:
      SET(MATLAB_POSTFIX mexa64 )
    ENDIF(CMAKE_SIZEOF_VOID_P EQUAL 4)

  add_custom_command(TARGET ${projectname} POST_BUILD
      COMMAND ln -sf $<TARGET_FILE:${projectname}> ${CMAKE_BINARY_DIR}/bin/${projectname}.${MATLAB_POSTFIX}
  )
  endif(${CMAKE_SYSTEM_NAME} STREQUAL Linux)

  if(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
    IF(CMAKE_SIZEOF_VOID_P EQUAL 4)
      # Regular x86
      SET(MATLAB_POSTFIX mexw32 )
    ELSE(CMAKE_SIZEOF_VOID_P EQUAL 4)
      # AMD64:
      SET(MATLAB_POSTFIX mexw64 )
    ENDIF(CMAKE_SIZEOF_VOID_P EQUAL 4)

    add_custom_command(TARGET ${projectname} POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${projectname}> $<TARGET_FILE_DIR:${projectname}>/${projectname}.${MATLAB_POSTFIX}
  )
    set_target_properties(${projectname} PROPERTIES LINK_FLAGS "/export:mexFunction")
  endif(${CMAKE_SYSTEM_NAME} STREQUAL Windows)

endmacro( rename_matlab_suffix project_name)