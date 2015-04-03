#ifndef MODIFYHOTELWINDOW_H
#define MODIFYHOTELWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>

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

private:
    Ui::ModifyHotelWindow *ui;
    int floors;
    QLabel *labels;
    QLineEdit *lineEdits;
    QFormLayout *formLayout;
};

#endif // MODIFYHOTELWINDOW_H
