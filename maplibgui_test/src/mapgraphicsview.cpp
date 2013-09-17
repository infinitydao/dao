/*
       mapgraphicsview.cpp
Created by infinitydao@gmail.com 
            09/2013
 General Publing License v 2.0
*/

#include <QGraphicsPixmapItem>
#include <QMouseEvent>

#include "mapgraphicsview.h"

//-------------------------------------------------------------------------
MapGraphicsView::MapGraphicsView( QWidget * parent /* = 0 */ )
:QGraphicsView(parent),
m_type(maplib::UndefinedItem)
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
  if( CheckValidCoords( event->pos().x(), event->pos().y() ) ){
    QPointF p = mapToScene( event->pos().x(), event->pos().y() );
    DrawObject( m_type, p.x(), p.y() );
    int i = p.x()/maplib::Map::instance()->cellSize();
    int j = p.y()/maplib::Map::instance()->cellSize();
    maplib::Map::instance()->m_map[i][j].blockId = m_type;
  }
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
void MapGraphicsView::setItemType( maplib::ItemType type )
{
  m_type = type;
}

//-------------------------------------------------------------------------
maplib::ItemType MapGraphicsView::getItemType()const
{
  return m_type;
}

//-------------------------------------------------------------------------
QGraphicsPixmapItem* MapGraphicsView::DrawObject( maplib::ItemType type, int x, int y )
{
  QGraphicsPixmapItem* pItem = 0;
  QPixmap pixmap;

  switch( type ){
    case maplib::Free:
      pixmap = QPixmap(":/images/free.png");
      break;
    case maplib::Block:
      pixmap = QPixmap(":/images/block.png");
      break;
    case maplib::Player:
      pixmap = QPixmap(":/images/player.png");
      break;
    case maplib::Enemy:
      pixmap = QPixmap(":/images/enemy.png");
      break;
    default:
      break;
  }

  QSize CellSize( maplib::Map::instance()->cellSize(), maplib::Map::instance()->cellSize() );
  pixmap = pixmap.scaled( CellSize );

  pItem = scene()->addPixmap( pixmap );
  QPointF p(x,y); //mapToScene( x, y );
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
