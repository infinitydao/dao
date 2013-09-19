/*           gamegraphicsview.cpp
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#include "gelib.h"

//-------------------------------------------------------------------------
gelib::GameGraphicsView::GameGraphicsView( QWidget *parent )
:QGraphicsView( parent )
{

}

//-------------------------------------------------------------------------
gelib::GameGraphicsView::GameGraphicsView( QGraphicsScene *scene, QWidget *parent )
:QGraphicsView( scene, parent )
{

}

//-------------------------------------------------------------------------
gelib::GameGraphicsView::~GameGraphicsView()
{

}

//-------------------------------------------------------------------------
