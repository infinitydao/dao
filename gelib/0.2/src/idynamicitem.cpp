/*              idynamicitem.cpp
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#include "gelib.h"

//-------------------------------------------------------------------------
gelib::IDynamicItem::IDynamicItem( maplib::ItemType type,
                                  maplib::DirectionType directionType, 
                                  unsigned int health, 
                                  unsigned int velocity, 
                                  int x, 
                                  int y, 
                                  int width,
                                  int height, 
                                  const QPixmap& pixmap )
:IMapItem( type, directionType, health, velocity ),
IDrawItem( x, y, width, height, pixmap )
{

}

//-------------------------------------------------------------------------
gelib::IDynamicItem::IDynamicItem( const IDynamicItem& other )
:IMapItem( other.m_type, other.m_directionType, m_health, m_velocity ),
IDrawItem( other.m_x, other.m_y, other.m_width, other.m_height, other.m_pixmap )
{

}

//-------------------------------------------------------------------------
gelib::IDynamicItem::~IDynamicItem()
{

}

//-------------------------------------------------------------------------
gelib::IDynamicItem& gelib::IDynamicItem::operator=( const IDynamicItem& other )
{
  if( this == &other )
    return *this;

  m_type = other.m_type;
  m_directionType = other.m_directionType;
  m_health = other.m_health;
  m_velocity = other.m_velocity;

  m_x = other.m_x;
  m_y = other.m_y;
  m_width = other.m_width;
  m_height = other.m_height;
  m_pixmap = other.m_pixmap;

  return *this;
}

//-------------------------------------------------------------------------
