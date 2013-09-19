/*             newgamedialog.h
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#ifndef __NEWGAMEDIALOG_H__
#define __NEWGAMEDIALOG_H__

#include <QDialog>
#include "ui_newgamedialog.h"

//=========================================================================
class NewGameDialog : public QDialog, public Ui::Dialog
{
  Q_OBJECT

public:
  NewGameDialog( QWidget *parent = 0, Qt::WindowFlags flags = 0 );
  ~NewGameDialog();
};

//=========================================================================

#endif //__NEWGAMEDIALOG_H__
