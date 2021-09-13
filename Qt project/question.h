#ifndef QUESTION_H
#define QUESTION_H

#include <QString>

class Question
{
public:
    Question();
    Question(QString, QString, QString, QString, QString, int, int, int);
    QString getAns1(){return ans1;}
    QString getAns2(){return ans2;}
    QString getAns3(){return ans3;}
    QString getAns4(){return ans4;}
    QString getText(){return text;}
    int getAns(){return ans;}
    int getPrice(){return price;}
private:
    QString text;
    QString ans1;
    QString ans2;
    QString ans3;
    QString ans4;
    int ans;
    int price;
    int category;

};

#endif // QUESTION_H
