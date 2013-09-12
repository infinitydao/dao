/*
          map.h
Created by infinitydao@gmail.com 
            09/2013
  General Publing License v 2.0
*/

#ifndef __MAP_H__
#define __MAP_H__

#include <QVector>
#include <QSharedPointer>
#include "regionitem.h"
#include "singleton.h"

//=========================================================================
namespace maplib{

  //=======================================================================
  class CMap 
  {
  protected:
    const unsigned int m_cellSize;          //Размер одной игровой ячейки (ширина и высота)
    QString m_fileName;                     //Файл карты
    int m_width;                          //Ширина карты
    int m_height;                         //Высота карты

  public:
    CMap();
    virtual ~CMap();

    void reset( int n, int m );             //Удаляет старую карту и инициализирует новую

    void setSize( int width, int height );

    int height()const;
    int width()const;

    void setFileName( const QString& name );
    QString fileName()const;

    int cellSize()const;

    QVector<QVector<RegionItem>>  m_map;    //Карта
  };

  typedef Singleton<CMap> Map;

}//namespace maplib

//=========================================================================

#endif//__MAP_H__
