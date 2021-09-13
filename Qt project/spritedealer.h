#ifndef SPRITEDEALER_H
#define SPRITEDEALER_H

#include <QImage>


class SpriteDealer
{
public:
    SpriteDealer(int);
    QImage* getEnDown(int);
    QImage* getEnUp(int);
    QImage* getEnLeft(int);
    QImage* getEnRight(int);

    QImage* getAlDown(int);
    QImage* getAlUp(int);
    QImage* getAlLeft(int);
    QImage* getAlRight(int);

    QImage* getMeDown(int);
    QImage* getMeUp(int);
    QImage* getMeLeft(int);
    QImage* getMeRight(int);

    int getSize(){return size;}

private:
    QImage enDown0;
    QImage enDown1;
    QImage enDown2;
    QImage enDown3;
    QImage enLeft0;
    QImage enLeft1;
    QImage enLeft2;
    QImage enLeft3;
    QImage enUp0;
    QImage enUp1;
    QImage enUp2;
    QImage enUp3;
    QImage enRight0;
    QImage enRight1;
    QImage enRight2;
    QImage enRight3;

    QImage meDown0;
    QImage meDown1;
    QImage meDown2;
    QImage meDown3;
    QImage meLeft0;
    QImage meLeft1;
    QImage meLeft2;
    QImage meLeft3;
    QImage meUp0;
    QImage meUp1;
    QImage meUp2;
    QImage meUp3;
    QImage meRight0;
    QImage meRight1;
    QImage meRight2;
    QImage meRight3;

    QImage alDown0;
    QImage alDown1;
    QImage alDown2;
    QImage alDown3;
    QImage alLeft0;
    QImage alLeft1;
    QImage alLeft2;
    QImage alLeft3;
    QImage alUp0;
    QImage alUp1;
    QImage alUp2;
    QImage alUp3;
    QImage alRight0;
    QImage alRight1;
    QImage alRight2;
    QImage alRight3;

    QString relativePath;
    int size;
};

#endif // SPRITEDEALER_H
