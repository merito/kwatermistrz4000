#ifndef FLOORBUTTON_H
#define FLOORBUTTON_H

#include <QWidget>
#include "ui_floorbutton.h"

namespace Ui {
class FloorButton;
}

class FloorButton : public QWidget
{
    Q_OBJECT
public:
    explicit FloorButton(QWidget *parent = 0);
    ~FloorButton();

signals:

public slots:

private slots:

private:
    Ui::FloorButton *ui;
};

#endif // FLOORBUTTON_H
