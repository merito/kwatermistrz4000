#include "roombutton.h"

RoomButton::RoomButton(QWidget *parent) : QWidget(parent)
{
    keyComboBox->addItem(QIcon(":/resources/HOTEL_OWNED.gif"), tr("Ośrodek"));
    keyComboBox->addItem(QIcon(":/resources/NO_KEY.gif"), tr("Nie ma klucza"));
    keyComboBox->addItem(QIcon(":/resources/ON_DESK.gif"), tr("Przygotowany"));
    keyComboBox->addItem(QIcon(":/resources/STUFF.gif"), tr("Obsługa"));
    keyComboBox->addItem(QIcon(":/resources/GUEST.gif"), tr("Wydany"));
    keyComboBox->addItem(QIcon(":/resources/LOST.gif"), tr("Zgubiony"));
}

RoomButton::~RoomButton()
{

}
