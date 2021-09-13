#include "game.h"

Game::Game(int branch, int difficulty)
{
    category=branch;

    //size of the window
    parWidth=1000;
    parHeight=600;
    //time=3000;
    time=3000;
    npcSize=40;
    focusFactor=22;
    enemyKillEarning = 30;
    questionFrequency=200;      //each x/5 sec
    screamPrice=600;
    headPhonesDuration=100;     //lasts x/5 sec
    turretPrice=200;
    timeBoostQuestion=50;
    soundsPath="qrc:/sounds/sounds/";

    scene = new QGraphicsScene( 0,-parHeight/2,parWidth,parHeight);
    this->setScene(scene);
    background = new Background(parWidth,parHeight);
    this->scene->addItem(background);

    this->setWindowTitle("HE-TowerDefence");
    this->setAttribute( Qt::WA_DeleteOnClose );

    //change parameters according to the difficulty
    switch (difficulty)
    {
        case 0:
        {
            coffeePrice=100;
            headPhonesPrice=100;
            money=1000;
            courseAdvancementFactor=0.025;
            enemySpawnPeriod = 4000;
            enemyKillEarning = 40;
            turretPrice = 150;
            upgradePrice=130;
            screamPrice=180;
            questionFrequency=150;
            timeBoostQuestion=80;
            break;
        }
        case 1:
        {
            coffeePrice=110;
            headPhonesPrice=120;
            money=800;
            courseAdvancementFactor=0.02;
            enemySpawnPeriod = 3000;
            turretPrice = 220;
            upgradePrice=150;
            screamPrice=250;
            questionFrequency=140;
            timeBoostQuestion=20;
            break;
        }
        case 2:
        {
            coffeePrice=140;
            headPhonesPrice=120;
            money=800;
            courseAdvancementFactor=0.020;
            enemySpawnPeriod = 3000;
            turretPrice = 230;
            upgradePrice=160;
            screamPrice=300;
            questionFrequency=120;
            timeBoostQuestion=60;
            enemyKillEarning = 20;
            break;
        }
        case 3:
        {
            coffeePrice=500;
            headPhonesPrice=500;
            enemyKillEarning = 100;
            money=75000;
            courseAdvancementFactor=0.02;
            enemySpawnPeriod = 2000;
            upgradePrice=300;
            break;
        }
        //For devellopers, 4 to win quickly, 5 to loose quickly
        case 4:
        {
            coffeePrice=500;
            headPhonesPrice=500;
            money=50000;
            enemyKillEarning = 200;
            courseAdvancementFactor=0.6;
            enemySpawnPeriod = 5000;
            questionFrequency=2000;
            upgradePrice=40;
            break;
        }
        case 5:
        {
            coffeePrice=500;
            headPhonesPrice=500;
            money=500;
            courseAdvancementFactor=0.02;
            enemySpawnPeriod = 5000;
            questionFrequency=2000;
            time=80;
            upgradePrice=40;
            break;
        }
    }

    //Set course quantity, useless to change since there is
    //a course advencement factor. But still used
    //to display and check if won
    courseMax=100;
    course=0;

    //a rectifier avec une fixed size a la fin du devellopement
    this->setMinimumSize(parWidth,parHeight);

    //sprite dealers, according to lvl
    sdNormal = new SpriteDealer(npcSize);
    sdBig = new SpriteDealer(npcSize*1.2);
    sdBigPhatFuck = new SpriteDealer(npcSize*1.5);
    sd = sdNormal;

    //create the places
    Place* place;
    int yRow=-height()/2;
    int xRow=0;
    int num=1;
    for (int i=0; i<4; i++)
    {

        if(i<2)
            yRow+=height()/9;
        else if(i==2)
            yRow=(height()/6)+(height()/9);
        else
            yRow+=height()/9;
        xRow=0;
        for(int j=0; j<4; j++)
        {
            xRow+=width()/9;
            for(int k=0; k<2; k++)
            {
                if (k==0)
                {
                    xRow+=width()/36;
                    place = new Place(QPoint(xRow, yRow), num);
                    num++;
                }
                else if (k==1)
                {
                    xRow+=width()/18;
                    place = new Place(QPoint(xRow, yRow), num);
                    xRow+=width()/36;
                    num++;
                }
                places.append(place);
            }
        }
    }

    foreach (Place * place, places)
    {
        scene->addItem(place);
    }


    //create the player
    this->player = new Player(places[7], sd, parWidth, parHeight);
    places[7]->setNPC(true);
    scene->addItem(player);

    //displays focus bar
    pensize=4;
    focusX=13*parWidth/18-pensize;
    focusY=-parHeight/2+pensize;
    focusWidth=5*parWidth/18;
    focusHeight=parHeight/18;

    focusBackground = new QGraphicsRectItem(focusX,focusY, focusWidth, focusHeight);
    focusBackground->setBrush(QBrush(QColor(204,229,255)));
    focusBackground->setPen(QPen(Qt::black, pensize));
    scene->addItem(focusBackground);
    focusForeground = new QGraphicsRectItem(focusX+(pensize/2),focusY+(pensize/2), focusWidth-pensize, focusHeight-pensize);
    focusForeground->setBrush(QBrush(QColor(255,51,51)));
    scene->addItem(focusForeground);
    focusTextItem = new QGraphicsTextItem();
    focusTextItem->setPlainText(QString("<big>Focus<\big>: %1/%2").arg(player->getFocus()).arg(player->getMaxFocus()));
    focusTextItem->setX(focusX);
    focusTextItem->setY(focusY);
    focusTextItem->setDefaultTextColor(QColor(Qt::white));
    scene->addItem(focusTextItem);

    //displays course advencement bar
    courseX=13*parWidth/18-pensize;
    courseY=parHeight/2 - parHeight/18-pensize;
    courseWidth=5*parWidth/18;
    courseHeight=parHeight/18;

    courseBackground = new QGraphicsRectItem(courseX,courseY, courseWidth, courseHeight);
    courseBackground->setBrush(QBrush(QColor(204,229,255)));
    courseBackground->setPen(QPen(Qt::black, pensize));
    scene->addItem(courseBackground);
    courseForeground = new QGraphicsRectItem(courseX+(pensize/2),courseY+(pensize/2), courseWidth-pensize, courseHeight-pensize);
    courseForeground->setBrush(QBrush(QColor(102,204,0)));
    scene->addItem(courseForeground);

    //displays time and pause button
    timeTextItem = new QGraphicsTextItem();
    timeX=parWidth/200;
    timeY=-parHeight/2;
    timeTextItem->setPos(timeX, timeY);
    timeTextItem->setHtml(QString("<big>Time left<\big>: %1:%2").arg((int)(time/300)).arg((int)((time/5)%60)));
    scene->addItem(timeTextItem);
    pauseLabel=new ClickLabel(parWidth,parHeight);
    pauseLabel->setGeometry(0, timeY, 48*(parWidth/280),parHeight/19);
    pauseLabel->setText(QString("WAAAAAAAAAA"));
    connect(pauseLabel, &ClickLabel::clicked, this, &Game::pause);
    scene->addWidget(pauseLabel);
    pauseBackground = new Background(parWidth, parHeight);
    pauseBackground->pause();

    //displays money$$$
    moneyTextItem = new QGraphicsTextItem();
    moneyX=parWidth/6+parWidth/200;
    moneyY=-parHeight/2;
    moneyTextItem->setPos(moneyX, moneyY);
    moneyTextItem->setHtml(QString("<big>Money<\big>: %1$").arg(money));
    scene->addItem(moneyTextItem);

    //displays spotify
    headPhonesTextItem = new QGraphicsTextItem();
    headPhonesX=2*parWidth/6+parWidth/200;
    headPhonesY=-parHeight/2;
    headPhonesTextItem->setPos(headPhonesX, headPhonesY);
    headPhonesTime=0;
    headPhonesTextItem->setHtml(QString("<big>Spotify:<\big> %1").arg(headPhonesTime));
    scene->addItem(headPhonesTextItem);

    //display coffee
    coffeeTextItem = new QGraphicsTextItem();
    coffeeX=13*parWidth/24-parWidth/200;
    coffeeY=-parHeight/2;
    coffeeTextItem->setPos(coffeeX, coffeeY);
    coffeeBoost=0;
    coffeeTextItem->setHtml(QString("<big>Coffee boost:<\big> %1").arg(coffeeBoost));
    scene->addItem(coffeeTextItem);


    //main timers
    moveTimer = new QTimer(this);
    moveTimer->setInterval(2);      //NE PAS MODIFIER
    spawnTimer = new QTimer(this);
    spawnTimer->setInterval(enemySpawnPeriod);
    timeTimer = new QTimer(this);
    timeTimer->setInterval(200);    //NE PAS MODIFIER
    turretTimer = new QTimer(this);
    turretTimer->setInterval(1500);
    projectileTimer = new QTimer(this);
    projectileTimer->setInterval(10);
    connect(spawnTimer, &QTimer::timeout, this, &Game::spawnEnnemy);
    connect(moveTimer, &QTimer::timeout, this, &Game::moveStep);
    connect(timeTimer, &QTimer::timeout, this, &Game::updateTimeAndCourse);  //gere aussi update des sprites


    //spawn button
    allieButton = new QPushButton();
    allieButtonX=0;
    allieButtonY=(parHeight/2)-(parHeight/18);
    allieButtonWidth=5*parWidth/36;
    allieButtonHeight=parHeight/18;
    allieButton->setText(QString("Call ally"));
    allieButton->setGeometry(allieButtonX, allieButtonY, allieButtonWidth, allieButtonHeight);
    connect(allieButton, &QPushButton::clicked, this, &Game::dialogAlly);
    scene->addWidget(allieButton);
    allyDialog = new AllyDialog(money, QVector<int>());
    connect(allyDialog, &AllyDialog::addSignal, this, &Game::spawnAlly);
    connect(allyDialog, &AllyDialog::closed, this, &Game::startTimers);

    //coffee button
    coffeeButton = new QPushButton();
    coffeeButtonX=5*parWidth/36;
    coffeeButtonY=(parHeight/2)-(parHeight/18);
    coffeeButtonWidth=5*parWidth/36;
    coffeeButtonHeight=parHeight/18;
    coffeeButton->setText(QString("Drink coffee (%1$)").arg(coffeePrice));
    coffeeButton->setGeometry(coffeeButtonX, coffeeButtonY, coffeeButtonWidth, coffeeButtonHeight);
    connect(coffeeButton, &QPushButton::clicked, this, &Game::drinkCoffee);
    scene->addWidget(coffeeButton);

    //spotify button
    headPhonesButton = new QPushButton();
    headPhonesButtonX=2*(5*parWidth/36);
    headPhonesButtonY=(parHeight/2)-(parHeight/18);
    headPhonesButtonWidth=5*parWidth/36;
    headPhonesButtonHeight=parHeight/18;
    headPhonesButton->setText(QString("Spotify (%1$)").arg(headPhonesPrice));
    headPhonesButton->setGeometry(headPhonesButtonX, headPhonesButtonY, headPhonesButtonWidth, headPhonesButtonHeight);
    connect(headPhonesButton, &QPushButton::clicked, this, &Game::useHeadPhones);
    scene->addWidget(headPhonesButton);

    //scream button
    screamButton = new QPushButton();
    screamButtonX=3*(5*parWidth/36);
    screamButtonY=(parHeight/2)-(parHeight/18);
    screamButtonWidth=5*parWidth/36;
    screamButtonHeight=parHeight/18;
    screamButton->setText(QString("Scream (%1$)").arg(screamPrice));
    screamButton->setGeometry(screamButtonX, screamButtonY, screamButtonWidth, screamButtonHeight);
    connect(screamButton, &QPushButton::clicked, this, &Game::scream);
    scene->addWidget(screamButton);

    //questions
    qd = QuestionDealer();
    questionDialog = new QuestionDialog(qd.getQuestion(category));
    connect(questionDialog, &QuestionDialog::confirmSignal, this, &Game::answereQuestion);

    //music
    ambiantSound = new QMediaPlayer(this);
    gameMusic = new QMediaPlayer(this);         //30200ms main theme commence, 228900ms main them recommence
    coffeeSound = new QMediaPlayer(this);
    screamSound = new QMediaPlayer(this);
    paperPlaneSound = new QMediaPlayer(this);


    gameMusic->setMedia(QUrl(soundsPath+"lamourtoujours.mp3"));
    ambiantSound->setMedia(QUrl(soundsPath+"large-group-of-women-speaking-ambience (mastered).mp3"));
    coffeeSound->setMedia(QUrl(soundsPath+"drinking-coffee-sound-effect (mastered).mp3"));
    screamSound->setMedia(QUrl(soundsPath+"scream.mp3"));
    paperPlaneSound->setMedia(QUrl(soundsPath+"paperplane.mp3"));

    paperPlaneSound->setVolume(70);
    coffeeSound->setVolume(40);
    screamSound->setVolume(70);
    gameMusic->setVolume(100);
    gameMusic->setPosition(1500);
    gameMusic->play();
    ambiantSound->setVolume(0);
    ambiantSound->play();
    musicTimer = new QTimer(this);
    musicTimer->setInterval(20);

    connect(musicTimer, &QTimer::timeout, this, &Game::updateMusic);
    musicTimer->start();

    //turret
    turretZone1 = new TurretZone(2*parWidth/9,-2*parHeight/9,parWidth/9,parHeight/9);
    turretZone2 = new TurretZone(4*parWidth/9,-2*parHeight/9,parWidth/9,parHeight/9);
    turretZone3 = new TurretZone(6*parWidth/9,-2*parHeight/9,parWidth/9,parHeight/9);
    turretZone4 = new TurretZone(2*parWidth/9,3*parHeight/18,parWidth/9,parHeight/9);
    turretZone5 = new TurretZone(4*parWidth/9,3*parHeight/18,parWidth/9,parHeight/9);
    turretZone6 = new TurretZone(6*parWidth/9,3*parHeight/18,parWidth/9,parHeight/9);
    turretZonea = new TurretZone(0*parWidth/9,-3*parHeight/9,parWidth/9,2*parHeight/9);
    turretZoneb = new TurretZone(8*parWidth/9,-3*parHeight/9,parWidth/9,2*parHeight/9);
    turretZonec = new TurretZone(0*parWidth/9,3*parHeight/18,parWidth/9,2*parHeight/9);
    turretZoned = new TurretZone(8*parWidth/9,3*parHeight/18,parWidth/9,2*parHeight/9);
    scene->addWidget(turretZone1);
    scene->addWidget(turretZone2);
    scene->addWidget(turretZone3);
    scene->addWidget(turretZone4);
    scene->addWidget(turretZone5);
    scene->addWidget(turretZone6);
    scene->addWidget(turretZonea);
    scene->addWidget(turretZoneb);
    scene->addWidget(turretZonec);
    scene->addWidget(turretZoned);
    connect(turretZone1, &TurretZone::clicked, this, &Game::addTurret);
    connect(turretZone2, &TurretZone::clicked, this, &Game::addTurret);
    connect(turretZone3, &TurretZone::clicked, this, &Game::addTurret);
    connect(turretZone4, &TurretZone::clicked, this, &Game::addTurret);
    connect(turretZone5, &TurretZone::clicked, this, &Game::addTurret);
    connect(turretZone6, &TurretZone::clicked, this, &Game::addTurret);
    connect(turretZonea, &TurretZone::clicked, this, &Game::addTurret);
    connect(turretZoneb, &TurretZone::clicked, this, &Game::addTurret);
    connect(turretZonec, &TurretZone::clicked, this, &Game::addTurret);
    connect(turretZoned, &TurretZone::clicked, this, &Game::addTurret);
    turretZone1->hide();
    turretZone2->hide();
    turretZone3->hide();
    turretZone4->hide();
    turretZone5->hide();
    turretZone6->hide();
    turretZonea->hide();
    turretZoneb->hide();
    turretZonec->hide();
    turretZoned->hide();
    turretButton = new QPushButton();
    turretButtonX=4*(5*parWidth/36);
    turretButtonY=(parHeight/2)-(parHeight/18);
    turretButtonWidth=5*parWidth/36;
    turretButtonHeight=parHeight/18;
    turretButton->setText(QString("Turret (%1$)").arg(turretPrice));
    turretButton->setGeometry(turretButtonX, turretButtonY, turretButtonWidth, turretButtonHeight);
    connect(turretButton, &QPushButton::clicked, this, &Game::showTurretZones);
    scene->addWidget(turretButton);
    upgradeButton=new QPushButton();
    upgradeButton->setGeometry(-parWidth/3,0,turretButtonWidth,turretButtonHeight);
    upgradeButton->hide();
    upgradeButton->setText(QString("Up (%1$)").arg(upgradePrice));
    scene->addWidget(upgradeButton);
    connect(upgradeButton, &QPushButton::clicked, this, &Game::payAnUpgrade);

    //accelerate
    accelerateButton = new QPushButton();
    accelerateButtonX=focusX+4*focusWidth/5;
    accelerateButtonY=-parHeight/2+focusHeight+2*pensize;
    accelerateButtonWidth=parWidth-accelerateButtonX;
    accelerateButtonHeight=parHeight/18;
    accelerateButton->setGeometry(accelerateButtonX, accelerateButtonY, accelerateButtonWidth, accelerateButtonHeight);
    accelerateButton->setText("x2");
    scene->addWidget(accelerateButton);
    connect(accelerateButton, &QPushButton::clicked, this, &Game::accelerate);


    startTimers();
}

