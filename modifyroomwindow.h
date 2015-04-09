#ifndef MODIFYROOMWINDOW_H
#define MODIFYROOMWINDOW_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class ModifyRoomWindow;
}

class ModifyRoomWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyRoomWindow(QWidget *parent = 0);
    ~ModifyRoomWindow();

private:
    Ui::ModifyRoomWindow *ui;
};

#endif // MODIFYROOMWINDOW_H
