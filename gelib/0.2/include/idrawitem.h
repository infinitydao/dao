/*               idrawitem.h
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#ifndef __IDRAWITEM_H__
#define __IDRAWITEM_H__

#include <QPixmap>

//=========================================================================
namespace gelib
{

class IDrawItem
{
protected:
  int m_x;
  int m_y;
  int m_width;
  int m_height;
  QPixmap m_pixmap;

public:
  IDrawItem();
  explicit IDrawItem( int x, int y, int width, int height, const QPixmap& pixmap );
  explicit IDrawItem( const IDrawItem& other );
  virtual ~IDrawItem();

  IDrawItem& operator=( const IDrawItem&  other );

  int x()const;
  int y()const;
  int width()const;
  int height()const;
  QPixmap& pixmap();

  void setX( int x );
  void setY( int y );
  void setWidth( int width );
  void setHeight( int height );
  void setPixmap( const QPixmap& pixmap );
};

} //namespace gelib

//=========================================================================

#endif //__IDRAWITEM_H__