//void Game::closeEvent(QCloseEvent*event)
//{
//    emit hasBeenClosed();
//}

//Game::~Game()
//{
//    delete scene;
//    delete selectedPlace;
//    delete sdNormal;
//    delete sdBig;
//    delete sdBigPhatFuck;
//    delete sd;
//    delete allyDialog;

//    //objects pouvant etre removed de la scene selon les circonstances
//    if(pauseBackground)
//        delete pauseBackground;
//    if(focusTextItem)
//        delete focusTextItem;
//    if(focusBackground)
//        delete focusBackground;
//    if(focusForeground)
//        delete focusForeground;
//    if(pauseBackground)
//        delete pauseBackground;
//}

//makes the enemies and allies move
void Game::moveStep()
{
    foreach (Enemy * ennemy, ennemies)
    {
        ennemy->step();
    }
    foreach (Ally * ally, allies)
    {
        ally->step();
    }
}


//spawns an ennemy, each 4 is lvl 2, each 15 is lvl 3
//check if there is a free place, else gives it a default place
//(the enemy will cross the hallway)
void Game::spawnEnnemy()
{
    //gestion puissance ennemis
    enemySent++;
    if(enemySent==15)
    {
        enemySent=0;
        sd=sdBigPhatFuck;
        enemyLvl=3;
    }
    else if (enemySent%4==0)
    {
        sd=sdBig;
        enemyLvl=2;
    }
    else
    {
        sd=sdNormal;
        enemyLvl=1;
    }

    //spawn des ennemis
    Enemy* ennemy;
    QVector<int> available;
    for (int i=0; i<places.size(); i++)
    {
         if(!(places[i]->hasNPC()))
         {
            available.append(i);
         }
    }

    if(available.isEmpty())
    {
        Place * place = new Place();
        ennemy = new Enemy(place, enemyLvl, parWidth, sd);
        ennemies.append(ennemy);
        scene->addItem(ennemy);
    }
    else
    {
        int m = rand() % static_cast<int>(available.size());
        int n = available[m];
        ennemy = new Enemy(places[n], enemyLvl, parWidth, sd);
        places[n]->setNPC(true);
        ennemies.append(ennemy);
        scene->addItem(ennemy);
    }
}

