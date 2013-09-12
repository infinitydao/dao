/*
          regionitem.cpp
Created by infinitydao@gmail.com 
            09/2013
 General Publing License v 2.0
*/

#include "regionitem.h"

//-------------------------------------------------------------------------
maplib::RegionItem::RegionItem( RegionItemType type )
:m_type( type )
{

}

//-------------------------------------------------------------------------
maplib::RegionItem::~RegionItem()
{

}

//-------------------------------------------------------------------------
maplib::RegionItem& maplib::RegionItem::operator =(const maplib::RegionItem &other)
{
  if( &other == this )
    return *this;
  m_type = other.m_type;
  return *this;
}

//-------------------------------------------------------------------------
maplib::RegionItem::RegionItem( const RegionItem& other )
:m_type(other.m_type)
{

}

//-------------------------------------------------------------------------
maplib::RegionItem::RegionItemType maplib::RegionItem::type() const
{
  return m_type;
}

//-------------------------------------------------------------------------
void maplib::RegionItem::setType(maplib::RegionItem::RegionItemType type)
{
  m_type = type;
}

//-------------------------------------------------------------------------
