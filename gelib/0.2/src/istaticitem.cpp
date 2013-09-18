/*              staticitem.cpp
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#include "gelib.h"

//-------------------------------------------------------------------------
gelib::IStaticItem::IStaticItem( maplib::ItemType type )
:IMapItem( type ),
IDrawItem()
{

}

//-------------------------------------------------------------------------
gelib::IStaticItem::IStaticItem( maplib::ItemType type, int x, int y, int width, int height, const QPixmap& pixmap )
:IMapItem( type ),
IDrawItem( x, y, width, height, pixmap )
{

}

//-------------------------------------------------------------------------
gelib::IStaticItem::IStaticItem( const IStaticItem& other )
:IMapItem( other.m_type ),
IDrawItem( other.m_x, other.m_y, other.m_width, other.m_height, other.m_pixmap )
{

}

//-------------------------------------------------------------------------
gelib::IStaticItem::~IStaticItem()
{

}

//-------------------------------------------------------------------------
gelib::IStaticItem& gelib::IStaticItem::operator=( const IStaticItem& other )
{
  if( &other == this )
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