//called when the allyButton is clicked
//stop the timers, reset the speed to 1x,
//check the free places and opens the ally dialog
//if there are no free places, restart the timers
//and do not open the dialog
void Game::dialogAlly()
{
    stopTimers();
    QVector<int> list;
    foreach(Place * place, places)
    {
        place->showNumber(true);
        if(!place->hasNPC())
        {
            list.append(place->getNumber());
        }
    }
    if(!list.isEmpty())
    {
        doubleSpeed=true;
        accelerate();
        allyDialog->construct(money, list);
        allyDialog->show();
    }
    else
    {
        startTimers();
    }
}

//function called when the allydialog is confirmed
//create an ally with a lvl and a place, and spawns it
void Game::spawnAlly(int lvl, int n) //n place number
{
    if(lvl==1)
    {
        sd=sdNormal;
        updateMoney(-100);
    }
    if(lvl==2)
    {
        sd=sdBig;
        updateMoney(-200);
    }
    if(lvl==3)
    {
        sd=sdBigPhatFuck;
        updateMoney(-400);
    }

    Ally* ally;
    ally = new Ally(places[n-1], lvl, parWidth, sd);
    places[n-1]->setNPC(true);
    allies.append(ally);
    scene->addItem(ally);
}

//calls all the important functions during a party the require
//the timers. Could be done with connections, but this
//enable us to just connect and disconnect once for those funct
//Modification: I called by updateTimeAndCourse
//once we have verified if the game is won or lost
void Game::partySteps()
{
    updateSpriteAndKill();
    updateGraphicInfos();
    updateQuestions();
    updateDamage();
    player->updateCoffee();
    player->updateHeadPhones();
}

