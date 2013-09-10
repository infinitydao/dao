/*
          map.h
Created by infinitydao@gmail.com 
            09/2013
*/

#ifndef __MAP_H__
#define __MAP_H__

#include <QVector>
#include <QSharedPointer>
#include "regionitem.h"

//=========================================================================
namespace maplib{

  //=======================================================================
  class Map
  /* ласс описывает пр€моугольную карту регионов(€чеек) размером m x n*/
  {
  public:
    explicit Map( const unsigned char m/*столбцы*/, const unsigned char n/*строки*/ );
    virtual ~Map();

  public:
    QVector<QVector< QSharedPointer<RegionItem> >> m_map;  //ƒвумерный массив €чеек карты (предварительный вариант)

    void clear();     //ќчистка m_map
  };
  //=======================================================================

}//namespace maplib

//=========================================================================

#endif//__MAP_H__
