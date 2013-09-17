/*
          maplib.h
Created by infinitydao@gmail.com 
            09/2013
 General Publing License v 2.0
*/

#ifndef __MAPLIB_H__
#define __MAPLIB_H__

#ifndef MAPLIB_MIN_VERSION
  #define MAPLIB_MIN_VERSION 1
#endif

#ifndef MAPLIB_MAJ_VERSION
  #define MAPLIB_MAJ_VERSION 0
#endif

#include "mapfile.h"
#include "map.h"


//=========================================================================

namespace maplib{
  const unsigned char cMapMinimumSize = 5;//минимальный размер (квадратной) карты
}//namespace maplib

//=========================================================================

#endif //__MAP_H__