//connection when the game is won
//at first implemented for lisibility
//but kind of useless
void Game::cleanGameSteps()
{
    updateSpriteAndKill();
}

//starts the timers, hide the place number
void Game::startTimers()
{
    foreach (Place * place, places) {
        place->showNumber(false);
    }
    setEnabled(true);
    timeTimer->start();
    spawnTimer->start();
    moveTimer->start();
    turretTimer->start();
    projectileTimer->start();
}

//a funct that stops the timers and diable
//the scene, used when we call an ally or
//a question is asked
void Game::stopTimers()
{
    setEnabled(false);
    timeTimer->stop();
    spawnTimer->stop();
    moveTimer->stop();
    turretTimer->stop();
    projectileTimer->stop();
}


//kills all the npc, disable everything,
//make the connections for the victory animation
//tells the player he've won
void Game::winning()
{
    stopTimers();
    player->hasWon();
    doubleSpeed=true;
    accelerate();
    scene->removeItem(focusTextItem);
    scene->removeItem(focusBackground);
    scene->removeItem(focusForeground);
    accelerateButton->hide();
    allieButton->setEnabled(false);
    coffeeButton->setEnabled(false);
    headPhonesButton->setEnabled(false);
    screamButton->setEnabled(false);
    turretButton->setEnabled(false);
    //lancer des timers d'annimation victoire
    foreach(Enemy * enemy, ennemies)
    {
        enemy->kill();
    }
    foreach(Ally * ally, allies)
    {
        ally->kill();
    }

    emit destroyAllTurretsAndProjectiles();
    turretZonesVisible=true;
    showTurretZones();

    disconnect(timeTimer, &QTimer::timeout, this, &Game::updateTimeAndCourse);
    disconnect(spawnTimer, &QTimer::timeout, this, &Game::spawnEnnemy);
    connect(timeTimer, &QTimer::timeout, this, &Game::cleanGameSteps);
    connect(timeTimer, &QTimer::timeout, this, &Game::updatePlayerSpriteAndBackground);
    connect(moveTimer, &QTimer::timeout, this, &Game::playerLeaves);
    timeTimer->start();
    moveTimer->start();


    //musique
    gameMusic->stop();
    gameMusic->setMedia(QUrl(soundsPath+"the-8-bit-hallelujah-chorus.mp3"));
    gameMusic->play();
}


