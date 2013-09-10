/*
          mapfile.h
Created by infinitydao@gmail.com 
            09/2013
*/

#ifndef __MAPFILE_H__
#define __MAPFILE_H__

#include <QFile>
#include "map.h"

//=========================================================================
namespace maplib{

class MapFile
{
public:
  MapFile( const Map& map );
  MapFile( const Map& map, const QString& name );
  virtual ~MapFile();

  bool Open();
  void setFileName( const QString& name );
  bool Save();
  bool Load();

protected:
  QFile m_file;
  const Map& m_map;

  virtual void saveFileHeader();
  virtual void saveFileData();
  virtual void loadFileHeader( int* m, int* n );
  virtual void loadFileData( int M, int N );
};

}//namespace maplib

//=========================================================================

#endif //__MAPFILE_H__
