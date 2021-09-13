#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QTimer>
#include <qmath.h> // qSin, qCos, qTan
#include "ennemy.h"
#include <QtDebug>

class Projectile: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Projectile(Enemy*, int, QGraphicsItem * parent=nullptr);

public slots:
    void move();
    double getMaxRange();
    double getDistanceTravelled();
    void setMaxRange(double rng);
    void setDistanceTravelled(double dist);
    void enemyShot();
    void destroyMeFunct();


signals:
    void destroyMe(Projectile*proj);
private:
    double maxRange;
    double distanceTravelled;
    QTimer * timer;
    Enemy * enemy;
    Enemy * pEnemy;
    bool noEnemy = false;
    int strength;

protected:
    QGraphicsRectItem * hitbox;
};

#endif // PROJECTILE_H
