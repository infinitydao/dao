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
  seedMagick( &m_header, sizeof(m_header) );
  if( m_header.minVersion == 0 && m_header.majVersion == 0 ){
    m_header.minVersion = MAPLIB_MIN_VERSION;
    m_header.majVersion = MAPLIB_MAJ_VERSION;
  }
  if( m_header.cellSize == 0 )
    m_header.cellSize = DEFAULT_CELL_SIZE;
}

//-------------------------------------------------------------------------
maplib::CMap::~CMap()
{

}

//-------------------------------------------------------------------------
void maplib::CMap::reset( int Width, int Height )
{
  setSize( Width, Height );
  m_map.clear();

  for( int i = 0; i < Width; i++ ){
    QVector<MAPITEM> vec;
    for( int j = 0; j < Height; j++ ){
      MAPITEM item;
      item.blockId = static_cast<int>( ItemType::Free );
      item.health = 0;
      item.direction = static_cast<int>( DirectionType::Fixed );
      vec.push_back( item );
    }
    m_map.push_back( vec );
  }
}

//-------------------------------------------------------------------------
void maplib::CMap::setSize( int Width, int Height )
{
  m_header.mapWidth = Width;
  m_header.mapHeight = Height;
}

//-------------------------------------------------------------------------
int maplib::CMap::width()const
{
  return m_header.mapWidth;
}

//-------------------------------------------------------------------------
int maplib::CMap::height()const
{
  return m_header.mapHeight;
}

//-------------------------------------------------------------------------
void maplib::CMap::setFileName( const QString& name )
{
  m_filename = name;
}

//-------------------------------------------------------------------------
QString maplib::CMap::fileName()const
{
  return m_filename;
}

//-------------------------------------------------------------------------
int maplib::CMap::cellSize()const
{
  return m_header.cellSize;
}

//-------------------------------------------------------------------------
bool maplib::CMap::loadMap()
{
  MapFile file;

  return file.load(*this);
}

//-------------------------------------------------------------------------
bool maplib::CMap::saveMap()
{
  MapFile file;

  return file.save(*this);
}

//-------------------------------------------------------------------------
void maplib::CMap::seedMagick( MAPFILEHEADER *pHeader, unsigned int uiHeaderSize )
{
  if( !pHeader || !uiHeaderSize )
    return;

  //ѕока что жестко отсекаем по размеру, в дальнейшем ориентирование на номер версии
  if( uiHeaderSize != sizeof(MAPFILEHEADER) )
    return;

  pHeader->minVersion = MAPLIB_MIN_VERSION;
  pHeader->majVersion = MAPLIB_MAJ_VERSION;

  const unsigned char Magick_a = 0xFF;
  const unsigned char Magick_b = 0x0A;
  const unsigned char Magick_c = 0xAF;
  const unsigned char Magick_d = 0xCF;

  const unsigned char Magick_e = 0x4C;
  const unsigned char Magick_f = 0x00;
  const unsigned char Magick_g = 0x11;
  const unsigned char Magick_h = 0xAE;

  pHeader->Magick[0] = Magick_a;
  pHeader->Magick[1] = Magick_b;
  pHeader->Magick[2] = Magick_c;
  pHeader->Magick[3] = Magick_d;

  pHeader->Magick[4] = Magick_e;
  pHeader->Magick[5] = Magick_f;
  pHeader->Magick[6] = Magick_g;
  pHeader->Magick[7] = Magick_h;
}

//-------------------------------------------------------------------------
bool maplib::CMap::checkMagick( MAPFILEHEADER *pHeader, unsigned int uiHeaderSize,
                         unsigned int uiMinVersion, unsigned int uiMajVersion )
{
  const unsigned char Magick_a = 0xFF;
  const unsigned char Magick_b = 0x0A;
  const unsigned char Magick_c = 0xAF;
  const unsigned char Magick_d = 0xCF;

  const unsigned char Magick_e = 0x4C;
  const unsigned char Magick_f = 0x00;
  const unsigned char Magick_g = 0x11;
  const unsigned char Magick_h = 0xAE;

  if( !pHeader || !uiHeaderSize )
    return false;

  if( uiMinVersion != MAPLIB_MIN_VERSION || uiMajVersion != MAPLIB_MAJ_VERSION )
    return false;

  if( uiHeaderSize != sizeof(MAPFILEHEADER) )
    return false;

  bool chain_1 = pHeader->Magick[0] == Magick_a && pHeader->Magick[1] == Magick_b;
  bool chain_2 = pHeader->Magick[2] == Magick_c && pHeader->Magick[3] == Magick_d;
  bool chain_3 = pHeader->Magick[4] == Magick_e && pHeader->Magick[5] == Magick_f;
  bool chain_4 = pHeader->Magick[6] == Magick_g && pHeader->Magick[7] == Magick_h;

  return chain_1 && chain_2 && chain_3 && chain_4;

  return false;
}

//-------------------------------------------------------------------------
int maplib::CMap::majorVersion()const
{
  return m_header.majVersion;
}

//-------------------------------------------------------------------------
int maplib::CMap::minorVersion()const
{
  return m_header.minVersion;
}

//-------------------------------------------------------------------------
