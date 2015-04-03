#include "modifyhotelwindow.h"
#include "ui_modifyhotelwindow.h"

ModifyHotelWindow::ModifyHotelWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyHotelWindow)
{
    ui->setupUi(this);
}

ModifyHotelWindow::~ModifyHotelWindow()
{
    delete ui;
}
