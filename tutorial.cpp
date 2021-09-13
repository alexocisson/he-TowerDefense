#include <QtWidgets>
#include "tutorial.h"

Tutorial::Tutorial(QWidget *parent) : QWidget(parent)
{
    setWindowIcon(QIcon(":/graphics/graphics/medown0.png"));
    pixmap = new QPixmap();
    picNum=picMax=0;
    setFocusPolicy(Qt::ClickFocus);     // Pour recevoir les évenements clavier
    this->setWindowTitle("Tutorial");
    selectDir();

    //https://wiki.qt.io/Center_and_Resize_MainWindow
    setGeometry(QStyle::alignedRect(
                Qt::LeftToRight,
                Qt::AlignCenter,
                QSize(1400,900), qApp->desktop()->availableGeometry()));
}

Tutorial::~Tutorial()
{
    delete pixmap;
}

void Tutorial::selectDir()
{

    fileNames.append(":/tutorial/tutorial/1.png");
    fileNames.append(":/tutorial/tutorial/2.png");
    fileNames.append(":/tutorial/tutorial/3.png");
    fileNames.append(":/tutorial/tutorial/4.png");
    fileNames.append(":/tutorial/tutorial/5.png");
    fileNames.append(":/tutorial/tutorial/6.png");
    fileNames.append(":/tutorial/tutorial/7.png");
    fileNames.append(":/tutorial/tutorial/8.png");
    fileNames.append(":/tutorial/tutorial/9.png");

    picMax= fileNames.size();

    loadImage();
}
void Tutorial::paintEvent(QPaintEvent *)
{
//    int largeur, hauteur, xOffset, yOffset;
//
//    // Calcul de la hauteur et de la largeur pour l'affichage.
//    largeur = width();
//    hauteur = pixmap->height() * largeur / pixmap->width();
//    if(hauteur > height())
//    {
//        hauteur = height();
//        largeur = pixmap->width() * hauteur / pixmap->height();
//    }
//    xOffset = (int)((width() - largeur) * 0.5f);
//    yOffset = (int)((height() - hauteur) * 0.5f);
//    QPainter paint(this);
//    paint.drawPixmap(xOffset, yOffset, largeur, hauteur, *pixmap);

    if (picMax>0){
    // Autre solution :
        int xOffset;
        int yOffset;
        // Création d'une nouvelle image à l'échelle de la fenêtre
        // en gardant le rapport d'aspect de l'image originale.
        // SmoothTransformation indique que l'image est transformée
        // en utilisant un filtre bilinéaire.
        QPixmap scaledPixmap =  pixmap->scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation /*Qt::FastTransformation*/);
        // Calcul de la position :
        xOffset = (int)((width() - scaledPixmap.width()) * 0.5f);
        yOffset = (int)((height() - scaledPixmap.height()) * 0.5f);
        // Affichage de l'image
        QPainter paint(this);
        paint.drawPixmap(xOffset, yOffset, scaledPixmap);
    }
}

void Tutorial::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)  next();
    if (e->button() == Qt::RightButton) previous();
}

void Tutorial::keyReleaseEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Left) previous();
    else if (e->key() == Qt::Key_Right || e->key() == Qt::Key_Space) next();
    else QWidget::keyReleaseEvent(e);
}

void Tutorial::loadImage()
{
    delete pixmap;
    pixmap = new QPixmap(QString("%1").arg(fileNames[picNum]));

    update();
}

void Tutorial::next()
{
    if (picMax>0){
        picNum = (picNum+1)%picMax;
        loadImage();
    }
}

void Tutorial::previous()
{
    if (picMax>0){
        picNum--;
        if (picNum<0) picNum = picMax-1;
        loadImage();
    }
}


void Tutorial::afficherInformation()
{
    QMessageBox::information( this,
        "Information",
        "Image : " + fileName + "\n\n"
        "Largeur : " + QString("%1").arg(pixmap->width()) + "\n"
        "Hauteur : " + QString("%1").arg(pixmap->height()) + "\n");
}
