#include "place.h"

Place::Place(QPoint pos, int number, QGraphicsItem* parent)
{
    size=20;
    this->pos=pos;
    this->setX(pos.x());
    this->setY(pos.y());
    parBoundingRect = QRectF(-size/2, -size/2, size, size);
    this->number=number;
    setFlag(QGraphicsItem::ItemIsSelectable);
}

Place::Place(QGraphicsItem* parent)
{
    size=20;
    this->number=-1;
    this->pos=QPoint(-size,0);
    this->setX(pos.x());
    this->setY(pos.y());
    parBoundingRect = QRectF(-size/2, -size/2, size, size);
}

void Place::paint( QPainter* painter,
const QStyleOptionGraphicsItem*, QWidget*)
{
    /*
    painter->setPen( QPen( Qt::black, 1 ) );
    painter->drawLine(-size/2,-size/2,-size/2,size/2);
    painter->drawLine(-size/2,size/2,size/2,size/2);
    painter->drawLine(-size/2,-size/2,-size/2,size/2);
    painter->drawLine(size/2,-size/2,size/2,size/2);
    */
    if(isSelected()&&!npcFlag)
    {
        painter->drawEllipse(-size/2, -size/2, size, size);
    }
    if(numberFlag)
    {
        painter->setPen(QColor(Qt::red));
        painter->drawText(size/2+2, 2,QString("%1").arg(number));
    }
}

QRectF Place::boundingRect() const
{

    return parBoundingRect;

}

void Place::setNPC(bool hasNPC)
{
    npcFlag=hasNPC;
    if(hasNPC)
        setSelected(false);
}

void Place::showNumber(bool b)
{
    numberFlag = b;
    update();
}
