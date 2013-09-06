/*
          main.cpp
Created by infinitydao@gmail.com 
            09/2013
*/

#include <QApplication>
#include "mainwindow.h"

int main( int argc, char *argv[] )
{
  QApplication app( argc, argv );
  SEMainWindow SEWindow;
  SEWindow.show();
  return app.exec();
}

