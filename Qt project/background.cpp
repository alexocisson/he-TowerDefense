#include "background.h"

Background::Background(int w, int h)
{
    relativePath = QString(":/graphics/graphics/");
    QImage image= QImage(relativePath+"background5.png");
    background = image.scaled(QSize(w, h));
    this->w=w;
    this->h=h;
    this->setX(0);
    this->setY(-h/2);
}

QRectF Background::boundingRect() const
{

return QRectF(0, 0, w, h);

}

void Background::paint( QPainter* painter,
const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->drawImage(QPoint(0,0), background);
}

void Background::victory()
{
    QImage image= QImage(relativePath+"backgroundvictory5.png");
    background = image.scaled(QSize(w, h));
    update();
}

void Background::breackWall()
{
    QImage image= QImage(relativePath+"backgroundbreack5.png");
    background = image.scaled(QSize(w, h));
    update();
}

void Background::normal()
{
    QImage image= QImage(relativePath+"background5.png");
    background = image.scaled(QSize(w, h));
    update();
}

void Background::pause()
{

    QImage image = QImage(relativePath+"pause.png");
    background = image.scaled(QSize(w, h));
    update();
}
