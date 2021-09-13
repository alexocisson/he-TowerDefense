#ifndef NPC_H
#define NPC_H

#include <QGraphicsItemGroup>
#include <QPainter>
#include <QGraphicsView>
#include <QPointF>
#include <place.h>
#include <QtMath>
#include <spritedealer.h>
#include <QTimer>

class NPC : public QGraphicsItemGroup
{

public:
    NPC(int, SpriteDealer*, QGraphicsItem* parent=0);
    double damage(QPointF);
    void getDamage(int);
    int getSize(){return size;}
    Place * getPlace(){return place;}
    QPointF getPosition(){return pos;}
    bool isOut(){return out;}
    bool isDead(){return hp==0;}
    void setPlace(Place *);
    void updateSprite();
    void kill();

protected:
    double hp;
    int state;
    QPointF pos; //position
    Place * place;
    //Infos infos;
    bool showInfos = false;
    QString name;
    double strength;
    double maxHp;
    double speed; //px/ms
    int size;
    int lvl;
    int mapWidth;
    bool vectorY=true; //true +, false -
    bool vectorx=true;
    bool out=false;
    SpriteDealer* sd;
    int spriteState;
    int spriteDir; //0 right, 1 up, 2 down, 3 left
    bool placeIsFree=false;


};
#endif // NPC_H
