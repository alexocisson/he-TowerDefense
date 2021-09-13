#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QtWidgets>
#include "game.h"
#include "tutorial.h"

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private:
    QPushButton* playButton;
    QPushButton* quitBtn;
    QPushButton* tutorialButton;

    QLabel* branchLabel;
    QLabel* difficultyLabel;

    QComboBox* branchComboBox;
    QComboBox* difficultyComboBox;

    QVBoxLayout* mainLayout;
    QHBoxLayout* labelLayout;
    QHBoxLayout* comboBoxLayout;
    QHBoxLayout* buttonLayout;

    Game* g;
    Tutorial* t;


private slots:
    void gameLaunch();
    void tutorialLaunch();
//    void deleteGame();


};
#endif // MAINMENU_H
