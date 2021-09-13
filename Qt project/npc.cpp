#include "npc.h"
#include <QDebug>

NPC::NPC(int lvl, SpriteDealer * sd, QGraphicsItem* parent)
    : QGraphicsItemGroup(parent)
{
    this->sd=sd;
    this->size=sd->getSize();
    this->lvl=lvl;
    spriteDir=0;
    spriteState=0;
}

void NPC::setPlace(Place * place)
{
    this->place = place;
    if(place->getNumber()%2==0)
    {
        vectorx=false;
    }
}

void NPC::getDamage(int damage)
{
    hp=hp-damage;
    if (hp<0)
        hp=0;
}

double NPC::damage(QPointF posEnemy)
{
    double distance = sqrt(pow(posEnemy.x()-this->x(), 2)+pow(posEnemy.y()-this->y(), 2));
    return strength/distance;
}

void NPC::updateSprite()
{
    spriteState++;
    if(spriteState>3)
        spriteState=0;
}

void NPC::kill()
{
    hp=0;
}
