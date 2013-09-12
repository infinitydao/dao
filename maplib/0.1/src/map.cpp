/*
          map.cpp
Created by infinitydao@gmail.com 
            09/2013
 General Publing License v 2.0
*/

#include <stdexcept>
#include "maplib.h"
#include "map.h"

//-------------------------------------------------------------------------
maplib::Map::Map()
{

}

//-------------------------------------------------------------------------
maplib::Map::Map(const unsigned char m, const unsigned char n)
{
  reset( m, n );
}

//-------------------------------------------------------------------------
maplib::Map::~Map()
{
  m_map.clear();
}

//-------------------------------------------------------------------------
void maplib::Map::clear()
{
  m_map.clear();
}

//-------------------------------------------------------------------------
bool maplib::Map::isEmpty() const
{
  return m_map.isEmpty();
}

//-------------------------------------------------------------------------
int maplib::Map::m() const
{
  return m_map.size();
}

//-------------------------------------------------------------------------
int maplib::Map::n() const
{
  if( m() > 0 )
    return m_map[0].size();
  else
    return 0;
}

//-------------------------------------------------------------------------
void maplib::Map::reset(const unsigned char m, const unsigned char n)
{
    clear();

    if( m < maplib::cMapMinimumSize || n < maplib::cMapMinimumSize )
      throw std::runtime_error( "Map size cant be less cMapMinimumSize" );
  
    for( unsigned int i = 0; i < m; i++ ){
      QVector<QSharedPointer< RegionItem >> vec;
      for( unsigned int j = 0; j < n; j++ ){
        QSharedPointer<RegionItem> Item = QSharedPointer<RegionItem>( new RegionItem(RegionItem::Block) );
        vec.push_back( Item );
      }
      m_map.push_back( vec );
    }
}

//-------------------------------------------------------------------------
