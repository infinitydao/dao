/*
          mapconsole.h
Created by infinitydao@gmail.com 
            09/2013
 General Publing License v 2.0
*/

#ifndef __MAPCONSOLE_H__
#define __MAPCONSOLE_H__

#include <Windows.h>
#include <stdio.h>
#include "regionitem.h"

//=========================================================================
//Windows only
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
    HANDLE m_hConsoleOut;

    BOOL PutCh( int ch );
  };

}

//=========================================================================

#endif //__MAPCONSOLE_H__
