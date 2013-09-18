/*              idynamicitem.h
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#ifndef __IDYNAMICITEM_H__
#define __IDYNAMICITEM_H__

//=========================================================================
namespace gelib
{

class IDynamicItem : public IMapItem, public IDrawItem
{
public:
  explicit IDynamicItem( maplib::ItemType type, maplib::DirectionType directionType, 
    unsigned int health, unsigned int velocity, int x, int y, int width,
    int height, const QPixmap& pixmap );
  explicit IDynamicItem( const IDynamicItem& other );
  ~IDynamicItem();

  IDynamicItem& operator=( const IDynamicItem& other );
};

} //namespace gelib

//=========================================================================

#endif //__IDYNAMICITEM_H__
