/*
          regionitem.h
Created by infinitydao@gmail.com 
            09/2013
*/

#ifndef __REGIONITEM_H__
#define __REGIONITEM_H__

//=========================================================================
namespace maplib 
{

//========================================================================
/*��������� ��������� ������� ������*/
class RegionItem
{
public:
  /*��� ��������(�����) �� ������� ����*/
  enum RegionItemType{
          Wrong = 0,        //������������ ������
          Block = 0xFF,     //�������� �� ������ ����������
          Free,             //�������� �� ������ ��������
          Player,           //�������� �� ������ �������� � �� ��� ��������� �����
          Enemy,            //�������� �� ������ �������� � �� ��� ��������� ����
  };

  //�������������� �� ��������� �������� ������, ����� ����������� ��������� ������
  RegionItem( RegionItemType type = Wrong );

  RegionItem( const RegionItem& other );
  RegionItem& operator=( const RegionItem& other );

  //��������� ����������� �������� ����������� ��������
  virtual ~RegionItem();

protected:
  //��� �������
  RegionItemType m_type;

public:
  //����� ���������� ��� �������
  RegionItemType type()const;
};

//=========================================================================

}//namespace maplib
//=========================================================================

#endif
