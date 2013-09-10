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
  m_file.close();

  if( !m_file.open( QIODevice::ReadWrite | QIODevice::Truncate ) )
    return false;

  saveFileHeader();
  saveFileData();

  m_file.close();

  return Open();
}

//-------------------------------------------------------------------------
bool maplib::MapFile::Load()
{
  int M = 0, N = 0;

  loadFileHeader( &M, &N );
  loadFileData( M, N );

  return true;
}

//-------------------------------------------------------------------------
void maplib::MapFile::saveFileHeader()
{
  if( m_map.isEmpty() )
    return;

  const int cM = m_map.m();
  const int cN = m_map.n();

  m_file.write( (char*)(&cM), sizeof(cM) );
  m_file.write( (char*)(&cN), sizeof(cN) );
}

//-------------------------------------------------------------------------
void maplib::MapFile::saveFileData()
{
  for( int i = 0; i < m_map.m(); i++ ){
    for( int j = 0; j < m_map.n(); j++ ){
      m_file.write( (char*)(&m_map.m_map[i][j]), sizeof(maplib::RegionItem::RegionItemType) );
    }
  }
}

//-------------------------------------------------------------------------
void maplib::MapFile::loadFileHeader(int *m, int *n)
{
  if( !m || !n )
    return;

  m_file.read( (char*)m, sizeof(int) );
  m_file.read( (char*)n, sizeof(int) );
}

//-------------------------------------------------------------------------
void maplib::MapFile::loadFileData( int m, int n )
{
  if( m <= 0 || n <= 0 )
    return;

  Map *ptrMap = const_cast<Map*>(&m_map);

  ptrMap->reset( m, n );

  for( int i = 0; i < m; i++ ){
    for( int j = 0; j < n; j++ ){
      m_file.read( (char*)(ptrMap->m_map)[i][j].data(), sizeof(maplib::RegionItem::RegionItemType) );
    }
  }
}

//-------------------------------------------------------------------------
