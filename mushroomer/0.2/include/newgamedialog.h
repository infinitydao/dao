/*             newgamedialog.h
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#ifndef __NEWGAMEDIALOG_H__
#define __NEWGAMEDIALOG_H__

#include <QDialog>
#include "ui_newgamedialog.h"
#include "gelib.h"

//=========================================================================
class NewGameDialog : public QDialog, public Ui::Dialog
{
  Q_OBJECT

public:
  NewGameDialog( QWidget *parent = 0, Qt::WindowFlags flags = 0 );
  ~NewGameDialog();

public slots:
  void OnMapSizeSelected( int Index );
  void OnGameModeSelected( int Index );

private:
  gelib::GameMapPatterns m_mapPattern;
  gelib::GameMode m_gameMode;

public:
  gelib::GameMapPatterns getGamePattern()const;
  gelib::GameMode getGameMode()const;
};

//=========================================================================

#endif //__NEWGAMEDIALOG_H__
