/*              homeitem.h
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#ifndef __HOMEITEM_H__
#define __HOMEITEM_H__

//=========================================================================
namespace gelib
{

class HomeItem : public IStaticItem
{
public:
  explicit HomeItem( int x, int y, int width, int height );
  explicit HomeItem( const QPoint& p, const QSize& size );
  explicit HomeItem( const HomeItem& other );
  ~HomeItem();
  HomeItem& operator=( const HomeItem& other );
};

} //namespace gelib

//=========================================================================

#endif //__HOMEITEM_H__
