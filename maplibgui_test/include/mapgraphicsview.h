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

protected:
  //void contextMenuEvent( QContextMenuEvent * event );
  //void dragEnterEvent( QDragEnterEvent * event );
  //void dragLeaveEvent( QDragLeaveEvent * event );
  //void dragMoveEvent( QDragMoveEvent * event );
  //void dropEvent( QDropEvent * event );
  //bool event( QEvent * event );
  //void focusInEvent( QFocusEvent * event );
  //bool focusNextPrevChild( bool next );
  //void focusOutEvent( QFocusEvent * event );
  //void inputMethodEvent( QInputMethodEvent * event );
  //void keyPressEvent( QKeyEvent * event );
  //void keyReleaseEvent( QKeyEvent * event );
  void mouseDoubleClickEvent( QMouseEvent * event );
  void mouseMoveEvent( QMouseEvent * event );
  void mousePressEvent( QMouseEvent * event );
  void mouseReleaseEvent( QMouseEvent * event );
  void paintEvent( QPaintEvent * event );
  //void resizeEvent( QResizeEvent * event );
  //void scrollContentsBy( int dx, int dy );
  //void showEvent( QShowEvent * event );
  //bool viewportEvent( QEvent * event )
  //void wheelEvent( QWheelEvent * event );

};

//=========================================================================

#endif //__MAPGRAPHICSVIEW_H__
