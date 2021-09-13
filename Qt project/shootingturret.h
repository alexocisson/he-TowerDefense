#ifndef SHOOTINGTURRET_H
#define SHOOTINGTURRET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include "projectile.h"
#include <QPointF>
#include <QLineF>
#include <QTimer>
#include <QGraphicsRectItem>
#include "ennemy.h"
#include <QDebug>
#include <QPushButton>
#include "projectile.h"



class ShootingTurret: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    ShootingTurret(QPoint,QGraphicsItem * parent= nullptr);
    double distanceTo(QGraphicsItem * item);
    virtual void fire();
    void decTimeToLive();
    void destroyMeFunct();
    void getMyPosition();
    void upGrade();
    QVariant itemChange(GraphicsItemChange, const QVariant&);

private:


signals:

    void addProjectile(Projectile *);
    void destroyMe(ShootingTurret *);
    void myPosition(QPoint);
    void showUpgradeButton(ShootingTurret*);
    void hideUpgradeButton(ShootingTurret*);

public slots:
    void aquire_target();

protected:
    QGraphicsEllipseItem * attack_area;
    Enemy * enemy_dest;
    bool has_target;
    int timeToLive;
    int size;
    bool selected;
    QPushButton* upgrade;
    int circleRad;
    int lvl=0;
    int projectileStrength;
};

#endif // SHOOTINGTURRET_H
