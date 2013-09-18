/*          staticitemfactory.h
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#ifndef __STATICITEMFACTORY_H__
#define __STATICITEMFACTORY_H__

//=========================================================================
namespace gelib
{

class StaticItemFactory
{
protected:
  unsigned int m_emptyCounter;
  unsigned int m_blockCounter;
  unsigned int m_homeCounter;
  unsigned int m_moneyCounter;

public:
  StaticItemFactory();
  virtual ~StaticItemFactory();

  virtual IStaticItem* createItem( maplib::ItemType type, const QPoint& p, const QSize& size );

  unsigned int emptyItems()const;
  unsigned int blockItems()const;
  unsigned int homeItems()const;
  unsigned int moneyItems()const;
};

} //namespace gelib

//=========================================================================

#endif //__STATICITEMFACTORY_H__
