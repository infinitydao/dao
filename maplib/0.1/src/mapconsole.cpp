/*
          mapconsole.cpp
Created by infinitydao@gmail.com 
            09/2013
  General Publing License v 2.0
*/

#include <stdexcept>
#include "mapconsole.h"

//-------------------------------------------------------------------------
maplib::MapConsole::MapConsole(maplib::RegionItem::RegionItemType type, int m, int n)
:m_type(type),
m_m(m),
m_n(n),
m_hConsoleOut(INVALID_HANDLE_VALUE)
{
  m_hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
  if( m_hConsoleOut == INVALID_HANDLE_VALUE )
    throw std::runtime_error("Can\'t open console");
  COORD crd;
  crd.X = m;
  crd.Y = n;
  SetConsoleCursorPosition( m_hConsoleOut, crd );
  if( type == RegionItem::Free )
    PutCh( 'e' );
  else
    PutCh( '#' );
}

//-------------------------------------------------------------------------
maplib::MapConsole::~MapConsole()
{

}

//-------------------------------------------------------------------------
BOOL maplib::MapConsole::PutCh(int ch)
{
  int wr;
  return WriteFile( m_hConsoleOut, (void*)&ch, 1, (LPDWORD)&wr, NULL );
}

//-------------------------------------------------------------------------