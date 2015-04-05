#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QList>
#include <iterator>
#include "modifyhotelwindow.h"
#include "hotel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNowy_triggered();

private:
    Ui::MainWindow *ui;
    ModifyHotelWindow *mhWindow;
    QList<QLabel> floorLabels;
    void drawContent();
};

#endif // MAINWINDOW_H
