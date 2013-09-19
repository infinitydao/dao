/*             newgamedialog.cpp
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#include "newgamedialog.h"

//-------------------------------------------------------------------------
NewGameDialog::NewGameDialog( QWidget *parent, Qt::WindowFlags flags )
:QDialog(parent,flags),
m_mapPattern(gelib::Map_5x5),
m_gameMode(gelib::Noob)
{
  setupUi(this);
  mapSizeBox->addItem(tr("5x5"));
  mapSizeBox->addItem(tr("7x7"));
  mapSizeBox->addItem(tr("10x10"));
  mapSizeBox->addItem(tr("12x12"));
  mapSizeBox->addItem(tr("15x15"));
  mapSizeBox->addItem(tr("17x17"));
  mapSizeBox->addItem(tr("20x20"));
  mapSizeBox->addItem(tr("22x22"));
  mapSizeBox->addItem(tr("25x25"));
  mapSizeBox->addItem(tr("27x27"));
  mapSizeBox->addItem(tr("30x30"));

  gameModeBox->addItem(tr("Noob"));
  gameModeBox->addItem(tr("Easy"));
  gameModeBox->addItem(tr("Normal"));
  gameModeBox->addItem(tr("Hard"));
  gameModeBox->addItem(tr("Hardcore"));

  connect( mapSizeBox, SIGNAL(activated(int)), this, SLOT(OnMapSizeSelected(int)) );
  connect( gameModeBox, SIGNAL(activated(int)), this, SLOT(OnGameModeSelected(int)) );
}

//-------------------------------------------------------------------------
NewGameDialog::~NewGameDialog()
{

}

//-------------------------------------------------------------------------
void NewGameDialog::OnMapSizeSelected( int Index )
{
  switch( Index ){
    case 0:
      m_mapPattern = gelib::Map_5x5;
      break;
    case 1:
      m_mapPattern = gelib::Map_7x7;
      break;
    case 2:
      m_mapPattern = gelib::Map_10x10;
      break;
    case 3:
      m_mapPattern = gelib::Map_12x12;
      break;
    case 4:
      m_mapPattern = gelib::Map_15x15;
      break;
    case 5:
      m_mapPattern = gelib::Map_17x17;
      break;
    case 6:
      m_mapPattern = gelib::Map_20x20;
      break;
    case 7:
      m_mapPattern = gelib::Map_22x22;
      break;
    case 8:
      m_mapPattern = gelib::Map_25x25;
      break;
    case 9:
      m_mapPattern = gelib::Map_27x27;
      break;
    case 10:
      m_mapPattern = gelib::Map_30x30;
      break;
    default:
      break;
  }
}

//-------------------------------------------------------------------------
void NewGameDialog::OnGameModeSelected( int Index )
{
  switch( Index ){
    case 0:
      m_gameMode = gelib::Noob;
      break;
    case 1:
      m_gameMode = gelib::Easy;
      break;
    case 2:
      m_gameMode = gelib::Normal;
      break;
    case 3:
      m_gameMode = gelib::Hard;
      break;
    case 4:
      m_gameMode = gelib::Hardcore;
      break;
    default:
      break;
  }
}

//-------------------------------------------------------------------------
gelib::GameMapPatterns NewGameDialog::getGamePattern()const
{
  return m_mapPattern;
}

//-------------------------------------------------------------------------
gelib::GameMode NewGameDialog::getGameMode()const
{
  return m_gameMode;
}

//-------------------------------------------------------------------------
