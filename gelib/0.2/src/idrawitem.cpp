/*               idrawitem.cpp
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#include "gelib.h"

//-------------------------------------------------------------------------
gelib::IDrawItem::IDrawItem()
:m_x(0),
m_y(0),
m_width(0),
m_height(0),
m_pixmap(QPixmap())
{

}

//-------------------------------------------------------------------------
gelib::IDrawItem::IDrawItem( int x, int y, int width, int height, const QPixmap& pixmap )
:m_x(x),
m_y(y),
m_width(width),
m_height(height),
m_pixmap(pixmap)
{

}

//-------------------------------------------------------------------------
gelib::IDrawItem::IDrawItem( const IDrawItem& other )
:m_x(other.m_x),
m_y(other.m_y),
m_width(other.m_width),
m_height(other.m_height),
m_pixmap(other.m_pixmap)
{

}

//-------------------------------------------------------------------------
gelib::IDrawItem::~IDrawItem()
{

}

//-------------------------------------------------------------------------
gelib::IDrawItem& gelib::IDrawItem::operator=( const IDrawItem&  other )
{
  if( this == &other )
    return *this;

  m_x = other.m_x;
  m_y = other.m_y;
  m_width = other.m_width;
  m_height = other.m_height;
  m_pixmap = other.m_pixmap;

  return *this;
}

//-------------------------------------------------------------------------
int gelib::IDrawItem::x()const
{
  return m_x;
}

//-------------------------------------------------------------------------
int gelib::IDrawItem::y()const
{
  return m_y;
}

//-------------------------------------------------------------------------
int gelib::IDrawItem::width()const
{
  return m_width;
}

//-------------------------------------------------------------------------
int gelib::IDrawItem::height()const
{
  return m_height;
}

//-------------------------------------------------------------------------
QPixmap& gelib::IDrawItem::pixmap()
{
  return m_pixmap;
}

//-------------------------------------------------------------------------
void gelib::IDrawItem::setX( int x )
{
  m_x = x;
}

//-------------------------------------------------------------------------
void gelib::IDrawItem::setY( int y )
{
  m_y = y;
}

//-------------------------------------------------------------------------
void gelib::IDrawItem::setWidth( int width )
{
  m_width = width;
}

//-------------------------------------------------------------------------
void gelib::IDrawItem::setHeight( int height )
{
  m_height = height;
}

//-------------------------------------------------------------------------
void gelib::IDrawItem::setPixmap( const QPixmap& pixmap )
{
  m_pixmap = pixmap;
}

//-------------------------------------------------------------------------
