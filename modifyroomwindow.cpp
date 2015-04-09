#include "modifyroomwindow.h"
#include "ui_modifyroomwindow.h"

ModifyRoomWindow::ModifyRoomWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyRoomWindow)
{
    ui->setupUi(this);
}

ModifyRoomWindow::~ModifyRoomWindow()
{
    delete ui;
}
