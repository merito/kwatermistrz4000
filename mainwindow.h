#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QList>
#include <iterator>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
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

    void on_actionWczyt_dom_hotel_triggered();

private:
    Ui::MainWindow *ui;
    ModifyHotelWindow *mhWindow;
    QList<QLabel> floorLabels;
    void drawContent();
    QVBoxLayout *mainLayout;
};

#endif // MAINWINDOW_H
