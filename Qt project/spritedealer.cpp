#include "spritedealer.h"
#include <QDir>
#include <QDebug>
#include <QUrl>

SpriteDealer::SpriteDealer(int size)
{    
    this->size=size;
    QImage image;
    //relativePath = QString("./../graphics/");
    relativePath = QString(":/graphics/graphics/");

    //enemy0 (right)
    image= QImage(relativePath+"joydown0.png");
    enDown0 = image.scaled(QSize(size, size));
    image= QImage(relativePath+"joyup0.png");
    enUp0 = image.scaled(QSize(size, size));
    image= QImage(relativePath+"joyleft0.png");
    enLeft0 = image.scaled(QSize(size, size));
    image= QImage(relativePath+"joyright0.png");
    enRight0 = image.scaled(QSize(size, size));

    //enemy1 (up)
    image = QImage(relativePath+"joydown1.png");
    enDown1 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"joyup1.png");
    enUp1 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"joyleft1.png");
    enLeft1 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"joyright1.png");
    enRight1 = image.scaled(QSize(size, size));

    //enemy2 (down)
    image = QImage(relativePath+"joydown2.png");
    enDown2 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"joyup2.png");
    enUp2 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"joyleft2.png");
    enLeft2 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"joyright2.png");
    enRight2 = image.scaled(QSize(size, size));

    //enemy3 (left)
    image = QImage(relativePath+"joydown3.png");
    enDown3 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"joyup3.png");
    enUp3 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"joyleft3.png");
    enLeft3 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"joyright3.png");
    enRight3 = image.scaled(QSize(size, size));


    //ally0 (right)
    image= QImage(relativePath+"boydown0.png");
    alDown0 = image.scaled(QSize(size, size));
    image= QImage(relativePath+"boyup0.png");
    alUp0 = image.scaled(QSize(size, size));
    image= QImage(relativePath+"boyleft0.png");
    alLeft0 = image.scaled(QSize(size, size));
    image= QImage(relativePath+"boyright0.png");
    alRight0 = image.scaled(QSize(size, size));

    //ally1 (up)
    image = QImage(relativePath+"boydown1.png");
    alDown1 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"boyup1.png");
    alUp1 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"boyleft1.png");
    alLeft1 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"boyright1.png");
    alRight1 = image.scaled(QSize(size, size));

    //ally2 (down)
    image = QImage(relativePath+"boydown2.png");
    alDown2 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"boyup2.png");
    alUp2 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"boyleft2.png");
    alLeft2 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"boyright2.png");
    alRight2 = image.scaled(QSize(size, size));

    //ally3 (left)
    image = QImage(relativePath+"boydown3.png");
    alDown3 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"boyup3.png");
    alUp3 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"boyleft3.png");
    alLeft3 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"boyright3.png");
    alRight3 = image.scaled(QSize(size, size));

    //me0 (right)
    image= QImage(relativePath+"medown0.png");
    meDown0 = image.scaled(QSize(size, size));
    image= QImage(relativePath+"meup0.png");
    meUp0 = image.scaled(QSize(size, size));
    image= QImage(relativePath+"meleft0.png");
    meLeft0 = image.scaled(QSize(size, size));
    image= QImage(relativePath+"meright0.png");
    meRight0 = image.scaled(QSize(size, size));

    //me1 (up)
    image = QImage(relativePath+"medown1.png");
    meDown1 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"meup1.png");
    meUp1 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"meleft1.png");
    meLeft1 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"meright1.png");
    meRight1 = image.scaled(QSize(size, size));

    //me2 (down)
    image = QImage(relativePath+"medown2.png");
    meDown2 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"meup2.png");
    meUp2 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"meleft2.png");
    meLeft2 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"meright2.png");
    meRight2 = image.scaled(QSize(size, size));

    //me3 (left)
    image = QImage(relativePath+"medown3.png");
    meDown3 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"meup3.png");
    meUp3 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"meleft3.png");
    meLeft3 = image.scaled(QSize(size, size));
    image = QImage(relativePath+"meright3.png");
    meRight3 = image.scaled(QSize(size, size));

}

