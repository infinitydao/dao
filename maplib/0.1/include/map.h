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
    const unsigned int m_cellSize;          //������ ����� ������� ������ (������ � ������)
    QString m_fileName;                     //���� �����
    int m_width;                          //������ �����
    int m_height;                         //������ �����

  public:
    CMap();
    virtual ~CMap();

    virtual void reset( int n, int m );             //������� ������ ����� � �������������� �����

    void setSize( int width, int height );

    int height()const;
    int width()const;

    void setFileName( const QString& name );
    QString fileName()const;

    int cellSize()const;

    QVector<QVector<RegionItem>>  m_map;    //�����

    virtual bool LoadMap();
    virtual bool SaveMap();
  };

  typedef Singleton<CMap> Map;

}//namespace maplib

//=========================================================================

#endif//__MAP_H__
