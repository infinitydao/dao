/*              mainwindow.cpp
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#include <QFileDialog>
#include <QMessageBox>
#include "mainwindow.h"
#include "newmapdialog.h"

//-------------------------------------------------------------------------
MainWindow::MainWindow( QWidget *parent, Qt::WindowFlags flags )
:QMainWindow( parent, flags ),
m_state( Undefined )
{
  setupUi(this);
  graphicsView->setVisible( false );

  CreateActions();
  CreateMenus();
  ConnectButtons();
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
  Ui::MainWindow::graphicsView->setState( MapGraphicsView::SceneState::Free );

  m_state = Edited;
}

//-------------------------------------------------------------------------
void MainWindow::OnSave()
{
  maplib::Map::instance()->setFileName( QFileDialog::getSaveFileName() );
  maplib::Map::instance()->saveMap();
  m_state = Saved;
}

//-------------------------------------------------------------------------
void MainWindow::OnSaveAs()
{
  OnSave();
}

//-------------------------------------------------------------------------
void MainWindow::OnLoad()
{
  maplib::Map::instance()->setFileName( QFileDialog::getOpenFileName() );
  if( maplib::Map::instance()->loadMap() ){
    graphicsView->setVisible( true );
    LoadMap();
  }
  m_state = Loaded;
}

//-------------------------------------------------------------------------
void MainWindow::OnExit()
{
#ifndef _DEBUG
  QMessageBox::StandardButton res = QMessageBox::question( this, tr("Do you realy want to exit?"), tr("Save file before exit?"),
    QMessageBox::Ok|QMessageBox::Cancel );
  if( res == QMessageBox::Ok )
    OnSave();
#endif //_DEBUG
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

  QPixmap blockPic(":/images/block.png");
  m_BlockAction = new QAction( QIcon(blockPic), tr("Block"), this );
  connect( m_BlockAction, SIGNAL(triggered()),
    this, SLOT(OnBlock()) );

  QPixmap emptyPic(":/images/free.png");
  m_EmptyAction = new QAction( QIcon(emptyPic), tr("Free"), this );
  connect( m_EmptyAction, SIGNAL(triggered()),
    this, SLOT(OnEmpty()));

  QPixmap playerPic(":/images/player.png");
  m_PlayerAction = new QAction( QIcon(playerPic), tr("Player"), this );
  connect( m_PlayerAction, SIGNAL(triggered()),
    this, SLOT(OnPlayer()) );

  QPixmap enemyPic(":/images/enemy.png");
  m_EnemyAction = new QAction( QIcon(enemyPic), tr("Enemy"), this );
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
  graphicsView->setState( MapGraphicsView::SceneState::Block );
}

//-------------------------------------------------------------------------
void MainWindow::OnEmpty()
{
  graphicsView->setState( MapGraphicsView::SceneState::Free );
}

//-------------------------------------------------------------------------
void MainWindow::OnPlayer()
{
  graphicsView->setState( MapGraphicsView::SceneState::Player );
}

//-------------------------------------------------------------------------
void MainWindow::OnEnemy()
{
  graphicsView->setState( MapGraphicsView::SceneState::Enemy );
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
void MainWindow::ConnectButtons()
{
  toolButton->setDefaultAction( m_BlockAction );
  toolButton_2->setDefaultAction( m_EmptyAction );
  toolButton_3->setDefaultAction( m_PlayerAction );
  toolButton_4->setDefaultAction( m_EnemyAction );
}

//-------------------------------------------------------------------------
void MainWindow::LoadMap()
{
  createNewMap();
  createGrid();
  LoadObjects();
}

//-------------------------------------------------------------------------
void MainWindow::LoadObjects()
{
   for( int i = 0; i < maplib::Map::instance()->width(); i++ ){
     for( int j = 0; j < maplib::Map::instance()->height(); j++ ){
       if( maplib::Map::instance()->m_map[i][j].blockId != maplib::ItemType::Free ){
         graphicsView->DrawObject( (MapGraphicsView::SceneState)maplib::Map::instance()->m_map[i][j].blockId, i*maplib::Map::instance()->cellSize(), j*maplib::Map::instance()->cellSize() );
       }
     }
   }
}

//-------------------------------------------------------------------------
