#include "questiondialog.h"

QuestionDialog::QuestionDialog(Question* question)
{
     this->question=question;
     vLayout = new QVBoxLayout();
     vLayout1 = new QVBoxLayout();
     confirm = new QPushButton(this);
     text = new QLabel(question->getText(), this);
     confirm->setText("CONFIRM!");
     timeBar = new QProgressBar();

     groupBox = new QGroupBox(this);
     radio1 = new QRadioButton(this->question->getAns1());
     radio2 = new QRadioButton(this->question->getAns2());
     radio3 = new QRadioButton(this->question->getAns3());
     radio4 = new QRadioButton(this->question->getAns4());

     radio1->setChecked(true);
     vLayout->addWidget(radio1);
     vLayout->addWidget(radio2);
     vLayout->addWidget(radio3);
     vLayout->addWidget(radio4);
     groupBox->setLayout(vLayout);

     vLayout1->addWidget(text);
     vLayout1->addWidget(groupBox);
     vLayout1->addWidget(confirm);
     vLayout1->addWidget(timeBar);

     this->setLayout(vLayout1);

     this->setWindowTitle(QString("%1$").arg(question->getPrice()));
     this->setMinimumSize(400,0);

     connect(confirm, &QPushButton::clicked, this, &QuestionDialog::confirmSlot);

     setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint | Qt::WindowStaysOnTopHint);
     setWindowIcon(QIcon(":/graphics/graphics/question.png"));

     timeLeft=1500;
     timer = new QTimer();
     connect(timer, &QTimer::timeout, this, &QuestionDialog::timeStep);
     timer->setInterval(10);
     timeBar->setRange(0,timeLeft);
     timeBar->setValue(timeLeft);
     //marche pas
     timeBar->setTextVisible(false);
     QSizePolicy policy(QSizePolicy::Expanding, QSizePolicy::Maximum);
     timeBar->setSizePolicy(policy);

     goodAnswere = new QMediaPlayer(this);
     badAnswere = new QMediaPlayer(this);
     goodAnswere->setMedia(QUrl("qrc:/sounds/sounds/good.mp3"));
     badAnswere->setMedia(QUrl("qrc:/sounds/sounds/bad.mp3"));
}


void QuestionDialog::construct(Question* question)
{
    this->setWindowTitle(QString("%1$").arg(question->getPrice()));
    this->question=question;
    radio1->setText(this->question->getAns1());
    radio2->setText(this->question->getAns2());
    radio3->setText(this->question->getAns3());
    radio4->setText(this->question->getAns4());
    text->setText(question->getText());
    timeLeft=1500;
    timeBar->setValue(timeLeft);
    timer->start();
}

void QuestionDialog::confirmSlot()
{
    bool rep=false;
    if(question->getAns()==1)
    {
        if(radio1->isChecked())
            rep=true;
    }
    if(question->getAns()==2)
    {
        if(radio2->isChecked())
            rep=true;
    }
    if(question->getAns()==3)
    {
        if(radio3->isChecked())
            rep=true;
    }
    if(question->getAns()==4)
    {
        if(radio4->isChecked())
            rep=true;
    }
    timer->stop();
    if(rep)
    {
        if(goodAnswere->state()==QMediaPlayer::PlayingState)
            goodAnswere->setPosition(0);
        else
            goodAnswere->play();
    }
    else
    {
        if(badAnswere->state()==QMediaPlayer::PlayingState)
            badAnswere->setPosition(0);
        else
            badAnswere->play();
    }
    this->close();
    emit confirmSignal(rep, question->getPrice());
}

void QuestionDialog::timeStep()
{
    timeLeft--;
    timeBar->setValue(timeLeft);
    if(timeLeft==0)
    {
        confirmSlot();
    }
}
