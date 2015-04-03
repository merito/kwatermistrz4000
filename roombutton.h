#ifndef ROOMBUTTON_H
#define ROOMBUTTON_H

#include <QWidget>
#include "room.h"
#include "ui_roombutton.h"

namespace Ui {
class RoomButton;
}

class RoomButton : public QWidget
{
    Q_OBJECT
public:
    explicit RoomButton(QWidget *parent = 0);
    ~RoomButton();

signals:

public slots:

private slots:

private:
    Ui::RoomButton *ui;
    QComboBox *keyComboBox = new QComboBox;
};

#endif // ROOMBUTTON_H
