#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QDialog>

namespace Ui {
class searchWindow;
}

class searchWindow : public QDialog
{
    Q_OBJECT

public:
    explicit searchWindow(QWidget *parent = 0);
    ~searchWindow();

signals:
    void searchName(QString name);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::searchWindow *ui;
};

#endif // SEARCHWINDOW_H
