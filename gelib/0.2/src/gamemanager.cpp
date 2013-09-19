/*              gamemanager.cpp
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#include "gelib.h"

std::auto_ptr<gelib::GameManager> gelib::Game::_inst( new gelib::GameManager );

//-------------------------------------------------------------------------
gelib::GameManager::GameManager()
{

}

//-------------------------------------------------------------------------
gelib::GameManager::~GameManager()
{

}

//-------------------------------------------------------------------------
void gelib::GameManager::setGameStatus( GameStatus status )
{
  m_status = status;
}

//-------------------------------------------------------------------------
gelib::GameStatus gelib::GameManager::getGameStatus()const
{
  return m_status;
}

//-------------------------------------------------------------------------
void gelib::GameManager::setGameMode( GameMode mode )
{
  m_mode = mode;
}

//-------------------------------------------------------------------------
gelib::GameMode gelib::GameManager::getGameMode()const
{
  return m_mode;
}

//-------------------------------------------------------------------------
void gelib::GameManager::setMapMode( GameMapPatterns MapMode )
{
  m_mapMode = MapMode;
}

//-------------------------------------------------------------------------
gelib::GameMapPatterns gelib::GameManager::getMapMode()const
{
  return m_mapMode;
}

//-------------------------------------------------------------------------
