/*              newmapdialog.h
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#ifndef __NEWMAPDIALOG_H__
#define __NEWMAPDIALOG_H__

#include <QDialog>
#include "ui_newdialog.h"

//=========================================================================
class NewMapDialog : public QDialog, Ui::Dialog
{
  Q_OBJECT

public:
  NewMapDialog( QWidget *parent = 0, Qt::WindowFlags flags = 0 );
  ~NewMapDialog();
};

//=========================================================================

#endif //__NEWMAPDIALOG_H__
