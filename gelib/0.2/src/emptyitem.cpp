/*              emptyitem.cpp
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#include "gelib.h"

//-------------------------------------------------------------------------
gelib::EmptyItem::EmptyItem( int x, int y, int width, int height )
:IStaticItem( maplib::Free, x, y, width, height, QPixmap(":/images/free.png") )
{

}

//-------------------------------------------------------------------------
gelib::EmptyItem::EmptyItem( const QPoint& p, const QSize& size )
:IStaticItem( maplib::Free, p.x(), p.y(), size.width(), size.height(), QPixmap(":/images/free.png" ) )
{

}

//-------------------------------------------------------------------------
gelib::EmptyItem::EmptyItem( const EmptyItem& other )
:IStaticItem( other.m_type, other.m_x, other.m_y, other.m_width, other.m_height, other.m_pixmap )
{

}

//-------------------------------------------------------------------------
gelib::EmptyItem::~EmptyItem()
{

}

//-------------------------------------------------------------------------
gelib::EmptyItem& gelib::EmptyItem::operator=( const EmptyItem& other )
{
  if( this == &other )
    return *this;

  m_type = other.m_type;
  m_x = other.m_x;
  m_y = other.m_y;
  m_width = other.m_width;
  m_height = other.m_height;
  m_pixmap = other.m_pixmap;

  return *this;
}

//-------------------------------------------------------------------------
