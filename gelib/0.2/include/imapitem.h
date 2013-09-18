/*                imapitem.h
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#ifndef __IMAPITEM_H__
#define __IMAPITEM_H__

#include "regionitem.h"

//=========================================================================
namespace gelib
{

class IMapItem
{
protected:
  maplib::ItemType m_type;                    //Тип ячейки
  unsigned int m_health;                      //Здорвье (для персонажей и разрушаемых блоков)
  maplib::DirectionType m_directionType;      //Направление (для движущихся объектов)
  unsigned int m_velocity;                    //Скорость (для движущихся объектов)

public:
  explicit IMapItem( maplib::ItemType type );
  explicit IMapItem( maplib::ItemType type, maplib::DirectionType dirType, unsigned int Health, unsigned int Velocity );
  explicit IMapItem( const IMapItem& other );
  virtual ~IMapItem();

  IMapItem& operator=( const IMapItem& other );

  void setType( maplib::ItemType type );
  maplib::ItemType getType()const;

  void setHealth( unsigned int health );
  unsigned int getHealth()const;

  void setVelocity( unsigned int velocity );
  unsigned int getVelocity()const;

  void setDirection( maplib::DirectionType directionType );
  maplib::DirectionType getDirection()const;
};

}//namespace gelib

//=========================================================================

#endif //__IMAPITEM_H__
