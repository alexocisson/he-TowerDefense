#ifndef CLICKLABEL_H
#define CLICKLABEL_H
#include <QLabel>
#include <QPainter>

class ClickLabel : public QLabel
{

    Q_OBJECT

public:
    ClickLabel(int, int);
    void mousePressEvent(QMouseEvent *ev) override;
    void paintEvent(QPaintEvent* event) override;
    void makeBig();
    void makeSmall();

signals:
    void clicked();

private:
    bool isBig=false;
    int w;
    int h;

};

#endif // CLICKLABEL_H
