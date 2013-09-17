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

//Структура, описывающая заголовок карты
struct MAPFILEHEADER
{
  unsigned char A[8];                     //Магическое число для простоты идентификации
  unsigned int minVersion;                //Младший номер версии
  unsigned int majVersion;                //Старший номер версии (пример 4.2 - 4 старший, 2 младший)
  unsigned int mapWidth;                  //Ширина карты в элементарных блоках
  unsigned int mapHeight;                 //Высота карты в элементарных блоках
  unsigned int additionalInfoOffset;      //Смещение в файле, где располагается дополнительная информация(здоровье, очки и т.д.)
  unsigned int additionalInfoSize;        //Размер дополнительной информации
};

class MapFile
{
public:
  MapFile( );
  MapFile( const QString& name );
  virtual ~MapFile();

  bool Open();
  void setFileName( const QString& name );
  bool Save();
  bool Load();

protected:
  QFile m_file;

  virtual void saveFileHeader();
  virtual void saveFileData();
  virtual void loadFileHeader( int* n, int* m );
  virtual void loadFileData( int N, int M );
};

}//namespace maplib

//=========================================================================

#endif //__MAPFILE_H__
