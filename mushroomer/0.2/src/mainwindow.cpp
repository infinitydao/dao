/*              mainwindow.cpp
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#include "mainwindow.h"

//-------------------------------------------------------------------------
MainWindow::MainWindow( QWidget *parent, Qt::WindowFlags flags )
:QMainWindow( parent, flags )
{
  setupUi(this);
  setCentralWidget( graphicsView );
  connect( actionNew_game, SIGNAL(triggered()), this, SLOT(OnNewGame()) );
  connect( actionSave_game, SIGNAL(triggered()), this, SLOT(OnSaveGame()) );
  connect( actionLoad_game, SIGNAL(triggered()), this, SLOT(OnLoadGame()) );
  connect( actionExit, SIGNAL(triggered()), this, SLOT(OnExit()) );
}

//-------------------------------------------------------------------------
MainWindow::~MainWindow()
{

}

//-------------------------------------------------------------------------
void MainWindow::OnNewGame()
{

}

//-------------------------------------------------------------------------
void MainWindow::OnSaveGame()
{

}

//-------------------------------------------------------------------------
void MainWindow::OnLoadGame()
{

}

//-------------------------------------------------------------------------
void MainWindow::OnExit()
{
  qApp->exit( 0 );
}

//-------------------------------------------------------------------------
