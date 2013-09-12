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

//=========================================================================
namespace maplib{

  //=======================================================================
  class Map
  /*Класс описывает прямоугольную карту регионов(ячеек) размером m x n*/
  {
  public:
    Map();
    explicit Map( const unsigned char m/*столбцы*/, const unsigned char n/*строки*/ );
    virtual ~Map();

  public:
    QVector<QVector< QSharedPointer<RegionItem> >> m_map;  //Двумерный массив ячеек карты (предварительный вариант)

    void clear();     //Очистка m_map
    bool isEmpty()const;  
    int m()const;
    int n()const;
    void reset( const unsigned char m, const unsigned char n ); //Удаляет старую карту и инициализирует новую
  };
  //=======================================================================

  class NewMap 
  {
  protected:
    unsigned int m_cellSize;                //Размер одной игровой ячейки (ширина и высота)
    QString m_fileName;                     //Файл карты
    float m_width;                          //Ширина карты
    float m_height;                         //Высота карты
  };

}//namespace maplib

//=========================================================================

#endif//__MAP_H__
