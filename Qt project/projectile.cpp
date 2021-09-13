
#include "projectile.h"



Projectile::Projectile(Enemy*enemy, int strength,QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    // set graphics

    setPixmap(QPixmap(":/graphics/graphics/projectile.png"));
    this->strength=strength;
    this->setScale(0.2+0.02*  (strength/10)  );
    this->enemy=enemy;

    // initialize values
    maxRange = 3000;
    distanceTravelled = 0;


    // connect a timer to enemyShot
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(enemyShot()));
    timer->start(50);
}

void Projectile::move(){
    double STEP_SIZE = 1;
    if(enemy->isDead())
        noEnemy=true;
    if(enemy!=nullptr&&!noEnemy)
    {
        QLineF ln(this->pos(),QPointF(enemy->getPosition()));
        int angle = -1 * ln.angle();
        this->setRotation(angle);
    }

    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));
    setPos(x()+dx, y()+dy);
    distanceTravelled++;
    if (distanceTravelled>maxRange)
        emit destroyMe(this);
}

double Projectile::getMaxRange(){
    return maxRange;
}

double Projectile::getDistanceTravelled(){
    return distanceTravelled;
}

void Projectile::setMaxRange(double rng){
    maxRange = rng;
}

void Projectile::setDistanceTravelled(double dist){
    distanceTravelled = dist;
}

void Projectile::enemyShot()
{
    QList<QGraphicsItem *> colliding_items =  this->collidingItems();
    foreach (QGraphicsItem * item, colliding_items)
    {
        // make sure it is an enemy
        pEnemy = dynamic_cast<Enemy*>(item);
        if(pEnemy!=nullptr)
        {
            pEnemy->getDamage(strength);
            emit destroyMe(this);
        }
        else
        {
        }
    }
}

void Projectile::destroyMeFunct()
{
    emit destroyMe(this);
}

