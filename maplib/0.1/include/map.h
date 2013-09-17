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
  MAPFILEHEADER m_header;
  QString m_filename;

  virtual void seedMagick( MAPFILEHEADER *pHeader, unsigned int uiHeaderSize );     //Инициализирует заголовок "волшебными числами" и версией
  virtual bool checkMagick( MAPFILEHEADER *pHeader, unsigned int uiHeaderSize,
                            unsigned int uiMinVersion, unsigned int uiMajVersion );    //Проверяет корректность заголовка и версии

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
