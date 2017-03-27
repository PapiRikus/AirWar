#include "GameWindow.h"

/**
 * @brief GameWindow::GameWindow - Constructor of the class
 * @param parent -
 */
GameWindow::GameWindow(QWidget *parent): QMainWindow(parent) {

    //The tittle of the window is defined
    this->setWindowTitle("Air War");
    //The size of the window is defined
    this->setFixedSize(1200,800);


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
        qDebug() << "Right key";
    }

    //Checks if the player press the "left key"
    else if(event->key() == Qt::Key_Left) {
        qDebug() << "Left key";
    }

    //Checks if the player press the "space key"
    else if(event->key() == Qt::Key_Space) {
        qDebug() << "Shoot";
    }

    //Checks if the player press the "Z key"
    else if(event->key() == Qt::Key_Z) {
        qDebug() << "Game Paused!";
    }

}
