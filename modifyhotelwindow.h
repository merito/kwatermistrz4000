#ifndef MODIFYHOTELWINDOW_H
#define MODIFYHOTELWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include "hotel.h"
#include "modifyfloorwindow.h"

namespace Ui {
class ModifyHotelWindow;
}

class ModifyHotelWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyHotelWindow(QWidget *parent = 0);
    ~ModifyHotelWindow();

private slots:
    void on_buttonBox_accepted();
    void on_lineEdit_textChanged(const QString &arg1);
    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    Ui::ModifyHotelWindow *ui;
    int floors;
    QString name;
    QLabel *labelsNames, *labelsRooms;
    QLineEdit *lineEditsNames, *lineEditsRooms;
    QFormLayout *formLayout;
    modifyfloorwindow *mfWindow;
};

#endif // MODIFYHOTELWINDOW_H
