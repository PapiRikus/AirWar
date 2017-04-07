#include "GameWindow.h"
#include <QDebug>

Server* server;

/**
 * @brief GameWindow::GameWindow - Constructor of the class
 * @param parent -
 */
GameWindow::GameWindow(QString pPlayerName, bool pMobileControl, QWidget *parent): QGraphicsView(parent) {

    //The tittle of the window is defined
    this->setWindowTitle("Air War");
    //The size of the window is defined
    this->setFixedSize(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);

    //Disables the horizontal and vertical scroll of the screen
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //A Scene to handle the graphics of the game is created (It's like a container)
    this->_gameScene = new QGraphicsScene(this);
    //The size of the Scene is defined
    this->_gameScene->setSceneRect(0, 0, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);
    //Associate the scene with the game window
    this->setScene(this->_gameScene);

    //
    this->_gameScene->setBackgroundBrush(QBrush(QImage(":/images/FondoLejos.png"))); // -- Fondo --

    //
    this->_mobileControl = pMobileControl;

    //Tha player is created
    this->_player = new Player(pPlayerName, GAME_WINDOW_WIDTH/2, (GAME_WINDOW_HEIGHT/2) + 200);
    //
    this->_player->setFlag(QGraphicsItem::ItemIsFocusable);
    //
    this->_player->setFocus();

    //Add the player to the game scene
    this->_gameScene->addItem(this->_player);

    //The state of the game is defined, at the beginning the user is playing
    this->_gameOnPause = false;

    //If the player is using a mobile control
    if(this->_mobileControl) {
       //The server is created
       server = new Server();
       //The server initializes
       server->StartServer();
       //A timer to checking for server input data is created
       this->_serverCallTimer = new QTimer(this);
       //Associated the timer with the funtion of receiving data
       connect(this->_serverCallTimer, SIGNAL(timeout()), this, SLOT(mobileControlEvent()));
       //The call time is defined
       this->_serverCallTimer->start(10);
    }

    //The player statictics are displayed on the screen
    drawStatistics();

    //A timer to handle the time from calling moving and collision functions is created
    this->_moveTimer = new QTimer(this);
    //Asssociates the timer with the function of moving enemies
    connect(this->_moveTimer, SIGNAL(timeout()), this, SLOT(moveEnemies()));
    //Associates the timer with the function of moving bullets
    connect(this->_moveTimer, SIGNAL(timeout()), this, SLOT(moveBullets()));
    //Associates the timer with the function of moving power ups
    connect(this->_moveTimer, SIGNAL(timeout()), this, SLOT(movePowerUps()));
    //Associates the timer with the function to detect collisions
    connect(this->_moveTimer, SIGNAL(timeout()), this, SLOT(detectCollisions()));
    //The call time is defined
    this->_moveTimer->start(40);

    //A timer to handle the time from calling the shooting function of the enemies, is created
    this->_shootEnemyTimer = new QTimer(this);
    //Associates the timer with the shooting function
    connect(this->_shootEnemyTimer, SIGNAL(timeout()), this, SLOT(enemiesShoot()));
    //The call time is defined
    this->_shootEnemyTimer->start(1500);

    // -- TEMPORAL --
    this->_spawnTimer = new  QTimer(this);
    //connect(this->_spawnTimer, SIGNAL(timeout()), this, SLOT(spawnEnemies()));
    this->_spawnTimer->start(2000);
    // -- TEMPORAL --

}


/**
 * @brief GameWindow::~GameWindow - Destructor of the class
 */
GameWindow::~GameWindow() {

}


/**
 * @brief GameWindow::drawStatistics - Function that draws the player statictics on screen
 */
