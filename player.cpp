#include "player.h"

Player::Player(Place * place, SpriteDealer * sd, int mapWidth, int mapHeight)
{
    this->place=place;
    this->sd=sd;
    size=40;
    maxFocus=100;
    focus=maxFocus;
    this->setX(place->x());
    this->setY(place->y());
    pos.setX(place->x());
    pos.setY(place->y());
    this->mapWidth=mapWidth;
    this->mapHeight=mapHeight;
    coffeBoost=25;
    coffeeTimeDecrement=0.008;
    headPhonesTimeDecrement=0.01;
    fallCount=500;
}

QRectF Player::boundingRect() const
{

return QRectF(-size/2, -size/2, size, size);

}

void Player::paint( QPainter* painter,
const QStyleOptionGraphicsItem*, QWidget*)
{
    /*
    painter->setPen( QPen( Qt::black, 1 ) );
    painter->drawLine(-size/2,-size/2,size/2,-size/2);
    painter->drawLine(-size/2,size/2,size/2,size/2);
    painter->drawLine(-size/2,-size/2,-size/2,size/2);
    painter->drawLine(size/2,-size/2,size/2,size/2);
*/
    if(state==0)
    {
        painter->drawImage(QPoint(-size/2,-size/2), *sd->getMeLeft(0));
    }
    else if (state!=6)
    {
        switch(spriteDir)
        {
            case 0:
                {
                painter->drawImage(QPoint(-size/2,-size/2), *sd->getMeRight(spriteState));
                break;
                }
            case 1:
                {
                painter->drawImage(QPoint(-size/2,-size/2), *sd->getMeUp(spriteState));
                break;
                }
            case 2:
                {
                painter->drawImage(QPoint(-size/2,-size/2), *sd->getMeDown(spriteState));
                break;
                }
            case 3:
                {
                painter->drawImage(QPoint(-size/2,-size/2), *sd->getMeLeft(spriteState));
                break;
                }
        }
    }
}
void Player::setFocus(double focus)
{
    if(focus>=0)
        this->focus=focus;
    else
        this->focus=0;
}


void Player::step()
{
    update();
    switch (state)
    {
        case 0:
        {
            pos.setX(pos.x()+0.2);
            this->setX(pos.x());
            if(pos.x()-place->x()>size/2)
                state=1;
            break;
        }
        case 1:
        {

                spriteDir=2;
                pos.setY(pos.y()+0.25);
                this->setY(pos.y());
                if(pos.y()>0)
                    state=2;
            break;
        }
        case 2:
        {
                spriteDir=3;
                pos.setX(pos.x()-0.1);
                this->setX(pos.x());
                if(pos.x()<mapWidth/2)
                {
                    if(won)
                        state=3;
                    else
                        state=4;
                }
            break;
        }
        case 3:
        {
            spriteDir=2;
            if(spriteState>1)
            {
                pos.setX(pos.x()+0.1);
                this->setX(pos.x());
                if(spriteState==2)
                {
                    pos.setY(pos.y()-0.05);
                    this->setY(pos.y());
                }
                else
                {
                    pos.setY(pos.y()+0.05);
                    this->setY(pos.y());
                }
            }
            else
            {
                pos.setX(pos.x()-0.1);
                this->setX(pos.x());
                if(spriteState==0)
                {
                    pos.setY(pos.y()-0.05);
                    this->setY(pos.y());
                }
                else
                {
                    pos.setY(pos.y()+0.05);
                    this->setY(pos.y());
                }
            }
            break;
        }
    case 4:
    {
        spriteDir=1;
        pos.setY(pos.y()-0.4);
        this->setY(pos.y());
        if(pos.y()<-(mapHeight/2)+(size/2))
            state=5;
        break;
    }
    case 5:
    {
        fallCount--;
        if(fallCount<0)
            state=6;
    }

    }
}

void Player::updateSprite()
{
        spriteState++;
        if(spriteState>3)
            spriteState=0;
}

void Player::updateCoffee()
{
    if(coffeeTime>0)
        coffeeTime-=coffeeTimeDecrement;
}


void Player::updateHeadPhones()
{
    if(headPhonesTime>0)
        headPhonesTime-=headPhonesTimeDecrement;
}


double Player::getFocus()
{
    if(headPhonesTime>0)
        return maxFocus+coffeeTime*coffeBoost;
    return focus+coffeeTime*coffeBoost;
}
