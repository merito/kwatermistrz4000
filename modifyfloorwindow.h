#ifndef MODIFYFLOORWINDOW_H
#define MODIFYFLOORWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include "hotel.h"
#include "room.h"

namespace Ui {
class modifyfloorwindow;
}

class modifyfloorwindow : public QDialog
{
    Q_OBJECT

public:
    explicit modifyfloorwindow(QWidget *parent = 0);
    ~modifyfloorwindow();

    int getRooms() const;
    void setRooms(int value);

private slots:

    void on_buttonBox_accepted();

private:
    Ui::modifyfloorwindow *ui;
    int rooms;
    QLabel *labelsNames, *labelsPlaces;
    QLineEdit *lineEditsNames, *lineEditsPlaces;
    QFormLayout *formLayout;
};

#endif // MODIFYFLOORWINDOW_H