void GameWindow::drawStatistics() {

    //If the player is not using a mobile control
    if(!this->_mobileControl) {
        //
        this->_playerNameText = new QGraphicsTextItem();
        //
        this->_playerNameText->setPlainText(QString("Name: " + this->_player->getName()));
        //
        this->_playerNameText->setDefaultTextColor(Qt::blue);
        //
        this->_playerNameText->setFont(QFont("times", 16));
        //
        this->_gameScene->addItem(this->_playerNameText);

        //
        this->_playerLivesText = new QGraphicsTextItem();
        //
        this->_playerLivesText->setPlainText(QString("Lives: " + QString::number(this->_player->getLives())));
        //
        this->_playerLivesText->setDefaultTextColor(Qt::red);
        //
        this->_playerLivesText->setFont(QFont("times", 16));
        //
        this->_playerLivesText->setPos(0, 30);
        //
        this->_gameScene->addItem(this->_playerLivesText);

        //
        this->_playerScoreText = new QGraphicsTextItem();
        //
        this->_playerScoreText->setPlainText(QString("Score: ") + QString::number(this->_player->getScore()));
        //
        this->_playerScoreText->setDefaultTextColor(Qt::green);
        //
        this->_playerScoreText->setFont(QFont("times", 16));
        //
        this->_playerScoreText->setPos(0, 60);
        //
        this->_gameScene->addItem(this->_playerScoreText);
    }
    //If the player is not using a mobile control
    else {

        // -- dibujar datos iniciales en el telefono

    }
    //A Label to place the pause logo of the game is created
    this->_airWarPauseLogoImage = new QGraphicsPixmapItem();
    //The corresponding image is associated with the item
    this->_airWarPauseLogoImage->setPixmap(QPixmap(":/images/pausedGameLogo.png"));
    //The item is placed in the position determined in screen
    this->_airWarPauseLogoImage->moveBy((GAME_WINDOW_WIDTH / 2) - 180 , (GAME_WINDOW_HEIGHT / 2) - 70);

}


/**
 * @brief GameWindow::keyPressEvent - Function that receives keyboard events
 * @param event - A type of key event that is occurring
 */
void GameWindow::keyPressEvent(QKeyEvent* event) {

    //If the player is not using a mobile control
    if(!(this->_mobileControl)) {
        if(!(this->_gameOnPause)) {
            //Checks if the player presses the "up key"
            if(event->key() == Qt::Key_Up) {
                //If the player has not passed the top limit of the screen
                if(this->_player->y() > 0) {
                    //Move the player up
                    this->_player->moveUp();
                }
            }
            //Checks if the player presses the "down key"
            else if(event->key() == Qt::Key_Down) {
                //If the player has not passed the down limit of the screen
                if((this->_player->y() + this->_player->getHeight()) < GAME_WINDOW_HEIGHT) {
                    //Move the player down
                    this->_player->moveDown();
                }
            }
            //Checks if the player presses the "right key"
            else if(event->key() == Qt::Key_Right) {
                //If the player has not passed the right limit of the screen
                if((this->_player->x() + this->_player->getWidth()) < GAME_WINDOW_WIDTH) {
                    //Move the player to the right
                    this->_player->moveRight();
                }
            }
            //Checks if the player presses the "left key"
            else if(event->key() == Qt::Key_Left) {
                //If the player has not passed the left limit of the screen
                if(this->_player->x() > 0) {
                    //Move the player to the left
                    this->_player->moveLeft();
                }
            }
            //Checks if the player presses the "space key", makes the player shoot
            else if(event->key() == Qt::Key_Space) {
                //A new Bullet is created
                Bullet* bullet = new Bullet(this->_player->getWeaponType(), this->_player->x() + (this->_player->getWidth() / 2) - 11, this->_player->y());
                //The Bullet is added to the player bullet list
                this->_bulletsList.append(bullet);
                //The Bullet is added to the game scene
                this->_gameScene->addItem(bullet);
            }
            //Checks if the player presses the "A key"
            else if(event->key() == Qt::Key_A) {
                //The player activated a power up
                this->_player->activatePowerUp();
            }
        }
        //Checks if the player presses the "Z key"
        if(event->key() == Qt::Key_Z) {
            //If the game is not paused (user is playing)
            if(!(this->_gameOnPause)) {
                //Pause the game
                pauseGame();
            }
            //If the game is paused (user is not playing)
            else{
                //Cancels the game pause
                quitPauseGame();
            }
        }
    }

}


/**
 * @brief GameWindow::checkBulletsColisions - Function that helps detect the collision of bullets with enemies
 * @param pBullet - A bullet to check
 */
