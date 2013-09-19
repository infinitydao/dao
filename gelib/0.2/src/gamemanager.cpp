/*              gamemanager.cpp
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#include "gelib.h"
#include "map.h"

std::auto_ptr<gelib::GameManager> gelib::Game::_inst( new gelib::GameManager );

//-------------------------------------------------------------------------
gelib::GameManager::GameManager()
:m_pView(0)
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
  initMap(MapMode);
  m_mapMode = MapMode;
}

//-------------------------------------------------------------------------
gelib::GameMapPatterns gelib::GameManager::getMapMode()const
{
  return m_mapMode;
}

//-------------------------------------------------------------------------
bool gelib::GameManager::init()
{
  if( !createGrid() )
    return false;
  return true;
}

//-------------------------------------------------------------------------
void gelib::GameManager::setGameGraphicsView( GameGraphicsView *pView )
{
  m_pView = pView;
}

//-------------------------------------------------------------------------
gelib::GameGraphicsView* gelib::GameManager::getGameGraphicsView()
{
  return m_pView;
}

//-------------------------------------------------------------------------
bool gelib::GameManager::createGrid()
{
  QGraphicsScene *pScene = m_pView->scene();

  if( !pScene )
    pScene = createNewGraphicsScene();

  pScene->addRect( 0, 0, maplib::Map::instance()->width()*maplib::Map::instance()->cellSize(),
       maplib::Map::instance()->height()*maplib::Map::instance()->cellSize(), QPen(), QBrush(QColor(0,125,0) ) );
  for( int i = 0; i <= maplib::Map::instance()->width(); i++ )
    pScene->addLine( i*maplib::Map::instance()->cellSize(), 0, i*maplib::Map::instance()->cellSize(), maplib::Map::instance()->cellSize()*maplib::Map::instance()->height() );
  for( int i = 0; i <= maplib::Map::instance()->height(); i++ )
    pScene->addLine( 0, i*maplib::Map::instance()->cellSize(), maplib::Map::instance()->cellSize()*maplib::Map::instance()->width(), i*maplib::Map::instance()->cellSize() );

  return true;
}

//-------------------------------------------------------------------------
bool gelib::GameManager::initMap( GameMapPatterns MapMode )
{
  //Зададим имя файла по умолчанию
  maplib::Map::instance()->setFileName( QString("Untitled.map") );

  switch( MapMode ){
    case Map_5x5:
      maplib::Map::instance()->reset( 5, 5 );
      break;
    case Map_7x7:
      maplib::Map::instance()->reset( 7, 7 );
      break;
    case Map_10x10:
      maplib::Map::instance()->reset( 10, 10 );
      break;
    case Map_12x12:
      maplib::Map::instance()->reset( 12, 12 );
      break;
    case Map_15x15:
      maplib::Map::instance()->reset( 15, 15 );
      break;
    case Map_17x17:
      maplib::Map::instance()->reset( 17, 17 );
      break;
    case Map_20x20:
      maplib::Map::instance()->reset( 20, 20 );
      break;
    case Map_22x22:
      maplib::Map::instance()->reset( 22, 22 );
      break;
    case Map_25x25:
      maplib::Map::instance()->reset( 25, 25 );
      break;
    case Map_27x27:
      maplib::Map::instance()->reset( 27, 27 );
      break;
    case Map_30x30:
      maplib::Map::instance()->reset( 30, 30 );
      break;
    default:
      return false;
      break;
  }
  return true;
}

//-------------------------------------------------------------------------
QGraphicsScene* gelib::GameManager::createNewGraphicsScene()
{
  return new QGraphicsScene;
}

//-------------------------------------------------------------------------