//kill all the ally, disconnect some timers and connects others
//dissable the special powers for the player
//and go in the loosing phase: the player kills himself.
//It is still possible to place ally and turrets.
//Yes you are dead, but the world doesn't stop when
//you die
void Game::loosing()
{
    stopTimers();
    doubleSpeed=true;
    accelerate();
    //lancer des timers d'annimation défaite
    foreach(Ally * ally, allies)
    {
        ally->kill();
    }
    money=1000;
    turretZonesVisible=true;
    showTurretZones();
    emit destroyAllTurretsAndProjectiles();
    accelerateButton->hide();
    coffeeButton->setEnabled(false);
    headPhonesButton->setEnabled(false);
    screamButton->setEnabled(false);
    places[7]->free();
    disconnect(timeTimer, &QTimer::timeout, this, &Game::updateTimeAndCourse);
    disconnect(musicTimer, &QTimer::timeout, this, &Game::updateMusic);
    connect(timeTimer, &QTimer::timeout, this, &Game::cleanGameSteps);
    connect(timeTimer, &QTimer::timeout, this, &Game::updatePlayerSpriteAndBackground);
    connect(moveTimer, &QTimer::timeout, this, &Game::playerLeaves);
    connect(timeTimer, &QTimer::timeout, this, &Game::updateDamage);

    gameMusic->setVolume(100);
    ambiantSound->setVolume(0);

    startTimers();

    //musique
    gameMusic->stop();
    gameMusic->setMedia(QUrl(soundsPath+"the-sound-of-silence-8-bit-tribute-to-disturbed-and-simon-garfunkel-8-bit-universe.mp3"));
    gameMusic->play();
}


//makes the player move when you win/loose
void Game::playerLeaves()
{
    player->step();
}

//updates the sprite of the player when the game is won or lost
//also updates the background for win/loose
void Game::updatePlayerSpriteAndBackground()
{
    player->updateSprite();
    if(state3Flage&&player->getState()==3)
    {
        background->victory();
        state3Flage==false;
    }
    if(player->getState()==5)
        background->breackWall();
}


