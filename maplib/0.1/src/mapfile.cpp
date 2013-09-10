/*
          mapfile.cpp
Created by infinitydao@gmail.com 
            09/2013
*/

#include "mapfile.h"

//-------------------------------------------------------------------------
maplib::MapFile::MapFile( const Map& map )
:m_map(map)
{

}

//-------------------------------------------------------------------------
maplib::MapFile::MapFile( const Map& map, const QString &name )
:m_map(map),
m_file(name)
{

}

//-------------------------------------------------------------------------
maplib::MapFile::~MapFile()
{

}

//-------------------------------------------------------------------------
bool maplib::MapFile::Open()
{
  if( m_file.fileName().isEmpty() )
    return false;
  return m_file.open( QIODevice::ReadWrite );
}

//-------------------------------------------------------------------------
void maplib::MapFile::setFileName(const QString &name)
{
  m_file.setFileName( name );
}

//-------------------------------------------------------------------------
bool maplib::MapFile::Save()
{
  return false;
}

//-------------------------------------------------------------------------
bool maplib::MapFile::Load()
{
  return false;
}

//-------------------------------------------------------------------------
