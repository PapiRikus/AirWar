#include "LogginWindow.h"

/**
 * @brief LogginWindow::LogginWindow - Constructor of the class
 * @param parent -
 */
LogginWindow::LogginWindow(QWidget *parent): QMainWindow(parent) {

    //The tittle of the window is defined
    this->setWindowTitle("Air War");
    //The size of the window is defined
    this->setFixedSize(600, 500);

    //A Frame to place the Widgets of the window is created
    this->frameLogginWindow = new QFrame(this);
    //The size of the Frame is defined
    frameLogginWindow->setFixedSize(600,500);

    //A Label to place the logo of the game is created
    this->airWarLogoImage = new QLabel(frameLogginWindow);
    //The corresponding image is associated with the Label
    airWarLogoImage->setPixmap(QPixmap("/home/ignacio/Qt Projects/AirWar/airWarLogo.png"));
    //The size of the label is defined in order that it adjust to the size of the image and places
    //in the position determined in screen
    airWarLogoImage->setGeometry(90,95,415,100);

    //A Label to place a message for the player is created
    this->nameTextMessage = new QLabel(frameLogginWindow);
    //The content of the message is defined
    nameTextMessage->setText("Welcome, please enter your name:");
    //The size of the Label adjusted in order that the message fits well
    nameTextMessage->adjustSize();
    //The Label is placed in a position determined in the screen
    nameTextMessage->move(177,250);

    //A text box is created for the player to enter his name
    this->playerNameTextBox = new QLineEdit(frameLogginWindow);
    //The size of the text box is defined
    playerNameTextBox->resize(250,35);
    //The text box is placed in the position determined in the screen
    playerNameTextBox->move(175,280);

    //A Button to start the game is created
    this->playButton = new QPushButton(frameLogginWindow);
    //The text of the Button is defined
    playButton->setText("Play");
    //The Buttons are placed in a position determined in the screen
    playButton->move(470,440);

    //Connect the click of the play button with an action to perform
    connect(playButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));

}


/**
 * @brief LogginWindow::~LogginWindow - Destructor of the class
 */
LogginWindow::~LogginWindow() {

}


/**
 * @brief LogginWindow::buttonClicked - Function that detects is the start game button is pressed
 */
void LogginWindow::buttonClicked() {

    //Verify that the user enters a name
    if(!playerNameTextBox->text().isEmpty()) {

        qDebug() << "Start Game!";

        //Hide the loggin window
        this->hide(); //???????????

        //The window of the game is created
        GameWindow* game = new GameWindow();
        //The game window is displayed
        game->show();


    }
    //If the user does not enter a name
    else{

        //Display a warning message asking the user to enter a name
        QMessageBox::warning(this, tr("Ups"), tr("¡Please enter a name!"));

    }

}