void GameWindow::checkBulletsColisions(Bullet* pBullet) {

    //If the game has enemies in play
    if(!this->_enemiesList.isEmpty()) {
        //Move through the enemies list of the game
        for(int i = 0; i < this->_enemiesList.size(); i++) {
            //If the bullet collides with the current enemy and the bullet is from the player
            if(pBullet->collidesWithItem(this->_enemiesList[i]) && (0 != pBullet->getType()) && (3 != pBullet->getType())) {
                //Remove the bullet from the game scene
                this->_gameScene->removeItem(pBullet);
                //Remove the bullet from the bullets list of the game
                this->_bulletsList.removeOne(pBullet);
                //The life of the current enemy is decreased
                this->_enemiesList[i]->decreaseLifePoints(pBullet->getDamage());
                //Check if the current enemy has lives
                if(0 >= this->_enemiesList[i]->getLifePoints()) {
                    //Increase the player score
                    this->_player->increaseScore(this->_enemiesList[i]->getScoreValue());
                    //Update the player score on the screen
                    updatePlayerScoreOnScreen();
                    //If the player score is divisible by 100
                    if(0 == (this->_player->getScore() % 100)) {
                        //Increase the lives of the player
                        this->_player->increaseLives();
                        //Update the player lives on screen
                        updatePlayerLivesOnScreen();
                        //Check is the current enemy is carry a power up
                        if(this->_enemiesList[i]->isCarryPowerUp()) {
                            //A new Power Up is created
                            PowerUp* newPowerUp = new PowerUp(this->_enemiesList[i]->x(), this->_enemiesList[i]->y());
                            //The power up is added to the game scene
                            this->_gameScene->addItem(newPowerUp);
                            //The power up is added to the game power up list
                            this->_powerUpsList.append(newPowerUp);
                        }
                        //Remove the current enemy from the game scene
                        this->_gameScene->removeItem(this->_enemiesList[i]);
                        //Remove the current enemy from the game enemies list
                        this->_enemiesList.removeOne(this->_enemiesList[i]);
                    }
                    //Leaves the cycle because the bullet collided
                    break;
                }
            }
        }
    }

}

/**
 * @brief GameWindow::mobileControlEvent - Function that receives the inputs from the server if the player uses mobile control
 */
void GameWindow::mobileControlEvent() {

    //If the player is within the limits of the game screen
    if((this->_player->x() > 0) && ((this->_player->x() + this->_player->getWidth()) < GAME_WINDOW_WIDTH) &&
        (this->_player->y() > 0) && ((this->_player->y() + this->_player->getHeight()) < GAME_WINDOW_HEIGHT)) {
        //Moves the player through the screen
        this->_player->move(server->getData(1), server->getData(0));
    }
    //
    else if(!(this->_player->x() > 0)) {
        //
        this->_player->move(1, server->getData(0));
    }
    //
    else if(!((this->_player->x() + this->_player->getWidth()) < GAME_WINDOW_WIDTH)) {
        //
        this->_player->move(-1, server->getData(0));
    }
    //
    else if(!(this->_player->y() > 0)) {
        //
        this->_player->move(server->getData(1), 1);
    }
    //
    else if(!((this->_player->y() + this->_player->getHeight()) < GAME_WINDOW_HEIGHT)) {
        //
        this->_player->move(server->getData(1), -1);
    }

    //If the player wants to shoot
    if(1 == server->getData(2)) {
        //A new Bullet is created
        Bullet* bullet = new Bullet(this->_player->getWeaponType(), this->_player->x() + (this->_player->getWidth() / 2) - 11, this->_player->y());
        //The Bullet is added to the player bullet list
        this->_bulletsList.append(bullet);
        //The Bullet is added to the game scene
        this->_gameScene->addItem(bullet);
    }

    // --- activar power ups

}


/**
 * @brief GameWindow::updatePlayerScoreOnScreen - Function that updates on screen the score of the player
 */
void GameWindow::updatePlayerScoreOnScreen() {

    //If the player is not using a mobile control
    if(!this->_mobileControl) {
        //Update the player's score on screen
        this->_playerScoreText->setPlainText(QString("Score: ") + QString::number(_player->getScore()));
    }
    //If the player is using a mobile control
    else {

        // -- mandar dato a la pantalla del telefono

    }

}


/**
 * @brief GameWindow::updatePlayerLivesOnScreen - Function that updates on screen the lives of the player
 */
void GameWindow::updatePlayerLivesOnScreen() {

    //If the player is not using a mobile control
    if(!this->_mobileControl) {
        //Update the player's lives on screen
        this->_playerLivesText->setPlainText((QString("Lives: " + QString::number(this->_player->getLives()))));
    }
    //If the player is using a mobile control
    else {

        // -- mandar dato a la pantalla del telefono

    }

}


/**
 * @brief GameWindow::pauseGame - Function that pauses the game
 */
void GameWindow::pauseGame() {

    //
    disconnect(this->_moveTimer, SIGNAL(timeout()), this, SLOT(moveEnemies()));
    //
    disconnect(this->_moveTimer, SIGNAL(timeout()), this, SLOT(moveBullets()));
    //
    disconnect(this->_moveTimer, SIGNAL(timeout()), this, SLOT(movePowerUps()));
    //
    disconnect(this->_moveTimer, SIGNAL(timeout()), this, SLOT(detectCollisions()));
    //
    disconnect(this->_spawnTimer, SIGNAL(timeout()), this, SLOT(spawnEnemies()));
    //
    this->_gameScene->addItem(this->_airWarPauseLogoImage);
    //
    this->_gameOnPause = true;

}


