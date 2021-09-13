#ifndef PLACE_H
#define PLACE_H

#include <QGraphicsItemGroup>
#include <QPaintDevice>
#include <QPoint>
#include <QRectF>
#include <QPainter>


class Place : public QGraphicsItemGroup
{
public:
    Place(QPoint, int, QGraphicsItem* parent=0);
    Place(QGraphicsItem* parent=0);
    void paint(QPainter* painter,
        const QStyleOptionGraphicsItem* option,
        QWidget* widget);
    QRectF boundingRect() const;
    void setNPC(bool);
    bool hasNPC(){return npcFlag;}
    QPointF getPos(){return pos;}
    int getNumber(){return number;}
    void free(){npcFlag=false;}
    bool isIn(QPointF);
    void showNumber(bool);

private:
    QPoint pos;
    QRectF parBoundingRect;
    int size;
    bool npcFlag=false;
    bool numberFlag=false;
    int number;
};

#endif // PLACE_H