//funct called when the player drinks the coffee,
//plays the sound andupdate the money
//activate a coffe in the class player
void Game::drinkCoffee()
{
    player->drinkCoffee();
    updateMoney(-coffeePrice);
    if(coffeeSound->state()==QMediaPlayer::PlayingState)
        coffeeSound->setPosition(0);
    else
        coffeeSound->play();
}

//funct called when the player pays for spotify
//updates the money and activate the headphones
//in the class player
void Game::useHeadPhones()
{
    player->useHeadPhones();
    updateMoney(-headPhonesPrice);
}


//funct called when the player screams,
//kills all the enemies and ally, update the
//money and plays the sound
void Game::scream()
{
    foreach(Enemy * enemy, ennemies)
    {
        enemy->kill();
    }
    foreach(Ally * ally, allies)
    {
        ally->kill();
    }
    if(screamSound->state()==QMediaPlayer::PlayingState)
    {
        screamSound->setPosition(0);
    }
    else
    {
        screamSound->play();
    }
    updateMoney(-screamPrice);
}


//this funct is called when the Dialog emits a signal
//it closes the dialog and update the money if the answere is true
//it also restart the timers to unpause the game
void Game::answereQuestion(bool rep, int money)
{
    if(rep)
    {
        updateMoney(money);
        time+=timeBoostQuestion;
    }
    startTimers();
}


//this funct updates the time and the progress of the course
//it also checks if the game is won or lost, and call the
//partySteps if the game is not won or lost
void Game::updateTimeAndCourse()
{
    //update temps et avancée cours
    time--;
    course+=(player->getFocus()/player->getMaxFocus())*courseAdvancementFactor;
    //verifie si on a gagner
    if (time<=0)
        loosing();
    else if (course>=courseMax)
        winning();
    else
        partySteps();
}


//this funct updates the sprites of the moving npcs
//and destroy those who are out of the game (and update the
//money if it's an ennemy)
void Game::updateSpriteAndKill()
{
    //tue les morts et update les sprites
    Enemy* enemy;
    Ally* ally;
    for (int i=ennemies.size()-1; i>=0; i--)
    {
        ennemies[i]->updateSprite();
        if(ennemies[i]->isOut())
        {
            enemy=ennemies[i];
            scene->removeItem(enemy);
            ennemies.remove(i);
            if(enemy->isDead())
                updateMoney(enemyKillEarning*enemy->getLvl());
            else
                updateMoney(-enemyKillEarning*enemy->getLvl());
            delete enemy;
        }
    }
    for (int i=allies.size()-1; i>=0; i--)
    {
        allies[i]->updateSprite();
        if(allies[i]->isOut())
        {
            ally=allies[i];
            scene->removeItem(ally);
            allies.remove(i);
            delete ally;
        }
    }


    switch (animatedIconState) {
    case 0:
    {
        setWindowIcon(QIcon(":/graphics/graphics/joydown0.png"));
        break;
    }
    case 1:
    {
        setWindowIcon(QIcon(":/graphics/graphics/joydown1.png"));
        break;
    }
    case 2:
    {
        setWindowIcon(QIcon(":/graphics/graphics/joydown2.png"));
        break;
    }
    case 3:
    {
        setWindowIcon(QIcon(":/graphics/graphics/joydown3.png"));
        break;
    }

    }
    animatedIconState++;
    if (animatedIconState==4)
        animatedIconState=0;
}


//this funct updates the money, time left, coffe boost left, spotify left,
//the advencement of the course and the focus
void Game::updateGraphicInfos()
{
    //focus, course, time visualUpdate
    focusForeground->setRect(focusX+(pensize/2),focusY+(pensize/2), (player->getFocus()/player->getMaxFocus())*(focusWidth-(pensize)), focusHeight-(pensize));
    courseForeground->setRect(courseX+(pensize/2),courseY+(pensize/2), (course/courseMax)*(courseWidth-(pensize)), courseHeight-(pensize));
    focusTextItem->setHtml(QString("<big>Focus</big>: %1/%2").arg((int)player->getFocus()).arg(player->getMaxFocus()));
    timeTextItem->setHtml(QString("<big>Time left<\big>: %1:%2").arg((int)(time/300)).arg((int)((time/5)%60))); //, -2, 10,'0' marche pas, faut fille le timer si 1 seul chiffre
    if(time<600)
        timeTextItem->setDefaultTextColor(QColor(Qt::red));
    headPhonesTime=player->getHeadPhonesTimeLeft();
    headPhonesTextItem->setHtml(QString("<big>Spotify:<\big> %1:%2").arg((int)(headPhonesTime/300)).arg((int)((headPhonesTime/5)%60)));
    coffeeBoost=player->getCoffeBoost();
    coffeeTextItem->setHtml(QString("<big>Coffee boost:<\big> %1").arg((int)coffeeBoost));
}


//this funct calculate the focus of the player depending on the enemies around
//it also deals the damages between allies and ennemies
void Game::updateDamage()
{
    double focus=player->getMaxFocus();
    foreach (Enemy * ennemy, ennemies)
    {
        if(!ennemy->isDead())
        {
            focus=focus-(ennemy->noise(player->getPosition())*focusFactor); //il faut change le 10. pour choisir le coeficient de dégats sur la concentration
            foreach (Ally * ally, allies)
            {
                if(!ally->isDead())
                {
                    ally->getDamage(ennemy->damage(ally->getPosition()));
                    ennemy->getDamage(ally->damage(ennemy->getPosition()));
                }
            }
        }
    }
    player->setFocus(focus);
}

