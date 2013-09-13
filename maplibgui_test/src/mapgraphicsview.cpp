/*
       mapgraphicsview.cpp
Created by infinitydao@gmail.com 
            09/2013
 General Publing License v 2.0
*/

#include "mapgraphicsview.h"

//-------------------------------------------------------------------------
MapGraphicsView::MapGraphicsView( QWidget * parent /* = 0 */ )
:QGraphicsView(parent)
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
