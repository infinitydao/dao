/*
          main.cpp
Created by infinitydao@gmail.com 
            09/2013
*/

#ifndef __REGIONITEM_H__
#define __REGIONITEM_H__

//=========================================================================
namespace maplib 
{

//========================================================================
/*ќписывает структуру игровой €чейки*/
class RegionItem
{
public:
  /*тип регионов(€чеек) на игровом поле*/
  enum RegionItemType{
          Wrong = 0,        //некорректна€ €чейка
          Block = 0xFF,     //движение по €чейке невозможно
          Free,             //движение по €чейке возможно
          Player,           //движение по €чейке возможно и на ней находитс€ игрок
          Enemy,            //движение по €чейке возможно и на ней находитс€ враг
  };

  //»нициализируем по умолчанию неверным блоком, чтобы отлавливать возможные ошибки
  RegionItem( RegionItemType type = Wrong );

  RegionItem( const RegionItem& other );
  RegionItem& operator=( const RegionItem& other );

  //добавлена возможность создани€ производных регионов
  virtual ~RegionItem();

protected:
  //тип региона
  RegionItemType m_type;

public:
  //метод возвращает тип региона
  RegionItemType type()const;
};

//=========================================================================

}//namespace maplib
//=========================================================================

#endif
