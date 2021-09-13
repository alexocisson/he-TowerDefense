#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItemGroup>
#include <QPainter>
#include <QGraphicsView>
#include <place.h>
#include <spritedealer.h>


class Player : public QGraphicsItemGroup
{
public:
    Player(Place*, SpriteDealer*, int, int);
    void paint(QPainter* painter,
    const QStyleOptionGraphicsItem* option,
    QWidget* widget);
    QRectF boundingRect() const;
    double getMaxFocus(){return maxFocus;}
    double getFocus();
    QPointF getPosition(){return QPointF(this->x(),this->y());}
    void setFocus(double);
    void step();
    void updateSprite();
    void hasWon(){won=true;}
    void drinkCoffee(){coffeeTime+=1;}
    void useHeadPhones(){headPhonesTime+=1;}
    void updateCoffee();
    void updateHeadPhones();
    double getHeadPhonesTimeLeft(){return headPhonesTime/headPhonesTimeDecrement;} //combien de 200ms restantes
    double getCoffeBoost(){return coffeBoost*coffeeTime;}
    int getState(){return state;}
private:
    double focus;
    double maxFocus;
    int size;
    Place * place;
    QPointF pos; //position
    SpriteDealer* sd;
    int state=0;
    int spriteState=0;
    int spriteDir=3; //0 right, 1 up, 2 down, 3 left
    int mapWidth;
    int mapHeight;
    bool won=false;
    double coffeeTime=0;
    double coffeBoost;
    double headPhonesTime=0;
    double coffeeTimeDecrement;
    double headPhonesTimeDecrement;
    int fallCount;
};

#endif // PLAYER_H
