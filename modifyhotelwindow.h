#ifndef MODIFYHOTELWINDOW_H
#define MODIFYHOTELWINDOW_H

#include <QDialog>

namespace Ui {
class ModifyHotelWindow;
}

class ModifyHotelWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyHotelWindow(QWidget *parent = 0);
    ~ModifyHotelWindow();

private:
    Ui::ModifyHotelWindow *ui;
};

#endif // MODIFYHOTELWINDOW_H
