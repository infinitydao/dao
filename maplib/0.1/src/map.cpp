/*
          map.cpp
Created by infinitydao@gmail.com 
            09/2013
 General Publing License v 2.0
*/

#include <stdexcept>
#include "maplib.h"
#include "map.h"
#include "mapfile.h"

std::auto_ptr<maplib::CMap> maplib::Map::_inst( new maplib::CMap );

#ifndef DEFAULT_CELL_SIZE
  #define DEFAULT_CELL_SIZE 20
#endif

//-------------------------------------------------------------------------
maplib::CMap::CMap()
{
  memset( &m_header, 0, sizeof(m_header) );
}

//-------------------------------------------------------------------------
maplib::CMap::~CMap()
{

}

//-------------------------------------------------------------------------
void maplib::CMap::reset( int Width, int Height )
{

}

//-------------------------------------------------------------------------
void maplib::CMap::setSize( int Width, int Height )
{

}

//-------------------------------------------------------------------------
int maplib::CMap::width()const
{
  return -1;
}

//-------------------------------------------------------------------------
int maplib::CMap::height()const
{
  return -1;
}

//-------------------------------------------------------------------------
void maplib::CMap::setFileName( const QString& name )
{

}

//-------------------------------------------------------------------------
QString maplib::CMap::fileName()const
{
  return "Fake";
}

//-------------------------------------------------------------------------
int maplib::CMap::cellSize()const
{
  return -1;
}

//-------------------------------------------------------------------------
bool maplib::CMap::loadMap()
{
  return false;
}

//-------------------------------------------------------------------------
bool maplib::CMap::saveMap()
{
  return false;
}

//-------------------------------------------------------------------------
