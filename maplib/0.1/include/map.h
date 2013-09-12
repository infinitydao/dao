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
  /*����� ��������� ������������� ����� ��������(�����) �������� m x n*/
  {
  public:
    Map();
    explicit Map( const unsigned char m/*�������*/, const unsigned char n/*������*/ );
    virtual ~Map();

  public:
    QVector<QVector< QSharedPointer<RegionItem> >> m_map;  //��������� ������ ����� ����� (��������������� �������)

    void clear();     //������� m_map
    bool isEmpty()const;  
    int m()const;
    int n()const;
    void reset( const unsigned char m, const unsigned char n ); //������� ������ ����� � �������������� �����
  };
  //=======================================================================

}//namespace maplib

//=========================================================================

#endif//__MAP_H__