/**
 * @brief GameWindow::quitPauseGame - Function that cancels game pause
 */
void GameWindow::quitPauseGame() {

    //
    connect(this->_moveTimer, SIGNAL(timeout()), this, SLOT(moveEnemies()));
    //
    connect(this->_moveTimer, SIGNAL(timeout()), this, SLOT(moveBullets()));
    //
    connect(this->_moveTimer, SIGNAL(timeout()), this, SLOT(movePowerUps()));
    //
    connect(this->_moveTimer, SIGNAL(timeout()), this, SLOT(detectCollisions()));
    //
    connect(this->_spawnTimer, SIGNAL(timeout()), this, SLOT(spawnEnemies()));
    //
    this->_gameScene->removeItem(this->_airWarPauseLogoImage);
    //
    this->_gameOnPause = false;

}


/**
 * @brief GameWindow::gameOver - Function that hepls in decisions if the player lose the game
 */
void GameWindow::gameOver() {

    QMessageBox::StandardButton restartGame;

    restartGame = QMessageBox::question(this, "Game Over", "Restart Game?\n holaaaa",
                                        QMessageBox::Yes | QMessageBox::No);


    if(restartGame == QMessageBox::Yes){
        qDebug() << "Restart Game";
    }

    else{

        this->close();

    }
}


/**
 * @brief GameWindow::enemiesMove - Funtion that moves enemies through the screen
 */
void GameWindow::moveEnemies() {

    //If the game has enemies in play
    if(!this->_enemiesList.isEmpty()) {
        //Move through the Enemies list
        for(int i = 0; i < this->_enemiesList.size(); i++) {
            //If the current enemy is a Jet Kamikaze
            if(4 == this->_enemiesList[i]->getType()) {
                //Move the current enemy to the current position of the player
                this->_enemiesList[i]->moveToPlayerPosition(this->_player->x());
            }
            //If current enemy is of another type
            else {
                //Move the current enemy
                this->_enemiesList[i]->move();
            }
        }
    }

}


/**
 * @brief GameWindow::enemiesShoot - Function that makes enemies shoot
 */
void GameWindow::enemiesShoot() {

    //If the game has enemies in play
    if(!this->_enemiesList.isEmpty()) {
        srand(time(NULL));
        //Move throught the Enemies list
        for(int i = 0; i < this->_enemiesList.size(); i++) {
            //If the current enemy is not a Jet Kamikaze
            if(4 != this->_enemiesList[i]->getType()) {
                //Choose a random number to know if the enemy is going to shoot
                if(1 == (1 + rand() % 2)){
                    int aa=0;
                    if (_enemiesList[i]->getType()==3){
                        aa=3;
                    }
                    //A new Bullet is created and makes the current enemy  shoot
                    Bullet* bullet = new Bullet(aa, this->_enemiesList[i]->x() + (this->_enemiesList[i]->getWidth() / 2) - 11, this->_enemiesList[i]->y()+40);
                    //The Bullet is added to the player bullet list
                    this->_bulletsList.append(bullet);
                    //The Bullet is added to the game scene
                    this->_gameScene->addItem(bullet);
                }
            }
        }
    }


}


/**
 * @brief GameWindow::bulletsMove - Function that moves all the Bullets through the screen
 */
void GameWindow::moveBullets() {

    //If the game has Bullets in play
    if(!this->_bulletsList.isEmpty()) {
        //Move through the Bullets list
        for(int i = 0; i < this->_bulletsList.size(); i++) {
            //
            if(3 == this->_bulletsList[i]->getType()){
                //
                this->_bulletsList[i]->moveToPlayer(_player->x(),0);
            }
            //Move the curren Bullet
            this->_bulletsList[i]->move();
        }
    }

}


/**
 * @brief GameWindow::powerUpMove - Function that moves all the PowerUps through the screen
 */
void GameWindow::movePowerUps() {

    //If the game has PowerUps in play
    if(!this->_powerUpsList.isEmpty()) {
        //Move through the PowerUps list
        for(int i = 0; i < this->_powerUpsList.size(); i++) {
            //Move the curret PowerUp
            this->_powerUpsList[i]->move();
        }
    }

}


/**
 * @brief GameWindow::detectCollisions - Function that takes charge of detecting all the collisions of the game
 */
