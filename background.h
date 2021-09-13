#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <QImage>
#include <QGraphicsItemGroup>
#include <QPainter>

class Background : public QGraphicsItemGroup
{
public:
    Background(int, int);
    QRectF boundingRect() const;
    void paint(QPainter* painter,
    const QStyleOptionGraphicsItem* option,
    QWidget* widget);
    void victory();
    void breackWall();
    void normal();
    void pause();
private:
    QImage background;
    int w;
    int h;
    QString relativePath;
};

#endif // BACKGROUND_H
