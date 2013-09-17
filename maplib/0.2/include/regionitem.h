/*
          regionitem.h
Created by infinitydao@gmail.com 
            09/2013
  General Publing License v 2.0
*/

#ifndef __REGIONITEM_H__
#define __REGIONITEM_H__

//=========================================================================
namespace maplib 
{

  //���������, ����������� ��������� �����
  struct MAPFILEHEADER
  {
    unsigned char Magick[8];                //���������� ����� ��� �������� �������������
    unsigned int minVersion;                //������� ����� ������
    unsigned int majVersion;                //������� ����� ������ (������ 4.2 - 4 �������, 2 �������)
    unsigned int mapWidth;                  //������ ����� � ������������ ������
    unsigned int mapHeight;                 //������ ����� � ������������ ������
    unsigned int cellSize;                  //������ � �������� �����������
    unsigned int additionalInfoOffset;      //�������� � �����, ��� ������������� �������������� ����������(��������, ���� � �.�.)
    unsigned int additionalInfoSize;        //������ �������������� ����������
  };

  struct MAPITEM
  {
    unsigned int blockId;                   //������������� �����
    unsigned int health;                    //������� �����������/��������
    unsigned int direction;                 //����������� �������� ��� ���������� ��������
  };

enum ItemType{
    UndefinedItem = 0,          //��������������
    Block,                  //�������� �������������
    Free,                   //�������� ��������
    Player,                 //� ������ ��������� �������� ������
    Enemy,                  //� ������ ��������� ��������� ��������
    Money,                  //� ������ ��������� �������� ����
    Home,                   //������, ���������� ������� ������� �������� � ������
};

enum BlockType{
    UndefinedBlock = 0,          //�������������� ��� �����
    Wood,                   //������
    Metal,                  //������
    Composite,              //�������������� ���������
};

enum DirectionType{
     Fixed = 0,             //��� �����������
     Up,                    //�����
     Down,                  //����
     Left,                  //�����
     Right,                 //������
};

}//namespace maplib
//=========================================================================

#endif
