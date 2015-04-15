#include "searchwindow.h"
#include "ui_searchwindow.h"

searchWindow::searchWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":resources/icon.png"));
}

searchWindow::~searchWindow()
{
    delete ui;
}

void searchWindow::on_buttonBox_accepted()
{
    QLineEdit *nameEdit = findChild<QLineEdit *>("lineEdit");
    QString nameToSearch =  nameEdit->text();
    emit searchName(nameToSearch);
}
