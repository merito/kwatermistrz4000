#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QList>
#include <iterator>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "modifyhotelwindow.h"
#include "hotel.h"
#include "floor.h"
#include "room.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString getFileName() const;
    void setFileName(const QString &value);

private slots:
    void on_actionNowy_triggered();

    void on_actionWczyt_dom_hotel_triggered();

    void on_actionZapisz_jako_triggered();

    void on_actionZapisz_triggered();

    void on_actionZako_cz_triggered();

    void on_actionOtw_rz_triggered();

private:
    Ui::MainWindow *ui;
    ModifyHotelWindow *mhWindow;
    QList<QLabel> floorLabels;
    void drawContent();
    QVBoxLayout *mainLayout;
    QString fileName;
    int toTextFile(QFile *file);
};

#endif // MAINWINDOW_H
