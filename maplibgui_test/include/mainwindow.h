/*              mainwindow.h
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QMainWindow>
#include <QAction>
#include "ui_mainwindow.h"
#include "map.h"

//=========================================================================
class MainWindow : public QMainWindow, public Ui::MainWindow
{
  Q_OBJECT

public:
  MainWindow( QWidget *parent = 0, Qt::WindowFlags flags = 0 );
  ~MainWindow();

  enum EditorState{
    Undefined = 0,
    Free,
    Block,
    Player,
    Enemy,
  };

public slots:
  void OnNewMap();
  void OnSave();
  void OnSaveAs();
  void OnLoad();
  void OnExit();

  void OnBlock();
  void OnEmpty();
  void OnPlayer();
  void OnEnemy();

private:
  void CreateActions();
  void CreateMenus();

  void createNewMap();
  void createGrid();

  QAction *m_NewMapAction;
  QAction *m_SaveMapAction;
  QAction *m_SaveAsMapAction;
  QAction *m_LoadMapAction;
  QAction *m_ExitAction;

  EditorState m_state;

  QAction *m_BlockAction;
  QAction *m_EmptyAction;
  QAction *m_PlayerAction;
  QAction *m_EnemyAction;

  QGraphicsScene m_scene;

public:
  EditorState getState()const;
  void setState( const EditorState& state );
};

//=========================================================================

#endif //__MAINWINDOW_H__
