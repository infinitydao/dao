/*
          mapfile.cpp
Created by infinitydao@gmail.com 
            09/2013
   General Publing License v 2.0
*/

#include "mapfile.h"

//-------------------------------------------------------------------------
maplib::MapFile::MapFile( )
{

}

//-------------------------------------------------------------------------
maplib::MapFile::MapFile( const QString &name )
:m_file(name)
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
  if( Map::instance()->m_map.empty() )
    return;

  const int cN = Map::instance()->width();
  const int cM = Map::instance()->height();

  m_file.write( (char*)(&cN), sizeof(cN) );
  m_file.write( (char*)(&cM), sizeof(cM) );
}

//-------------------------------------------------------------------------
void maplib::MapFile::saveFileData()
{
  m_file.seek( 2*sizeof(int) );
  for( int i = 0; i < Map::instance()->width(); i++ ){
    for( int j = 0; j < Map::instance()->height(); j++ ){
      RegionItem::RegionItemType itemType = Map::instance()->m_map[i][j].type();
      m_file.write( (char*)&itemType, sizeof(RegionItem::RegionItemType) );
    }
  }
}

//-------------------------------------------------------------------------
void maplib::MapFile::loadFileHeader(int *n, int *m)
{
  if( !m || !n )
    return;

  m_file.read( (char*)n, sizeof(int) );
  m_file.read( (char*)m, sizeof(int) );
}

//-------------------------------------------------------------------------
void maplib::MapFile::loadFileData( int n, int m )
{
  if( n <= 0 || m <= 0 )
    return;

  Map::instance()->reset( n, m );

  RegionItem::RegionItemType type;

  m_file.seek( 2*sizeof(int) );

  for( int i = 0; i < n; i++ ){
    for( int j = 0; j < m; j++ ){
      m_file.read( (char*)(&type), sizeof(RegionItem::RegionItemType) );
      Map::instance()->m_map[i][j].setType( type );
    }
  }
}

//-------------------------------------------------------------------------
