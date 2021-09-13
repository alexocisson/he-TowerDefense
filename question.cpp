#include "question.h"

Question::Question(QString text, QString ans1, QString ans2, QString ans3, QString ans4, int ans, int price, int category)
{
    this->text = text;
    this->ans1 = ans1;
    this->ans2 = ans2;
    this->ans3 = ans3;
    this->ans4 = ans4;
    this->ans = ans;
    this->price = price;
    this->category = category;
}

Question::Question()
{

}
