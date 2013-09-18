/*          staticitemfactory.cpp
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#include "gelib.h"

//-------------------------------------------------------------------------
gelib::StaticItemFactory::StaticItemFactory()
:m_emptyCounter(0),
m_blockCounter(0),
m_homeCounter(0),
m_moneyCounter(0)
{

}

//-------------------------------------------------------------------------
gelib::StaticItemFactory::~StaticItemFactory()
{

}

//-------------------------------------------------------------------------
gelib::IStaticItem* gelib::StaticItemFactory::createItem( maplib::ItemType type, const QPoint&p, const QSize& size )
{
  switch( type ){
    case maplib::Free:
      m_emptyCounter++;
      return new EmptyItem( p.x(), p.y(), size.width(), size.height() );
      break;
    case maplib::Block:
      m_blockCounter++;
      return new BlockItem( p.x(), p.y(), size.width(), size.height() );
      break;
    case maplib::Home:
      if( !m_homeCounter ){
        m_homeCounter++;
        return new HomeItem( p.x(), p.y(), size.width(), size.height() );
      }
      break;
    case maplib::Money:
      m_moneyCounter++;
      return new MoneyItem( p.x(). p.y(), size.width(), size.height() );
      break;
    default:
      break;
  }

  return reinterpret_cast<IStaticItem*>(0);
}

//-------------------------------------------------------------------------
unsigned int gelib::StaticItemFactory::emptyItems()const
{
  return m_emptyCounter;
}

//-------------------------------------------------------------------------
unsigned int gelib::StaticItemFactory::blockItems()const
{
  return m_blockCounter;
}

//-------------------------------------------------------------------------
unsigned int gelib::StaticItemFactory::homeItems()const
{
  return m_homeCounter;
}

//-------------------------------------------------------------------------
unsigned int gelib::StaticItemFactory::moneyItems()const
{
  return m_moneyCounter;
}

//-------------------------------------------------------------------------
