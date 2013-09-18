/*                imapitem.cpp
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#include "gelib.h"

//-------------------------------------------------------------------------
gelib::IMapItem::IMapItem( maplib::ItemType type )
:m_type( type ),
m_directionType( maplib::Fixed ),
m_health( 0 ),
m_velocity( 0 )
{

}

//-------------------------------------------------------------------------
gelib::IMapItem::IMapItem( maplib::ItemType type, maplib::DirectionType dirType, unsigned int Health, unsigned int Velocity )
:m_type(type),
m_directionType(dirType),
m_health(Health),
m_velocity(Velocity)
{

}

//-------------------------------------------------------------------------
gelib::IMapItem::IMapItem( const IMapItem& other )
:m_type(other.m_type),
m_directionType(other.m_directionType),
m_health(other.m_health),
m_velocity(other.m_velocity)
{
  
}

//-------------------------------------------------------------------------
gelib::IMapItem::~IMapItem()
{

}

//-------------------------------------------------------------------------
gelib::IMapItem& gelib::IMapItem::operator=( const IMapItem& other )
{
  if( &other == this )
    return *this;

  m_type = other.m_type;
  m_directionType = other.m_directionType;
  m_health = other.m_health;
  m_velocity = other.m_velocity;

  return *this;
}

//-------------------------------------------------------------------------
void gelib::IMapItem::setType( maplib::ItemType type )
{
  m_type = type;
}

//-------------------------------------------------------------------------
maplib::ItemType gelib::IMapItem::getType()const
{
  return m_type;
}

//-------------------------------------------------------------------------
void gelib::IMapItem::setHealth( unsigned int health )
{
  m_health = health;
}

//-------------------------------------------------------------------------
unsigned int gelib::IMapItem::getHealth()const
{
  return m_health;
}

//-------------------------------------------------------------------------
void gelib::IMapItem::setVelocity( unsigned int velocity )
{
  m_velocity = velocity;
}

//-------------------------------------------------------------------------
unsigned int gelib::IMapItem::getVelocity()const
{
  return m_velocity;
}

//-------------------------------------------------------------------------
void gelib::IMapItem::setDirection( maplib::DirectionType directionType )
{
  m_directionType = directionType;
}

//-------------------------------------------------------------------------
maplib::DirectionType gelib::IMapItem::getDirection()const
{
  return m_directionType;
}

//-------------------------------------------------------------------------
