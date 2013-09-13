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
  switch(m_state){
    case Free:{
      QPixmap freePic(":/images/free.png");
      QGraphicsPixmapItem *pItem = scene()->addPixmap( freePic );
      pItem->setX( event->pos().x() );
      pItem->setY( event->pos().y() );
      break;
      }
    case Block:{
      QPixmap blockPick(":/images/block.png");
      QGraphicsPixmapItem *pItem = scene()->addPixmap( blockPick );
      pItem->setX( event->pos().x() );
      pItem->setY( event->pos().y() );
      break;
      }
    case Player:{
      QPixmap playerPic(":/images/player.png");
      QGraphicsPixmapItem *pItem = scene()->addPixmap( playerPic );
      pItem->setX( event->pos().x() );
      pItem->setY( event->pos().y() );
      break;
      }
    case Enemy:{
      QPixmap enemyPic(":/images/enemy.png");
      QGraphicsPixmapItem *pItem = scene()->addPixmap( enemyPic );
      pItem->setX( event->pos().x() );
      pItem->setY( event->pos().y() );
      break;
      }
    case Undefined:
    default:
      break;
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
