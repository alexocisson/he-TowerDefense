#include "clicklabel.h"

ClickLabel::ClickLabel(int w, int h)
{
    this->w=w;
    this->h=h;
    setGeometry(0, 0, 48*(w/280),h/19);
    setAttribute(Qt::WA_TranslucentBackground);
}


void ClickLabel::paintEvent(QPaintEvent* event)
{

}
void ClickLabel::makeBig()
{
    isBig=true;
    setGeometry(0, -h/2, w,h);
}
void ClickLabel::makeSmall()
{
    isBig=false;
    setGeometry(0, -h/2, 48*(w/280),h/19);
}


void ClickLabel::mousePressEvent(QMouseEvent *ev)
{
    emit clicked();
}
