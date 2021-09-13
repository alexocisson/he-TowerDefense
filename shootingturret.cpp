#include "shootingturret.h"



ShootingTurret::ShootingTurret(QPoint p, QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/graphics/graphics/turretlvl1.png"));

    lvl=0;
    projectileStrength=8;
    timeToLive=40;
    size=35;
    circleRad=200;
    this->setPos(p.x()-size/2, p.y()-size/2);

    // create the QGraphicsPolygonItem
    attack_area = new QGraphicsEllipseItem(-circleRad+size/2,-circleRad+size/2,2*circleRad,2*circleRad,this);
    attack_area->setPen(QPen(QColor(0xFF, 0, 0, 0x00)));

    // set attack_dest
    has_target = false;
    setFlag(QGraphicsItem::ItemIsSelectable);
    selected=isSelected();

}

double ShootingTurret::distanceTo(QGraphicsItem *item){
    // returns the distance to the item

    QLineF ln(this->pos(),item->pos());
    return ln.length();
}

void ShootingTurret::fire(){

    Projectile * projectile = new Projectile(enemy_dest, projectileStrength);
    projectile->setPos(x()+size/2,y()+size/2);
    QLineF ln(QPointF(x(),y()),QPointF(enemy_dest->getPosition()));
    int angle = -1 * ln.angle();

    projectile->setRotation(angle);

    emit addProjectile(projectile);

}

void ShootingTurret::aquire_target(){
    // get a list of all enemies that collide with attack_area, find the closest one
    // and set it's position as the attack_dest

    // get a list of all enemies within attack_area

    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();


    // assume ShootingTurret does not have a target, unless we find one
    has_target = false;

    // find the closest Enemy
    double closest_dist = 3000;
    QPointF closest_pt(0,0);
    Enemy * enemy;
    foreach (QGraphicsItem * item, colliding_items) {
        Enemy * pEnemy = dynamic_cast<Enemy *>(item);
        if (pEnemy){
            double this_dist = distanceTo(item);
            if (this_dist < closest_dist&&!pEnemy->isDead()){
                closest_dist = this_dist;
                enemy = pEnemy;
                has_target = true;
            }
        }
    }

    // if has target, set the closest enemy as the attack_dest, and fire
    if (has_target){
        enemy_dest = enemy;
        fire();
    }
}

void ShootingTurret::decTimeToLive()
{
    timeToLive--;
    if(timeToLive==0)
    {
        if(this->isSelected())
            emit hideUpgradeButton(this);
        emit destroyMe(this);
    }
    else if (timeToLive<12)
    {
        setPixmap(QPixmap(":/graphics/graphics/turretdead.png"));
    }
    else
    {
         setPixmap(QPixmap(QString(":/graphics/graphics/turretlvl%1.png").arg((lvl/5)+1)));
    }
}

void ShootingTurret::destroyMeFunct()
{
    if(this->isSelected())
        emit hideUpgradeButton(this);
    emit destroyMe(this);
}


void ShootingTurret::getMyPosition()
{
    emit myPosition(QPoint(this->pos().x(),this->pos().y()));
}

QVariant ShootingTurret::itemChange(GraphicsItemChange change, const QVariant &value)
{
            if (change == ItemSelectedChange)
            {
                selected=isSelected();
                if(!selected)
                {
                    attack_area->setPen(QPen(QColor(0xDD, 0, 0xFF, 0x30), 3));
                    attack_area->update();
                    emit showUpgradeButton(this);
                }
                else
                {
                    attack_area->setPen(QPen(QColor(0xFF, 0, 0, 0x00)));
                    attack_area->update();
                    emit hideUpgradeButton(this);
                }
            }

    return QGraphicsItem::itemChange(change, value);
}

void ShootingTurret::upGrade()
{
    if(lvl<14)
        lvl++;
    projectileStrength+=2;
    timeToLive+=30;
    setPixmap(QPixmap(QString(":/graphics/graphics/turretlvl%1.png").arg((lvl/5)+1)));
    attack_area->setRect(-circleRad+size/2-20*lvl,-circleRad+size/2-20*lvl,2*circleRad+40*lvl,2*circleRad+40*lvl);
}
