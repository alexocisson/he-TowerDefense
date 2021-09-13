#include "ennemy.h"
#include <cmath>

Enemy::Enemy(Place * place, int lvl, int mapWidth, SpriteDealer* sd, QGraphicsItem* parent)
    : NPC(lvl, sd, parent)

{
    this->place=place;
    this->mapWidth=mapWidth;
    if(place->getPos().y()<0)
        vectorY=false;
    if(place&&place->getNumber()%2==0)
    {
        vectorx=false;
    }
    parBoundingRect = QRectF(-size/2, -size/2, size, size);
    maxHp=180*lvl;
    hp=maxHp;
    state=0;
    pos=QPointF(-size/2,-(2/3)*size); //position
    this->setX(pos.x());
    this->setY(pos.y());
    name="Raj";
    strength=90*lvl;
    speed=0.3/lvl;
    if (place->getNumber()==-1)
        placeIsFree=true;
}


QRectF Enemy::boundingRect() const
{

return parBoundingRect;

}

void Enemy::paint( QPainter* painter,
const QStyleOptionGraphicsItem*, QWidget*)
{
    /*
    painter->setPen( QPen( Qt::red, 1 ) );
    painter->drawLine(-size/2,-size/2,size/2,-size/2);
    painter->drawLine(-size/2,size/2,size/2,size/2);
    painter->drawLine(-size/2,-size/2,-size/2,size/2);
    painter->drawLine(size/2,-size/2,size/2,size/2);
    */
    painter->setPen( QPen( Qt::red, 1 ) );
    painter->drawLine(-size/2,-size/2+5,size/2,-size/2+5);
    painter->drawLine(-size/2,-size/2+4,size/2,-size/2+4);
    painter->setPen( QPen( Qt::green, 1 ) );
    double hpSize=(hp/maxHp)*size;
    painter->drawLine(-size/2,-size/2+5,(-size/2)+hpSize,-size/2+5);
    painter->drawLine(-size/2,-size/2+4,(-size/2)+hpSize,-size/2+4);

    if(state==3)
    {
        if(spriteDir==0)
            painter->drawImage(QPoint(-size/2,-size/2), *sd->getEnRight(0));
        else
            painter->drawImage(QPoint(-size/2,-size/2), *sd->getEnLeft(0));
    }
    else
    {
        switch(spriteDir)
        {
            case 0:
                {
                painter->drawImage(QPoint(-size/2,-size/2), *sd->getEnRight(spriteState));
                break;
                }
            case 1:
                {
                painter->drawImage(QPoint(-size/2,-size/2), *sd->getEnUp(spriteState));
                break;
                }
            case 2:
                {
                painter->drawImage(QPoint(-size/2,-size/2), *sd->getEnDown(spriteState));
                break;
                }
            case 3:
                {
                painter->drawImage(QPoint(-size/2,-size/2), *sd->getEnLeft(spriteState));
                break;
                }
        }
    }


}

void Enemy::step()
{
    update();
    switch (state)
    {
        case 0:
        {
            spriteDir=0;
            pos.setX(pos.x()+speed);
            this->setX(pos.x());
            if(hp==0)
            {
                if(!placeIsFree)
                {
                    placeIsFree=true;
                    place->free();
                }
                state=9;
            }
            if(place->getNumber()!=-1)
            {
                if(vectorx)
                {
                    if(place->x()-pos.x()<size/2)
                        state=1;
                }
                else
                {
                    if(pos.x()-place->x()>size/2)
                        state=1;
                }
            }
            else
            {
                //Verifier si on est arriver au bout
                if(pos.x()>size/2+mapWidth)
                    state=8;
            }

            break;
        }
        case 1:
        {
            if(hp==0)
            {
                if(!placeIsFree)
                {
                    placeIsFree=true;
                    place->free();
                }
                state=5;
            }
            if(vectorY)
            {
                spriteDir=2;
                pos.setY(pos.y()+speed);
                this->setY(pos.y());
                if(place->y()-pos.y()<0)
                    state=2;
            }
            else
            {
                spriteDir=1;
                pos.setY(pos.y()-speed);
                this->setY(pos.y());
                if(place->y()-pos.y()>0)
                    state=2;
            }
            break;
        }
        case 2:
        {
            if(hp==0)
            {
                state=4;
            }
            if(vectorx)
            {
                spriteDir=0;
                pos.setX(pos.x()+speed/2);
                this->setX(pos.x());
                if(place->x()-pos.x()<0)
                    state=3;
            }
            else
            {
                spriteDir=3;
                pos.setX(pos.x()-speed/2);
                this->setX(pos.x());
                if(place->x()-pos.x()>0)
                    state=3;
            }
            break;
        }
        case 3:
        {
            if(hp==0)
            {
                state=4;
            }
            break;
        }
        case 4:
        {
            if(vectorx)
            {
                spriteDir=0; //3
                pos.setX(pos.x()-speed/2);
                this->setX(pos.x());
                if(place->x()-pos.x()>size/2)
                {
                    state=5;

                    if(!placeIsFree)
                    {
                        placeIsFree=true;
                        place->free();
                    }
                }
            }
            else
            {
                spriteDir=3; //0
                pos.setX(pos.x()+speed/2);
                this->setX(pos.x());
                if(pos.x()-place->x()>size/2)
                {
                    state=5;
                    if(!placeIsFree)
                    {
                        placeIsFree=true;
                        place->free();
                    }
                }
            }
            break;
        }
        case 5:
        {
            if(vectorY)
            {
                spriteDir=1;
                pos.setY(pos.y()-speed);
                this->setY(pos.y());
                if(pos.y()<(3/2)*size)
                    state=6;
            }
            else
            {
                spriteDir=2;
                pos.setY(pos.y()+speed);
                this->setY(pos.y());
                if(pos.y()>(3/2)*size)
                    state=6;
            }
            break;
        }
        case 6:
        {
            spriteDir=3;
            pos.setX(pos.x()-speed);
            this->setX(pos.x());
            if(pos.x()<-size/2)
                state=7;
            break;
        }
        case 7:
        {
            //is dead
            out=true;
            break;
        }
        case 8:
        {
            //has crossed the hallway
            out=true;
            break;
        }
        case 9:
        {
            //dead en route
            spriteDir=2;
            pos.setY(pos.y()+speed);
            this->setY(pos.y());
            if(pos.y()>(3/2)*size)
                state=6;
        }

    }
}

double Enemy::noise(QPointF posPlayer)
{
    double distance = sqrt(pow(posPlayer.x()-this->x(), 2)+pow(posPlayer.y()-this->y(), 2));
    return strength/distance;
}

