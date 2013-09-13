/*
       mapgraphicsview.cpp
Created by infinitydao@gmail.com 
            09/2013
 General Publing License v 2.0
*/

#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include "mapgraphicsview.h"
#include "map.h"

//-------------------------------------------------------------------------
MapGraphicsView::MapGraphicsView( QWidget * parent /* = 0 */ )
:QGraphicsView(parent),
m_state(Undefined)
{

}

//-------------------------------------------------------------------------
MapGraphicsView::MapGraphicsView( QGraphicsScene * scene, QWidget * parent /* = 0 */ )
:QGraphicsView( scene, parent )
{

}

//-------------------------------------------------------------------------
MapGraphicsView::~MapGraphicsView()
{

}

//-------------------------------------------------------------------------
void MapGraphicsView::mouseDoubleClickEvent( QMouseEvent * event )
{
  QGraphicsView::mouseDoubleClickEvent( event );
}

//-------------------------------------------------------------------------
void MapGraphicsView::mouseMoveEvent( QMouseEvent * event )
{
  QGraphicsView::mouseMoveEvent( event );
}

//-------------------------------------------------------------------------
void MapGraphicsView::mousePressEvent( QMouseEvent * event )
{
  if( CheckValidCoords( event->pos().x(), event->pos().y() ) )
    DrawObject( m_state, event->pos().x(), event->pos().y() );
  QGraphicsView::mousePressEvent( event );
}

//-------------------------------------------------------------------------
void MapGraphicsView::mouseReleaseEvent( QMouseEvent * event )
{
  QGraphicsView::mouseReleaseEvent(event);
}

//-------------------------------------------------------------------------
void MapGraphicsView::paintEvent( QPaintEvent * event )
{
  QGraphicsView::paintEvent( event );
}

//-------------------------------------------------------------------------
void MapGraphicsView::setState( SceneState state )
{
  m_state = state;
}

//-------------------------------------------------------------------------
MapGraphicsView::SceneState MapGraphicsView::getState()const
{
  return m_state;
}

//-------------------------------------------------------------------------
QGraphicsPixmapItem* MapGraphicsView::DrawObject( SceneState state, int x, int y )
{
  QGraphicsPixmapItem* pItem = 0;
  QPixmap pixmap;

  switch( state ){
    case Free:
      pixmap = QPixmap(":/images/free.png");
      break;
    case Block:
      pixmap = QPixmap(":/images/block.png");
      break;
    case Player:
      pixmap = QPixmap(":/images/player.png");
      break;
    case Enemy:
      pixmap = QPixmap(":/images/enemy.png");
      break;
    case Undefined:
    default:
      break;
  }

  QSize CellSize( maplib::Map::instance()->cellSize(), maplib::Map::instance()->cellSize() );
  pixmap = pixmap.scaled( CellSize );

  pItem = scene()->addPixmap( pixmap );
  QPointF p = mapToScene( x, y );
  alignPoint( p );
  pItem->setX( p.x() );
  pItem->setY( p.y() );
  return pItem;
}

//-------------------------------------------------------------------------
void MapGraphicsView::alignPoint(QPointF &point)
{
  int x = point.x()/maplib::Map::instance()->cellSize();
  point.setX( x*maplib::Map::instance()->cellSize() );

  int y = point.y()/maplib::Map::instance()->cellSize();
  point.setY( y*maplib::Map::instance()->cellSize() );
}

//-------------------------------------------------------------------------
bool MapGraphicsView::CheckValidCoords(int x, int y)
{
   QPointF p = mapToScene( x, y );

   if( p.x() < 0 || p.x() > maplib::Map::instance()->cellSize()*maplib::Map::instance()->width() )
     return false;
   if( p.y() < 0 || p.y() > maplib::Map::instance()->cellSize()*maplib::Map::instance()->height() )
     return false;

  return true;
}

//-------------------------------------------------------------------------
