#include "turretzone.h"
#include <QMouseEvent>

TurretZone::TurretZone(int x, int y, int w, int h)
{
    setGeometry(x, y, w, h);
    setStyleSheet("background-color: rgba(255,10,10,10%)");
}

void TurretZone::mousePressEvent(QMouseEvent *ev)
{
    emit clicked(ev->pos(), this);
}
