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

  //Структура, описывающая заголовок карты
  struct MAPFILEHEADER
  {
    unsigned char Magick[8];                //Магическое число для простоты идентификации
    unsigned int minVersion;                //Младший номер версии
    unsigned int majVersion;                //Старший номер версии (пример 4.2 - 4 старший, 2 младший)
    unsigned int mapWidth;                  //Ширина карты в элементарных блоках
    unsigned int mapHeight;                 //Высота карты в элементарных блоках
    unsigned int cellSize;                  //Размер в экранных координатах
    unsigned int additionalInfoOffset;      //Смещение в файле, где располагается дополнительная информация(здоровье, очки и т.д.)
    unsigned int additionalInfoSize;        //Размер дополнительной информации
  };

  struct MAPITEM
  {
    unsigned int blockId;                   //Идентификатор блока
    unsigned int health;                    //Уровень повреждений/здоровья
    unsigned int direction;                 //Направление движения для движущихся объектов
  };

enum ItemType{
    UndefinedItem = 0,          //Неопределенный
    Block,                  //Движение заблокировано
    Free,                   //Движение возможно
    Player,                 //В ячейке находится персонаж игрока
    Enemy,                  //В ячейке находится вражеский персонаж
    Money,                  //В ячейке находятся призовые очки
    Home,                   //Ячейка, достижение игроком которой приводит к победе
};

enum BlockType{
    UndefinedBlock = 0,          //Неопределенный тип блока
    Wood,                   //Дерево
    Metal,                  //Металл
    Composite,              //Композиционные материалы
};

enum DirectionType{
     Fixed = 0,             //Без направления
     Up,                    //Вверх
     Down,                  //Вниз
     Left,                  //Влево
     Right,                 //Вправо
};

}//namespace maplib
//=========================================================================

#endif