//This funct is called when an ally, turret or special power
//is bought. It updates the money and disable the buttons
//that makes actions you are to poor to do
void Game::updateMoney(int parMoney)
{
    if (time>0&&course<courseMax)
    {
        money = money+parMoney;
        moneyTextItem->setHtml(QString("<big>Money<\big>: %1$").arg(money));
        if(money<100)
            allieButton->setEnabled(false);
        else
            allieButton->setEnabled(true);
        if(money<coffeePrice)
            coffeeButton->setEnabled(false);
        else
            coffeeButton->setEnabled(true);
        if(money<headPhonesPrice)
            headPhonesButton->setEnabled(false);
        else
            headPhonesButton->setEnabled(true);
        if(money<screamPrice)
            screamButton->setEnabled(false);
        else
            screamButton->setEnabled(true);
        if(money<upgradePrice)
            upgradeButton->setEnabled(false);
        else
            upgradeButton->setEnabled(true);
        //here the turretzone is hidden (if it was shown)
        //while the button to show it is disabled
        if(money<turretPrice)
        {
            turretZonesVisible=true;
            showTurretZones();
            turretButton->setEnabled(false);
        }
        else
        {
            turretButton->setEnabled(true);
        }
    }

}

//This funct increments the  count and show the dialog for a
// when the count is equals to the frequency.
//reste the speed of the game to x1
void Game::updateQuestions()
{
    questionCount++;
    if(questionCount==questionFrequency)
    {
        doubleSpeed=true;
        accelerate();
        setEnabled(false);
        stopTimers();
        questionCount=0;
        if(questionDialog)
        questionDialog->construct(qd.getQuestion(category));
        questionDialog->show();
    }
}

//this funct is regulary called by the musicTimer, it adapts the volume
//of the music and the enemies noise depending on the focus.
//It also loops those two sounds
void Game::updateMusic()
{
    int focus = player->getFocus();
    if(focus>100)
        focus=100;
    gameMusic->setVolume(focus);
    ambiantSound->setVolume(100-focus);
    if(gameMusic->position()>228900)
        gameMusic->setPosition(30200);
    if(ambiantSound->position()>178000)
        ambiantSound->setPosition(300);
}

//this funct is called when the pauselabel is clicked, it checks if the game
//is paused or not, starts/stops the timers, shows/hide the pause image
//and change the size of the pauselabel (when the game is paused, it
//takes the whole screen so you can click anywhere to upause
void Game::pause()
{
    if(gamePaused)
    {
        gamePaused=false;
        timeTimer->start();
        spawnTimer->start();
        moveTimer->start();
        turretTimer->start();
        projectileTimer->start();
        allieButton->setEnabled(true);
        coffeeButton->setEnabled(true);
        headPhonesButton->setEnabled(true);
        screamButton->setEnabled(true);
        pauseLabel->makeSmall();
        scene->removeItem(pauseBackground);
    }
    else
    {
        gamePaused=true;
        timeTimer->stop();
        spawnTimer->stop();
        moveTimer->stop();
        turretTimer->stop();
        projectileTimer->stop();
        allieButton->setEnabled(false);
        coffeeButton->setEnabled(false);
        headPhonesButton->setEnabled(false);
        screamButton->setEnabled(false);
        pauseLabel->makeBig();
        scene->addItem(pauseBackground);
        turretZonesVisible=true;
        showTurretZones();
    }
}

//this funct is called when a turret emits a projectile, it adds it to the
//scene and makes the requiered connections
void Game::addProjectile(Projectile * proj)
{
    scene->addItem(proj);
    connect(proj, &Projectile::destroyMe, this, &Game::destroyProjectile);
    connect(projectileTimer, &QTimer::timeout, proj, &Projectile::move);
    connect(this, &Game::destroyAllTurretsAndProjectiles, proj, &Projectile::destroyMeFunct);

    if(paperPlaneSound->state()==QMediaPlayer::PlayingState)
        paperPlaneSound->setPosition(0);
    else
        paperPlaneSound->play();
}

//This funct is called when a projectile is to old or collided with an enemy
//it disconnects its connections, removes it from the scene and deletes it
void Game::destroyProjectile(Projectile * proj)
{
    disconnect(proj, &Projectile::destroyMe, this, &Game::destroyProjectile);
    disconnect(projectileTimer, &QTimer::timeout, proj, &Projectile::move);
    disconnect(this, &Game::destroyAllTurretsAndProjectiles, proj, &Projectile::destroyMeFunct);
    scene->removeItem(proj);
    delete proj;
}

