/*              gamemanager.h
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include "singleton.h"

class QGraphicsScene;

//=========================================================================
namespace gelib
{

class GameGraphicsView;

enum GameStatus
{
  UnknownGameStatus = 0,          //Неизвестный статус
  NotInited,                      //Не инициализирована
  Inited,                         //Инициализировано и готово к запуску
  Running,                        //Запущена
  Paused,                         //Прервана на паузу
  Stopped,                        //Остановлена
};

enum GameMode
{
  UnknownGameMode = 0,            //Неизвестный режим игры
  Noob,                           //Самый легкий
  Easy,
  Normal,
  Hard,
  Hardcore,                       //Самый сложный
};

enum GameMapPatterns
{
  UnknownMapPattern = 0,
  Map_5x5,
  Map_7x7,
  Map_10x10,
  Map_12x12,
  Map_15x15,
  Map_17x17,
  Map_20x20,
  Map_22x22,
  Map_25x25,
  Map_27x27,
  Map_30x30,
};

class GameManager
{
public:
  GameManager();
  virtual ~GameManager();

protected:
  GameStatus m_status;
  GameMode m_mode;
  GameMapPatterns m_mapMode;
  GameGraphicsView *m_pView;

  virtual bool createGrid();
  virtual bool initMap( GameMapPatterns MapMode );
  virtual QGraphicsScene* createNewGraphicsScene();

public:
  void setGameStatus( GameStatus status );
  GameStatus getGameStatus()const;

  void setGameMode( GameMode mode );
  GameMode getGameMode()const;

  void setMapMode( GameMapPatterns MapMode );
  GameMapPatterns getMapMode()const;

  virtual bool init();

  void setGameGraphicsView( GameGraphicsView *pView );
  GameGraphicsView* getGameGraphicsView();
};

typedef maplib::Singleton<GameManager> Game;

} //namespace gelib

//=========================================================================

#endif //__GAMEMANAGER_H__
