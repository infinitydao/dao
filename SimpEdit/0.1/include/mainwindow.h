/*
          main.cpp
Created by infinitydao@gmail.com 
            09/2013
*/

#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QMainWindow>
#include "ui_mainwindow.h"

//=========================================================================
class SEMainWindow : public QMainWindow, public Ui::MainWindow
{
  Q_OBJECT

public:
  SEMainWindow( QWidget *parent = 0, Qt::WindowFlags flags = 0 );
  ~SEMainWindow();
};

//=========================================================================

#endif
