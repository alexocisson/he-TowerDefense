#ifndef TUTORIAL_H
#define TUTORIAL_H

#include <QWidget>

class Tutorial : public QWidget
{
    Q_OBJECT
public:
    explicit Tutorial(QWidget *parent = 0);
    ~Tutorial();

public slots:
    void afficherInformation();
    void selectDir();
    void loadImage();
    void next();
    void previous();

signals :
    void statBar(const QString &);

protected:
      void paintEvent(QPaintEvent *);
      void mouseReleaseEvent(QMouseEvent *);
      void keyReleaseEvent(QKeyEvent *);

    private:
      QPixmap * pixmap;
      int picNum, picMax;
      QString path, fileName;
      QStringList fileNames;


};

#endif // TUTORIAL_H
