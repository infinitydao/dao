/*              moneyitem.h
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#ifndef __MONEYITEM_H__
#define __MONEYITEM_H__

//=========================================================================
namespace gelib
{

class MoneyItem : public IStaticItem
{
public:
  explicit MoneyItem( int x, int y, int width, int height );
  explicit MoneyItem( const QPoint& p, const QSize& size );
  explicit MoneyItem( const MoneyItem& other );
  ~MoneyItem();
  MoneyItem& operator=( const MoneyItem& other );
};

} //namespace gelib

//=========================================================================

#endif //__MONEYITEM_H__
