/*                main.cpp
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#include <QApplication>
#include "mainwindow.h"

int main( int argc, char *argv[] )
{
  QApplication app(argc, argv);
  MainWindow wnd;
  wnd.show();
  return app.exec();
}
