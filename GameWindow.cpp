#include "GameWindow.h"

/**
 * @brief GameWindow::GameWindow - Constructor of the class
 * @param parent -
 */
GameWindow::GameWindow(QWidget *parent): QGraphicsView(parent) {

    //The tittle of the window is defined
    this->setWindowTitle("Air War");
    //The size of the window is defined
    this->setFixedSize(1200, 800);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // -- TEMPORAL --
    this->setStyleSheet("background-color:blue;");
    // -- TEMPORAL --

    //A Scene to handle the graphics of the game is created (It's like a container)
    this->gameScene = new QGraphicsScene(this);
    //The size of the Scene is defined
    gameScene->setSceneRect(0, 0, 1200, 800);
    //Associate the scene with the game window
    this->setScene(gameScene);

    //Tha player is created
    this->player = new Player("nacho", 550, 780, 100, 100);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //Add the player to the game scene
    gameScene->addItem(player);

    // -- TEMPORAL --
    QTimer* timer = new  QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(spawnEnemys()));
    timer->start(2000);
    // -- TEMPORAL --

}


/**
 * @brief GameWindow::~GameWindow - Destructor of the class
 */
GameWindow::~GameWindow() {

}


/**
 * @brief GameWindow::keyPressEvent - Function that receives keyboard events
 * @param event - A type of key event that is occurring
 */
void GameWindow::keyPressEvent(QKeyEvent *event) {

    //Checks if the player press the "right key"
    if(event->key() == Qt::Key_Right) {
        //Move the player to the right
        this->player->moveRight();
    }

    //Checks if the player press the "left key"
    else if(event->key() == Qt::Key_Left) {
        //Move the player to the left
        this->player->moveLeft();
    }

    //Checks if the player press the "space key"
    else if(event->key() == Qt::Key_Space) {
        //If the player want to shoot
        Bullet* bullet = new Bullet(player->x(), player->y(), 10, 50);
        //Add the Bullet to the game scene
        gameScene->addItem(bullet);

    }

    //Checks if the player press the "P key"
    else if(event->key() == Qt::Key_P) {
        qDebug() << "Game Paused!";
    }

}



/**
 * @brief GameWindow::spawnEnemys - Function that creates the enemies on screen
 */
void GameWindow::spawnEnemys() {

    int random_number = rand() % 1200;

    Enemy* enemy = new Enemy(1, random_number, 0);
    gameScene->addItem(enemy);


}

