/*
          map.cpp
Created by infinitydao@gmail.com 
            09/2013
 General Publing License v 2.0
*/

#include <stdexcept>
#include "maplib.h"
#include "map.h"

std::auto_ptr<maplib::CMap> maplib::Map::_inst( new maplib::CMap );

#ifndef DEFAULT_CELL_SIZE
  #define DEFAULT_CELL_SIZE 20
#endif

//-------------------------------------------------------------------------
maplib::CMap::CMap()
:m_cellSize(DEFAULT_CELL_SIZE),
m_width(0),
m_height(0)
{

}

//-------------------------------------------------------------------------
maplib::CMap::~CMap()
{

}

//-------------------------------------------------------------------------
void maplib::CMap::reset( int n, int m )
{
    m_map.clear();

    if( n < maplib::cMapMinimumSize || m < maplib::cMapMinimumSize )
      throw std::runtime_error( "Map size cant be less cMapMinimumSize" );
  
    for( unsigned int i = 0; i < n; i++ ){
      QVector<RegionItem> vec;
      for( unsigned int j = 0; j < m; j++ ){
        RegionItem Item(RegionItem::Block);
        vec.push_back( Item );
      }
      m_map.push_back( vec );
    }
}

//-------------------------------------------------------------------------
void maplib::CMap::setSize( float width, float height )
{
  m_width = width;
  m_height = height;
}

//-------------------------------------------------------------------------
float maplib::CMap::width()const
{
  return m_width;
}

//-------------------------------------------------------------------------
float maplib::CMap::height()const
{
  return m_height;
}

//-------------------------------------------------------------------------
void maplib::CMap::setFileName( const QString& name )
{
  m_fileName = name;
}

//-------------------------------------------------------------------------
QString maplib::CMap::fileName()const
{
  return m_fileName;
}

//-------------------------------------------------------------------------
int maplib::CMap::cellSize()const
{
  return m_cellSize;
}

//-------------------------------------------------------------------------
