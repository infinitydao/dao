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
  /*����� ��������� ������������� ����� ��������(�����) �������� m x n*/
  {
  public:
    explicit Map( const unsigned char m/*�������*/, const unsigned char n/*������*/ );
    virtual ~Map();

  protected:
    QVector<QVector< QSharedPointer<RegionItem> >> m_map;  //��������� ������ ����� ����� (��������������� �������)
  };
  //=======================================================================

}//namespace maplib

//=========================================================================

#endif//__MAP_H__
