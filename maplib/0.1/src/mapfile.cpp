/*
          mapfile.cpp
Created by infinitydao@gmail.com 
            09/2013
   General Publing License v 2.0
*/

#include "maplib.h"
#include "mapfile.h"

//-------------------------------------------------------------------------
maplib::MapFile::MapFile()
{

}

//-------------------------------------------------------------------------
maplib::MapFile::~MapFile()
{

}

//-------------------------------------------------------------------------
bool maplib::MapFile::save( CMap& map )
{
  if( map.fileName().isEmpty() )
    return false;

  m_file.setFileName( map.fileName() );

  if( !m_file.open( QIODevice::ReadWrite|QIODevice::Truncate ) )
    return false;

  m_file.write( (char*)&map.m_header, sizeof(map.m_header) );

  for( int i = 0; i < map.width(); i++ ){
    for( int j = 0; j < map.height(); j++ ){
      m_file.write( (char*)(&map.m_map[i][j]), sizeof(MAPITEM) );
    }
  }

  m_file.close();

  return true;
}

//-------------------------------------------------------------------------
bool maplib::MapFile::load( CMap& map )
{
  if( map.fileName().isEmpty() )
    return false;

  m_file.setFileName( map.fileName() );

  if( !m_file.open( QIODevice::ReadWrite|QIODevice::Truncate ) )
    return false;

  m_file.read( (char*)(&map.m_header), sizeof(map.m_header) );

  if( !map.checkMagick( &map.m_header, sizeof(map.m_header), MAPLIB_MIN_VERSION, MAPLIB_MAJ_VERSION) )
    return false;

  map.reset( map.width(), map.height() );

  for( int i = 0; i < map.width(); i++ ){
    for( int j = 0; j < map.height(); j++ ){
      MAPITEM item;
      memset( &item, 0, sizeof(item) );
      m_file.read( (char*)(&item), sizeof(item) );
      map.m_map[i][j] = item;
    }
  }

  m_file.close();

  return true;
}

//-------------------------------------------------------------------------
