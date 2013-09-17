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

//���������, ����������� ��������� �����
struct MAPFILEHEADER
{
  unsigned char A[8];                     //���������� ����� ��� �������� �������������
  unsigned int minVersion;                //������� ����� ������
  unsigned int majVersion;                //������� ����� ������ (������ 4.2 - 4 �������, 2 �������)
  unsigned int mapWidth;                  //������ ����� � ������������ ������
  unsigned int mapHeight;                 //������ ����� � ������������ ������
  unsigned int additionalInfoOffset;      //�������� � �����, ��� ������������� �������������� ����������(��������, ���� � �.�.)
  unsigned int additionalInfoSize;        //������ �������������� ����������
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
