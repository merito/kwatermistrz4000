#ifndef MODIFYFLOORWINDOW_H
#define MODIFYFLOORWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>

namespace Ui {
class modifyfloorwindow;
}

class modifyfloorwindow : public QDialog
{
    Q_OBJECT

public:
    explicit modifyfloorwindow(QWidget *parent = 0);
    ~modifyfloorwindow();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::modifyfloorwindow *ui;
    int rooms;
    QLabel *labelsNames, *labelsPlaces;
    QLineEdit *lineEditsNames, *lineEditsPlaces;
    QFormLayout *formLayout;
};

#endif // MODIFYFLOORWINDOW_H
