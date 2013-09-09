/*
          mapconsole.h
Created by infinitydao@gmail.com 
            09/2013
*/

#ifndef __MAPCONSOLE_H__
#define __MAPCONSOLE_H__

#include "regionitem.h"

//=========================================================================
namespace maplib{

  /*
      # - block item
      e - empty item
  */
  class MapConsole{
    /*Класс для тестирования карт в консоли*/
  public:
    MapConsole( RegionItem::RegionItemType type, int m, int n );
    virtual ~MapConsole();

  protected:
    RegionItem::RegionItemType m_type;
    int m_m;
    int m_n;
  };

}

//=========================================================================

#endif //__MAPCONSOLE_H__
