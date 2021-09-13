#ifndef ALLY_H
#define ALLY_H

#include <npc.h>

class Ally: public NPC
{

public:
    Ally(Place*, int, int, SpriteDealer*, QGraphicsItem* parent=0);
    QRectF boundingRect() const;
    void paint(QPainter* painter,
    const QStyleOptionGraphicsItem* option,
    QWidget* widget);
    void step();

private:
    QRectF parBoundingRect;
};

#endif // ALLY_H
