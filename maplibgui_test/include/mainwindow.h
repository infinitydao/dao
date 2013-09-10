/*              mainwindow.h
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QMainWindow>
#include "ui_mainwindow.h"

//=========================================================================
class MainWindow : public QMainWindow, public Ui::MainWindow
{
public:
  MainWindow( QWidget *parent = 0, Qt::WindowFlags flags = 0 );
  ~MainWindow();

};

//=========================================================================

#endif //__MAINWINDOW_H__