void GameWindow::detectCollisions() {

    //If the game has enemies in play
    if(!this->_enemiesList.isEmpty()) {
        //Move through the enemies list of the game
        for(int i = 0; i < this->_enemiesList.size(); i++) {
            //If the current enemy leaves the screen
            if(this->_enemiesList[i]->y() > GAME_WINDOW_HEIGHT) {
                //Remove the current enemy from the game scene
                this->_gameScene->removeItem(this->_enemiesList[i]);
                //Remove the current enemy from the game enemies list
                this->_enemiesList.removeOne(this->_enemiesList[i]);
                //Continue with the next enemy in the list
                continue;
            }
            //If the current Enemy collides with the player and the player has no shield activated
            if(this->_enemiesList[i]->collidesWithItem(this->_player) && !this->_player->haveShield()) {
                //Remove the current enemy from the game scene
                this->_gameScene->removeItem(this->_enemiesList[i]);
                //Remove the current enemy from the game enemies list
                this->_enemiesList.removeOne(this->_enemiesList[i]);
                //The life of the player is decreased
                this->_player->decreaseLives();
                //Update the player lives on the screen
                updatePlayerLivesOnScreen();
                //Check if the player has lives
                if(0 == this->_player->getLives()) {
                    qDebug() << "Game Over";
                }
            }
        }
    }
    //If the game has power ups in play
    if(!this->_powerUpsList.isEmpty()) {
        //Move through the power up list of the game
        for(int i = 0; i < this->_powerUpsList.size(); i++) {
            //If the power up leaves the screen
            if(this->_powerUpsList[i]->y() > GAME_WINDOW_HEIGHT) {
                //Remove the current power up from the game scene
                this->_gameScene->removeItem(this->_powerUpsList[i]);
                //Remove the current power up from the game power up list
                this->_powerUpsList.removeOne(this->_powerUpsList[i]);
                //Continue with the next power up in the list
                continue;
            }
            //If the current power up collides with the player
            if(this->_powerUpsList[i]->collidesWithItem(this->_player)) {
                //Passed the current power up to the player
                this->_player->receivePowerUp(this->_powerUpsList[i]);
                //Remove the current power up from the game scene
                this->_gameScene->removeItem(this->_powerUpsList[i]);
                //Remove the current power up from the game power up list
                this->_powerUpsList.removeOne(this->_powerUpsList[i]);
            }
        }
    }
    //If the game has bullets in play
    if(!this->_bulletsList.isEmpty()) {
        //Move through the Bullets list of the game
        for(int i = 0; i < this->_bulletsList.size(); i++) {
            //If the Bullets leaves the screen (top and down limit)
            if((this->_bulletsList[i]->y() < 0) || (this->_bulletsList[i]->y() > GAME_WINDOW_HEIGHT)) {
                //Remove the current Bullet from the game scene
                this->_gameScene->removeItem(this->_bulletsList[i]);
                //Remove the current Bullet from the game bullets list
                this->_bulletsList.removeOne(this->_bulletsList[i]);
                //Continue with the next Bullet in the list
                continue;
            }
            //If the current bullet collides with the player and the bullet is from the enemy and the player has no shield activated
            if((this->_bulletsList[i]->collidesWithItem(this->_player)) && ((0 == this->_bulletsList[i]->getType()) || (3 == this->_bulletsList[i]->getType())) && !this->_player->haveShield()) {
                //Remove the bullet from the game scene
                this->_gameScene->removeItem(this->_bulletsList[i]);
                //Remove the bullet from the bullets list of the game
                this->_bulletsList.removeOne(this->_bulletsList[i]);
                //The life of the player is decreased
                this->_player->decreaseLives();
                //Update the player life on the screen
                updatePlayerLivesOnScreen();
                //Check if the player has lives
                if(0 == this->_player->getLives()) {
                    qDebug() << "Game Over";
                }
                //Continue with the next Bullet in the list
                continue;
            }
            //Check if the current bullet will collides an enemy
            checkBulletsColisions(this->_bulletsList[i]);
        }
    }

}


/**
 * @brief GameWindow::spawnEnemys - Function that creates the enemies on screen - "OJO" / TEMPORAL
 */
void GameWindow::spawnEnemies() {

    int random_number = rand() % 1200;
    int random_type = 1 + rand() % 4;

    //random_type = 3;

    Enemy* enemy = new Enemy(random_type, random_number, 0);

    this->_gameScene->addItem(enemy);
    this->_enemiesList.append(enemy);


}
