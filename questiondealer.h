#ifndef QUESTIONDEALER_H
#define QUESTIONDEALER_H
#include <question.h>
#include <QVector>
#include <QRandomGenerator>

class QuestionDealer
{
public:
    QuestionDealer();
    Question* getQuestion(int);
private:
    QVector<Question*> mathQuestions;   //0
    QVector<Question*> physicQuestions; //1
    QVector<Question*> historyQuestions;    //2
};

#endif // QUESTIONDEALER_H
