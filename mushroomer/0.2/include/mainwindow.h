/*              mainwindow.h
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QMainWindow>
#include "ui_mushroomer.h"

//=========================================================================
class MainWindow : public QMainWindow, public Ui::MainWindow
{
  Q_OBJECT

public:
  MainWindow( QWidget *parent = 0, Qt::WindowFlags flags = 0 );
  ~MainWindow();

public slots:
  void OnNewGame();
  void OnSaveGame();
  void OnLoadGame();
  void OnExit();
};

//=========================================================================

#endif
