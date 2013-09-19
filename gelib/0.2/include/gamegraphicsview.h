/*           gamegraphicsview.h
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#ifndef __GAMEGRAPHICSVIEW_H__
#define __GAMEGRAPHICSVIEW_H__

#include <QGraphicsView>

//=========================================================================
namespace gelib
{

class GameGraphicsView : public QGraphicsView
{
  Q_OBJECT

public:
  GameGraphicsView( QWidget *parent = 0 );
  GameGraphicsView( QGraphicsScene *scene, QWidget *parent = 0 );
  ~GameGraphicsView();
};

} //namespace gelib

//=========================================================================

#endif //__GAMEGRAPHICSVIEW_H__
