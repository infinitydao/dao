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

//=========================================================================
class MainWindow : public QMainWindow, public Ui::MainWindow
{
  Q_OBJECT

public:
  MainWindow( QWidget *parent = 0, Qt::WindowFlags flags = 0 );
  ~MainWindow();

public slots:
  void OnNewMap();
  void OnSave();
  void OnSaveAs();
  void OnLoad();
  void OnExit();

private:
  void CreateActions();
  void CreateMenus();

  QAction *m_NewMapAction;
  QAction *m_SaveMapAction;
  QAction *m_SaveAsMapAction;
  QAction *m_LoadMapAction;
  QAction *m_ExitAction;
};

//=========================================================================

#endif //__MAINWINDOW_H__
