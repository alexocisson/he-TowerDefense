#ifndef ENNEMY_H
#define ENNEMY_H

#include <npc.h>

class Enemy : public NPC
{

public:
    Enemy(Place*, int, int, SpriteDealer*, QGraphicsItem* parent=0);
    QRectF boundingRect() const;
    void paint(QPainter* painter,
    const QStyleOptionGraphicsItem* option,
    QWidget* widget);
    void step();
    double noise(QPointF);
    int getLvl(){return lvl;}


private:
    QRectF parBoundingRect;
    QImage scaledImage;



};

#endif // ENNEMY_H
