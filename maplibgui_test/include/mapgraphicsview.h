/*
       mapgraphicsview.h
Created by infinitydao@gmail.com 
            09/2013
 General Publing License v 2.0
*/

#ifndef __MAPGRAPHICSVIEW_H__
#define __MAPGRAPHICSVIEW_H__

#include <QGraphicsView>

//=========================================================================
class MapGraphicsView : public QGraphicsView
{
  Q_OBJECT

public:
  MapGraphicsView( QWidget * parent = 0 );
  MapGraphicsView( QGraphicsScene * scene, QWidget * parent = 0 );
  ~MapGraphicsView();

};

//=========================================================================

#endif //__MAPGRAPHICSVIEW_H__
