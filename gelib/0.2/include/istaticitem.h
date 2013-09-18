/*              staticitem.h
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#ifndef __ISTATICITEM_H__
#define __ISTATICITEM_H__

//=========================================================================
namespace gelib
{

class IStaticItem : public IMapItem, public IDrawItem
{
public:
  explicit IStaticItem( maplib::ItemType type );
  explicit IStaticItem( maplib::ItemType type, int x, int y, int width, int height, const QPixmap& pixmap );
  explicit IStaticItem( const IStaticItem& other );
  ~IStaticItem();

  IStaticItem& operator=( const IStaticItem& other );
};

} //namespace gelib

//=========================================================================

#endif //__ISTATICITEM_H__
