#ifndef MODIFYROOMWINDOW_H
#define MODIFYROOMWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class ModifyRoomWindow;
}

class ModifyRoomWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyRoomWindow(QWidget *parent = 0);
    ~ModifyRoomWindow();

    QLineEdit *getLineEdits();
    void setLineEdits(QLineEdit *value);

private:
    Ui::ModifyRoomWindow *ui;
    QLineEdit *lineEdits;
};

#endif // MODIFYROOMWINDOW_H
