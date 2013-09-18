/*              emptyitem.h
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#ifndef __EMPTYITEM_H__
#define __EMPTYITEM_H__

#include <QPoint>
#include <QSize>

//=========================================================================
namespace gelib
{

class EmptyItem : public IStaticItem
{
public:
  explicit EmptyItem( int x, int y, int width, int height );
  explicit EmptyItem( const QPoint& p, const QSize& size );
  explicit EmptyItem( const EmptyItem& other );
  ~EmptyItem();
  EmptyItem& operator=( const EmptyItem& other );
};

} //namespace gelib

//=========================================================================

#endif //__EMPTYITEM_H__
