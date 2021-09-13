#ifndef GAME_H
#define GAME_H
#include <QVector>
#include <QWidget>
#include <QTimer>
#include <QGraphicsView>
#include <ennemy.h>
#include <place.h>
#include <ally.h>
#include <player.h>
#include <spritedealer.h>
#include <QPushButton>
#include <allydialog.h>
#include <questiondialog.h>
#include <questiondealer.h>
#include <background.h>
#include <QMediaPlayer>
#include <QIcon>
#include <QCloseEvent>
#include <clicklabel.h>
#include <shootingturret.h>
#include <projectile.h>
#include <turretzone.h>

class Game: public QGraphicsView
{

    Q_OBJECT

public:
    Game(int, int);

//    ~Game();

private slots:
    void spawnEnnemy();
    void spawnAlly(int, int);
    void moveStep();
    void partySteps();          //lance les 4 methodes d'update durant le jeu
    void cleanGameSteps();
    void startTimers();
    void stopTimers();
    void winning();
    void loosing();
    void dialogAlly();
    void drinkCoffee();
    void useHeadPhones();
    void scream();
    void updateTimeAndCourse(); //verifie aussi si on a gagner
    void updateSpriteAndKill();
    void updatePlayerSpriteAndBackground();
    void updateGraphicInfos();
    void updateDamage();
    void updateMoney(int);
    void updateQuestions();
    void answereQuestion(bool, int);
    void playerLeaves();
    void updateMusic();     //loop la musique, gère le volume
    void pause();
    void addProjectile(Projectile*);
    void addTurret(QPoint, TurretZone*);
    void destroyProjectile(Projectile*);
    void destroyTurret(ShootingTurret*);
    void showTurretZones();
    void addTurretPosition(QPoint);
    void fillTurretPositions();
    void showUpgradeButton(ShootingTurret*);
    void hideUpgradeButton(ShootingTurret*);
    void payAnUpgrade();
    void accelerate();
//    void closeEvent(QCloseEvent*);

signals:
    void destroyAllTurretsAndProjectiles();
    void getTurretPosition();
//    void hasBeenClosed();

private:
    QVector<Place*> places;
    Place * selectedPlace;
    //QVector<TurretSpot> turretSports;
    QVector<Enemy*> ennemies;
    QVector<Ally*> allies;
    QTimer* moveTimer;          //gère le déplacement des npc
    QTimer* spawnTimer;         //spawn les ennemis
    QTimer* timeTimer;          //gere le temps qui passe, les dégats entre alliés et ennemis et la destruction s des npc hors de la map.
                                //gere aussi la mise a jour des sprites, NE PAS MODIFIER LES 200MS
                                //mise a jour du focus, de lavancement de la matiere, du timer
    QGraphicsScene *scene;
    Player * player;
    int parWidth, parHeight;
    int time;                   //1 unit: 200ms
    int npcSize;
    int money;
    double courseAdvancementFactor;            //facteur qui multiplie foc/focMax qui est ajouter a course
    double focusFactor;                        //facteur qui multiplie l'effets des ennemis sur notre focus
    int enemySpawnPeriod;
    SpriteDealer* sd;
    SpriteDealer* sdNormal;
    SpriteDealer* sdBig;
    SpriteDealer* sdBigPhatFuck;
    Background * background;

    //gestion d'ennemis envoyés
    int enemyKillEarning;
    int enemyLvl=1;
    int enemySent=0;

    //barre de concentration
    QGraphicsRectItem* focusBackground;
    QGraphicsRectItem* focusForeground;
    QGraphicsTextItem* focusTextItem;
    int pensize;
    int focusWidth;
    int focusHeight;
    int focusX;
    int focusY;

    //avancement matière
    double courseMax;
    double course;
    QGraphicsRectItem* courseBackground;
    QGraphicsRectItem* courseForeground;
    int courseWidth;
    int courseHeight;
    int courseX;
    int courseY;

    //affichage du temps
    QGraphicsTextItem* timeTextItem;
    int timeX;
    int timeY;

    //affichage du temps ecouteurs
    QGraphicsTextItem* headPhonesTextItem;
    int headPhonesTime;
    int headPhonesX;
    int headPhonesY;

    //affichage du caffe
    QGraphicsTextItem* coffeeTextItem;
    int coffeeBoost;
    int coffeeX;
    int coffeeY;

    //affichage de la thune
    QGraphicsTextItem* moneyTextItem;
    int moneyX;
    int moneyY;

    //bouton spawn allié
    int allieButtonX;
    int allieButtonY;
    int allieButtonWidth;
    int allieButtonHeight;
    QPushButton* allieButton;
    AllyDialog* allyDialog;

    //bouton cafe
    int coffeePrice;
    int coffeeButtonX;
    int coffeeButtonY;
    int coffeeButtonWidth;
    int coffeeButtonHeight;
    QPushButton* coffeeButton;

    //bouton ecouteurs
    int headPhonesPrice;
    int headPhonesDuration;
    int headPhonesButtonX;
    int headPhonesButtonY;
    int headPhonesButtonWidth;
    int headPhonesButtonHeight;
    QPushButton* headPhonesButton;

    //bouton crier
    int screamPrice;
    int screamDuration;
    int screamButtonX;
    int screamButtonY;
    int screamButtonWidth;
    int screamButtonHeight;
    QPushButton* screamButton;

    //Questions bonus
    int category;
    int questionCount=0;
    int questionFrequency;
    int timeBoostQuestion;
    QuestionDialog* questionDialog;
    QuestionDealer qd;

    //music
    QMediaPlayer * gameMusic;
    QMediaPlayer * ambiantSound;
    QMediaPlayer * coffeeSound;
    QMediaPlayer * screamSound;
    QMediaPlayer * paperPlaneSound;
    QString soundsPath;
    QTimer * musicTimer;

    //win/loose animation flag
    bool state3Flage=true;

    //animated icon
    int animatedIconState=0;

    //pauseButton
    ClickLabel * pauseLabel;
    bool gamePaused=false;
    Background * pauseBackground;

    //turret
    ShootingTurret * turret;
    TurretZone * turretZone1;
    TurretZone * turretZone2;
    TurretZone * turretZone3;
    TurretZone * turretZone4;
    TurretZone * turretZone5;
    TurretZone * turretZone6;
    TurretZone * turretZonea;
    TurretZone * turretZoneb;
    TurretZone * turretZonec;
    TurretZone * turretZoned;

    int turretPrice;
    int turretDuration;
    int turretButtonX;
    int turretButtonY;
    int turretButtonWidth;
    int turretButtonHeight;
    bool turretZonesVisible=false;
    QPushButton* turretButton;
    QPushButton* upgradeButton;
    QTimer* turretTimer;
    QTimer* projectileTimer;
    int turretNb=0;
    QVector<QPoint> turretPositions;
    int upgradePrice;

    //accelerate
    bool doubleSpeed=false;
    QPushButton* accelerateButton;
    int accelerateButtonX;
    int accelerateButtonY;
    int accelerateButtonWidth;
    int accelerateButtonHeight;


};

#endif // GAME_H
