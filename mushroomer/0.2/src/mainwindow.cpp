/*              mainwindow.cpp
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#include "mainwindow.h"
#include "newgamedialog.h"

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
  NewGameDialog dlg(this);
  if( QDialog::Accepted == dlg.exec() ){
    gelib::Game::instance()->setMapMode( dlg.getGamePattern() );
    gelib::Game::instance()->setGameMode( dlg.getGameMode() );
    gelib::Game::instance()->init();
    gelib::Game::instance()->setGameStatus( gelib::Inited );
  }
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
