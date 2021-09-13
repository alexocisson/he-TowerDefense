#ifndef QUESTIONDIALOG_H
#define QUESTIONDIALOG_H
#include <QDialog>
#include <QLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QLabel>
#include <question.h>
#include <QTimer>
#include <QProgressBar>
#include <QSizePolicy>
#include <QMediaPlayer>

class QuestionDialog : public QDialog
{

    Q_OBJECT

public:
    QuestionDialog(Question*);
    void construct(Question*);
    void timeStep();
private slots:
    void confirmSlot();
signals:
    void confirmSignal(bool rep, int money);
private:
    QVBoxLayout* vLayout;
    QVBoxLayout* vLayout1;
    QPushButton* confirm;
    QRadioButton* radio1;
    QRadioButton* radio2;
    QRadioButton* radio3;
    QRadioButton* radio4;
    QLabel* text;
    QGroupBox *groupBox;
    Question* question;
    QTimer* timer;
    QProgressBar* timeBar;
    int timeLeft;
    QMediaPlayer * goodAnswere;
    QMediaPlayer * badAnswere;
};

#endif // QUESTIONDIALOG_H
