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