QImage* SpriteDealer::getEnDown(int i)
{
    switch(i)
    {
        case 0:
        {
            return &enDown0;
            break;
        }
        case 1:
        {
            return &enDown1;
            break;
        }
        case 2:
        {
            return &enDown2;
            break;
        }
        case 3:
        {
            return &enDown3;
            break;
        }
    }
}
QImage* SpriteDealer::getEnUp(int i)
{
    switch(i)
    {
        case 0:
        {
            return &enUp0;
            break;
        }
        case 1:
        {
            return &enUp1;
            break;
        }
        case 2:
        {
            return &enUp2;
            break;
        }
        case 3:
        {
            return &enUp3;
            break;
        }
    }
}
QImage* SpriteDealer::getEnLeft(int i)
{
    switch(i)
    {
        case 0:
        {
            return &enLeft0;
            break;
        }
        case 1:
        {
            return &enLeft1;
            break;
        }
        case 2:
        {
            return &enLeft2;
            break;
        }
        case 3:
        {
            return &enLeft3;
            break;
        }
    }
}
QImage* SpriteDealer::getEnRight(int i)
{
    switch(i)
    {
        case 0:
        {
            return &enRight0;
            break;
        }
        case 1:
        {
            return &enRight1;
            break;
        }
        case 2:
        {
            return &enRight2;
            break;
        }
        case 3:
        {
            return &enRight3;
            break;
        }
    }
}


QImage* SpriteDealer::getMeDown(int i)
{
    switch(i)
    {
        case 0:
        {
            return &meDown0;
            break;
        }
        case 1:
        {
            return &meDown1;
            break;
        }
        case 2:
        {
            return &meDown2;
            break;
        }
        case 3:
        {
            return &meDown3;
            break;
        }
    }
}
QImage* SpriteDealer::getMeUp(int i)
{
    switch(i)
    {
        case 0:
        {
            return &meUp0;
            break;
        }
        case 1:
        {
            return &meUp1;
            break;
        }
        case 2:
        {
            return &meUp2;
            break;
        }
        case 3:
        {
            return &meUp3;
            break;
        }
    }
}
QImage* SpriteDealer::getMeLeft(int i)
{
    switch(i)
    {
        case 0:
        {
            return &meLeft0;
            break;
        }
        case 1:
        {
            return &meLeft1;
            break;
        }
        case 2:
        {
            return &meLeft2;
            break;
        }
        case 3:
        {
            return &meLeft3;
            break;
        }
    }
}
QImage* SpriteDealer::getMeRight(int i)
{
    switch(i)
    {
        case 0:
        {
            return &meRight0;
            break;
        }
        case 1:
        {
            return &meRight1;
            break;
        }
        case 2:
        {
            return &meRight2;
            break;
        }
        case 3:
        {
            return &meRight3;
            break;
        }
    }
}

QImage* SpriteDealer::getAlDown(int i)
{
    switch(i)
    {
        case 0:
        {
            return &alDown0;
            break;
        }
        case 1:
        {
            return &alDown1;
            break;
        }
        case 2:
        {
            return &alDown2;
            break;
        }
        case 3:
        {
            return &alDown3;
            break;
        }
    }
}
QImage* SpriteDealer::getAlUp(int i)
{
    switch(i)
    {
        case 0:
        {
            return &alUp0;
            break;
        }
        case 1:
        {
            return &alUp1;
            break;
        }
        case 2:
        {
            return &alUp2;
            break;
        }
        case 3:
        {
            return &alUp3;
            break;
        }
    }
}
QImage* SpriteDealer::getAlLeft(int i)
{
    switch(i)
    {
        case 0:
        {
            return &alLeft0;
            break;
        }
        case 1:
        {
            return &alLeft1;
            break;
        }
        case 2:
        {
            return &alLeft2;
            break;
        }
        case 3:
        {
            return &alLeft3;
            break;
        }
    }
}

QImage* SpriteDealer::getAlRight(int i)
{
    switch(i)
    {
        case 0:
        {
            return &alRight0;
            break;
        }
        case 1:
        {
            return &alRight1;
            break;
        }
        case 2:
        {
            return &alRight2;
            break;
        }
        case 3:
        {
            return &alRight3;
            break;
        }
    }
}
