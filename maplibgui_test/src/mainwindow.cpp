/*              mainwindow.cpp
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#include "mainwindow.h"
#include "newmapdialog.h"

//-------------------------------------------------------------------------
MainWindow::MainWindow( QWidget *parent, Qt::WindowFlags flags )
:QMainWindow( parent, flags )
{
  setupUi(this);
  graphicsView->setVisible( false );

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
  NewMapDialog *pNewMapDialog = new NewMapDialog( this );

  if( pNewMapDialog->exec() == QDialog::Rejected )
    return;

  maplib::Map::instance()->setFileName( pNewMapDialog->fileName() );
  maplib::Map::instance()->reset( pNewMapDialog->Width().toInt(), pNewMapDialog->Height().toInt() );

  createNewMap();
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
  qApp->exit( 0 );
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


  m_BlockAction = new QAction( tr("Block"), this );
  connect( m_BlockAction, SIGNAL(triggered()),
    this, SLOT(OnBlock()) );

  m_EmptyAction = new QAction( tr("Empty"), this );
  connect( m_EmptyAction, SIGNAL(triggered()),
    this, SLOT(OnFree()));

  m_PlayerAction = new QAction( tr("Player"), this );
  connect( m_PlayerAction, SIGNAL(triggered()),
    this, SLOT(OnPlayer()) );

  m_EnemyAction = new QAction( tr("Enemy"), this );
  connect( m_EnemyAction, SIGNAL(triggered()),
    this, SLOT(OnEnemy()) ); 
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
void MainWindow::OnBlock()
{

}

//-------------------------------------------------------------------------
void MainWindow::OnEmpty()
{

}

//-------------------------------------------------------------------------
void MainWindow::OnPlayer()
{

}

//-------------------------------------------------------------------------
void MainWindow::OnEnemy()
{

}

//-------------------------------------------------------------------------
void MainWindow::createNewMap()
{
  graphicsView->setVisible( true );
  createGrid();
}

//-------------------------------------------------------------------------
void MainWindow::createGrid()
{
  m_scene.addRect( 0, 0, maplib::Map::instance()->width()*maplib::Map::instance()->cellSize(),
                   maplib::Map::instance()->height()*maplib::Map::instance()->cellSize(), QPen(), QBrush(QColor(0,125,0) ) );
  for( int i = 0; i <= maplib::Map::instance()->width(); i++ )
    m_scene.addLine( i*maplib::Map::instance()->cellSize(), 0, i*maplib::Map::instance()->cellSize(), maplib::Map::instance()->cellSize()*maplib::Map::instance()->height() );
  for( int i = 0; i <= maplib::Map::instance()->height(); i++ )
    m_scene.addLine( 0, i*maplib::Map::instance()->cellSize(), maplib::Map::instance()->cellSize()*maplib::Map::instance()->width(), i*maplib::Map::instance()->cellSize() );
  graphicsView->setScene( &m_scene );
}

//-------------------------------------------------------------------------
