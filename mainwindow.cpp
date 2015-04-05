#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNowy_triggered()
{
    mhWindow = new ModifyHotelWindow();
    mhWindow->show();

    drawContent();
}

void MainWindow::drawContent()
{
    QString windowTitle = QString("Kwatermistrz4000 - Ośrodek %1").
            arg(Hotel::getInstance().getName());
    setWindowTitle(windowTitle);

    QList<Floor>::iterator floorIterator;

    for(floorIterator=Hotel::getInstance().getFloors()->begin();
        floorIterator!=Hotel::getInstance().getFloors()->end();
        ++floorIterator){
        QString floorTitle = QString("Piętro %1").arg(
                    (*floorIterator).getName());
    }
}
