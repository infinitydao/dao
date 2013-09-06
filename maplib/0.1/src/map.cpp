/*
          map.cpp
Created by infinitydao@gmail.com 
            09/2013
*/

#include <stdexcept>
#include "maplib.h"
#include "map.h"


//-------------------------------------------------------------------------
maplib::Map::Map(const unsigned char m, const unsigned char n)
{
  if( m < maplib::cMapMinimumSize || n < maplib::cMapMinimumSize )
    throw std::runtime_error( "Map size cant be less cMapMinimumSize" );

  for( unsigned int i = 0; i < n; i++ ){
    QVector<QSharedPointer< RegionItem >> vec;
    for( unsigned int j = 0; j < n; j++ ){
      QSharedPointer<RegionItem> Item = QSharedPointer<RegionItem>( new RegionItem(RegionItem::Block) );
      vec.push_back( Item );
    }
    m_map.push_back( vec );
  }
}

//-------------------------------------------------------------------------
maplib::Map::~Map()
{
  m_map.clear();
}

//-------------------------------------------------------------------------
