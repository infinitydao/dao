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

#ifndef MAPLIB_MIN_VERSION
  #define MAPLIB_MIN_VERSION 1
#endif

#ifndef MAPLIB_MAJ_VERSION
  #define MAPLIB_MAJ_VERSION 0
#endif

//=========================================================================
namespace maplib{

  //=======================================================================
class CMap
{
protected:
  MAPFILEHEADER m_header;
  QString m_filename;

public:
  QVector<QVector<MAPBLOCK>> m_map;

  CMap();
  virtual ~CMap();

  virtual void reset( int Width, int Height );
  void setSize( int Width, int Height );

  int width()const;
  int height()const;

  void setFileName( const QString& name );
  QString fileName()const;

  int cellSize()const;

  virtual bool loadMap();
  virtual bool saveMap();
};

typedef Singleton<CMap> Map;

}//namespace maplib

//=========================================================================

#endif//__MAP_H__
