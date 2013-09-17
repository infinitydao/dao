/*
          mapfile.h
Created by infinitydao@gmail.com 
            09/2013
 General Publing License v 2.0
*/

#ifndef __MAPFILE_H__
#define __MAPFILE_H__

#include <QFile>
#include "map.h"

//=========================================================================
namespace maplib{

class CMap;

class MapFile
{
public:
  MapFile( const QString& name );
  virtual ~MapFile();

  virtual bool save(CMap& map);
  virtual bool load(CMap& map);

protected:
  QFile m_file;
};

}//namespace maplib

//=========================================================================

#endif //__MAPFILE_H__
