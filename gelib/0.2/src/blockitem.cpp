/*              blockitem.cpp
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#include "gelib.h"

//-------------------------------------------------------------------------
gelib::BlockItem::BlockItem( int x, int y, int width, int height )
:IStaticItem( maplib::Block, x, y, width, height, QPixmap(":/images/block.png") )
{

}

//-------------------------------------------------------------------------
gelib::BlockItem::BlockItem( const QPoint& p, const QSize& size )
:IStaticItem( maplib::Block, p.x(), p.y(), size.width(), size.height(), QPixmap(":/images/block.png") )
{

}

//-------------------------------------------------------------------------
gelib::BlockItem::BlockItem( const BlockItem& other )
:IStaticItem( other.m_type, other.m_x, other.m_y, other.m_width, other.m_height, other.m_pixmap )
{

}

//-------------------------------------------------------------------------
gelib::BlockItem::~BlockItem()
{

}

//-------------------------------------------------------------------------
gelib::BlockItem& gelib::BlockItem::operator=( const BlockItem& other )
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
