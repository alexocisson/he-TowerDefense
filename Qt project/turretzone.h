#ifndef TURRETZONE_H
#define TURRETZONE_H
#include <QLabel>


class TurretZone : public QLabel
{

    Q_OBJECT

public:
    TurretZone(int, int, int, int);
        void mousePressEvent(QMouseEvent *ev) override;
signals:
    void clicked(QPoint, TurretZone*);


};

#endif // TURRETZONE_H