//this funct is called when a turret emits the signal "destroy me"
//it disconnect all the connections, remove the turret from the scene
//destroys the turret, and decrement the number of turrets
void Game::destroyTurret(ShootingTurret* tur)
{
    disconnect(tur, &ShootingTurret::addProjectile, this, &Game::addProjectile);
    disconnect(tur, &ShootingTurret::destroyMe, this, &Game::destroyTurret);
    disconnect(turretTimer, &QTimer::timeout, tur, &ShootingTurret::aquire_target);
    disconnect(turretTimer, &QTimer::timeout, tur, &ShootingTurret::decTimeToLive);
    disconnect(this, &Game::destroyAllTurretsAndProjectiles, tur, &ShootingTurret::destroyMeFunct);
    disconnect(this, &Game::getTurretPosition, tur, &ShootingTurret::getMyPosition);
    disconnect(tur, &ShootingTurret::myPosition, this, &Game::addTurretPosition);
    disconnect(tur, &ShootingTurret::showUpgradeButton, this, &Game::showUpgradeButton);
    disconnect(tur, &ShootingTurret::hideUpgradeButton, this, &Game::hideUpgradeButton);
    scene->removeItem(tur);
    delete tur;
    turretNb--;
}

//this funct is called when we click in the turret zone to add a turret
void Game::addTurret(QPoint p, TurretZone * zone)
{
    fillTurretPositions();
    bool noTurret=true;
    //check that the turret isn't over another
    foreach(QPoint point, turretPositions)
    {
        if(point.x()-15<zone->x()+p.x()&&
           point.x()+45>zone->x()+p.x()&&
           point.y()-15<zone->y()+p.y()&&
           point.y()+45>zone->y()+p.y())
        {
            noTurret=false;
        }
    }
    //check that the turret is not to much out of the zone
    if(p.x()<10||p.x()>zone->width()-10||p.y()<10||p.y()>zone->height()-10)
        noTurret=false;
    //place the turret and make all the connections if the player
    //has engouth money and there aren't to many turrets
    if(money>=turretPrice&&turretNb<15&&noTurret)
    {
        updateMoney(-turretPrice);
        turret = new ShootingTurret(QPoint(zone->x()+p.x(),zone->y()+p.y()));
        scene->addItem(turret);
        connect(turret, &ShootingTurret::addProjectile, this, &Game::addProjectile);
        connect(turret, &ShootingTurret::destroyMe, this, &Game::destroyTurret);
        connect(turretTimer, &QTimer::timeout, turret, &ShootingTurret::aquire_target);
        connect(turretTimer, &QTimer::timeout, turret, &ShootingTurret::decTimeToLive);
        connect(this, &Game::destroyAllTurretsAndProjectiles, turret, &ShootingTurret::destroyMeFunct);
        connect(this, &Game::getTurretPosition, turret, &ShootingTurret::getMyPosition);
        connect(turret, &ShootingTurret::myPosition, this, &Game::addTurretPosition);
        connect(turret, &ShootingTurret::showUpgradeButton, this, &Game::showUpgradeButton);
        connect(turret, &ShootingTurret::hideUpgradeButton, this, &Game::hideUpgradeButton);

        turretNb++;
    }
}

//this funct shows/hides the zone to place turrets
void Game::showTurretZones()
{
    if(turretZonesVisible)
    {
        turretZone1->hide();
        turretZone2->hide();
        turretZone3->hide();
        turretZone4->hide();
        turretZone5->hide();
        turretZone6->hide();
        turretZonea->hide();
        turretZoneb->hide();
        turretZonec->hide();
        turretZoned->hide();
        turretZonesVisible=false;
    }
    else
    {
        turretZone1->show();
        turretZone2->show();
        turretZone3->show();
        turretZone4->show();
        turretZone5->show();
        turretZone6->show();
        turretZonea->show();
        turretZoneb->show();
        turretZonec->show();
        turretZoned->show();
        turretZonesVisible=true;
    }
}

//Add a turrets position in the list to check if we don't add a turret over another in addTurret()
void Game::addTurretPosition(QPoint p)
{
    turretPositions.append(p);
}

//Asks all the turrets for their position
void Game::fillTurretPositions()
{
    turretPositions.clear();
    emit getTurretPosition();
}

//When a turret is selected, it emits a signal that call this function
//the upgrade button is moved uder the turret, and the click of the button is connected
//to the upGrade funct of the selected turret
void Game::showUpgradeButton(ShootingTurret* turret)
{
    connect(upgradeButton, &QPushButton::clicked, turret, &ShootingTurret::upGrade);
    upgradeButton->setGeometry(turret->x(), turret->y()+35, turretButtonWidth, turretButtonHeight);
    upgradeButton->show();
}

//When a turret is unselected, disconnect the upgrade button from the turret
//and hide the upgradebutton
void Game::hideUpgradeButton(ShootingTurret* turret)
{
    disconnect(upgradeButton, &QPushButton::clicked, turret, &ShootingTurret::upGrade);
    upgradeButton->hide();
}

//Update the money when the upgradeButton is clicked
void Game::payAnUpgrade()
{
    updateMoney(-upgradePrice);
}

void Game::accelerate()
{
    if(!doubleSpeed)
    {
        doubleSpeed=true;
        moveTimer->setInterval(1);
        spawnTimer->setInterval(enemySpawnPeriod/2);
        timeTimer->setInterval(100);
        turretTimer->setInterval(750);
        projectileTimer->setInterval(5);
        accelerateButton->setText("x1");
    }
    else
    {
        doubleSpeed=false;
        moveTimer->setInterval(2);
        spawnTimer->setInterval(enemySpawnPeriod);
        timeTimer->setInterval(200);
        turretTimer->setInterval(1500);
        projectileTimer->setInterval(10);
        accelerateButton->setText("x2");
    }
}
