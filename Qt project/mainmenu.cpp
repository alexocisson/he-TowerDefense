#include "mainmenu.h"
#include "game.h"

MainMenu::MainMenu(QWidget *parent)
    : QWidget(parent)
{
    setWindowIcon(QIcon(":/graphics/graphics/joydown0.png"));
    t = new Tutorial();
    playButton = new QPushButton("Play !");
    quitBtn = new QPushButton("Quit");

    branchLabel = new QLabel("Branch :");
    difficultyLabel= new QLabel("Difficulty :");

    branchComboBox = new QComboBox();
    difficultyComboBox= new QComboBox();

    mainLayout = new QVBoxLayout();
    labelLayout= new QHBoxLayout();
    comboBoxLayout = new QHBoxLayout();
    buttonLayout = new QHBoxLayout();

    tutorialButton = new QPushButton("Tutorial");

    //Add items in comboboxes
    branchComboBox->addItem("Mathematics");
    branchComboBox->addItem("Physics");
    branchComboBox->addItem("History");

    difficultyComboBox->addItem("Low");
    difficultyComboBox->addItem("Medium");
    difficultyComboBox->addItem("Hard");
    difficultyComboBox->addItem("[bonus]Bill Gates");
    difficultyComboBox->addItem("[bonus]testDevMode");
    difficultyComboBox->addItem("[bonus]YouLoose");

    //Set the window title
    this->setWindowTitle("Choose yer options and start a game! ฅʕ•̫͡•ʔฅ");


    //Add items into layouts

    labelLayout->addWidget(branchLabel);
    labelLayout->addWidget(difficultyLabel);

    comboBoxLayout->addWidget(branchComboBox);
    comboBoxLayout->addWidget(difficultyComboBox);

    buttonLayout->addWidget(playButton);
    buttonLayout->addWidget(quitBtn);

    mainLayout->addLayout(labelLayout);
    mainLayout->addLayout(comboBoxLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(tutorialButton);

    //set main layout
    setLayout(mainLayout);

    //Set window size (W,H)
    resize(800,200);

    //BUTTONS CONNECTS
    QObject::connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);

    QObject::connect(playButton, &QPushButton::clicked, this, &MainMenu::gameLaunch);

    QObject::connect(tutorialButton, &QPushButton::clicked, this, &MainMenu::tutorialLaunch);

//    QObject::connect(g, &Game::hasBeenClosed, this, &MainMenu::deleteGame);


    //BUTTONS
    playButton->setSizePolicy(playButton->sizePolicy().horizontalPolicy(),QSizePolicy::MinimumExpanding);
    quitBtn->setSizePolicy(quitBtn->sizePolicy().horizontalPolicy(),QSizePolicy::MinimumExpanding);

}

MainMenu::~MainMenu()
{

}

void MainMenu::gameLaunch()
{

    int branch = branchComboBox->currentIndex();
    int difficulty = difficultyComboBox->currentIndex();
    g = new Game(branch, difficulty);
    g->show();
    this->hide();
    t->hide();
}

void MainMenu::tutorialLaunch()
{
    t->show();
}

//void MainMenu::deleteGame()
//{
//    delete g;
//    this->show();
//}
