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

  CreateActions();
  CreateMenus();
}

//-------------------------------------------------------------------------
MainWindow::~MainWindow()
{

}

//-------------------------------------------------------------------------
void MainWindow::OnNewMap()
{

}

//-------------------------------------------------------------------------
void MainWindow::OnSave()
{

}

//-------------------------------------------------------------------------
void MainWindow::OnSaveAs()
{

}

//-------------------------------------------------------------------------
void MainWindow::OnLoad()
{

}

//-------------------------------------------------------------------------
void MainWindow::OnExit()
{

}

//-------------------------------------------------------------------------
void MainWindow::CreateActions()
{
  m_NewMapAction = new QAction( tr("New"), this );
  connect( m_NewMapAction, SIGNAL(triggered()),
    this, SLOT(OnNewMap()));

  m_SaveMapAction = new QAction( tr("Save"), this );
  connect( m_SaveMapAction, SIGNAL(triggered()),
    this, SLOT(OnSave()));

  m_SaveAsMapAction = new QAction( tr("Save As.."), this );
  connect( m_SaveAsMapAction, SIGNAL(triggered()),
    this, SLOT(OnSaveAs()));

  m_LoadMapAction = new QAction( tr("Load"), this );
  connect( m_LoadMapAction, SIGNAL(triggered()),
    this, SLOT(OnLoad()));

  m_ExitAction = new QAction( tr("Exit"), this );
  connect( m_ExitAction, SIGNAL(triggered()),
    this, SLOT(OnExit()));
}

//-------------------------------------------------------------------------
void MainWindow::CreateMenus()
{
  menuFile->addAction( m_NewMapAction );
  menuFile->addAction( m_SaveMapAction );
  menuFile->addAction( m_SaveAsMapAction );
  menuFile->addAction( m_LoadMapAction );
  menuFile->addSeparator();
  menuFile->addAction( m_ExitAction );
}

//-------------------------------------------------------------------------
