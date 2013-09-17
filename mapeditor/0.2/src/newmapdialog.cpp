/*              newmapdialog.cpp
      created by infinitydao@gmail.com
                  09/2013
          General Publing License v 2.0
*/

#include "newmapdialog.h"

//-------------------------------------------------------------------------
NewMapDialog::NewMapDialog( QWidget *parent /* = 0 */, Qt::WindowFlags flags /* = 0 */ )
:QDialog(parent,flags)
{
  setupUi(this);
}

//-------------------------------------------------------------------------
NewMapDialog::~NewMapDialog()
{

}

//-------------------------------------------------------------------------
QString NewMapDialog::fileName()const
{
  return lineEdit_3->text();
}

//-------------------------------------------------------------------------
QString NewMapDialog::Width()const
{
  return lineEdit->text();
}

//-------------------------------------------------------------------------
QString NewMapDialog::Height()const
{
  return lineEdit_2->text();
}

//-------------------------------------------------------------------------
