#include "LogginWindow.h"

/**
 * @brief LogginWindow::LogginWindow - Constructor of the class
 * @param parent -
 */
LogginWindow::LogginWindow(QWidget *parent): QMainWindow(parent) {

    //The tittle of the window is defined
    this->setWindowTitle("Air War");
    //The size of the window is defined
    this->setFixedSize(LOGGIN_WINDOW_WIDTH, LOGGIN_WINDOW_HEIGHT);

    //A Frame to place the Widgets of the window is created
    this->_frameLogginWindow = new QFrame(this);
    //The size of the Frame is defined
    this->_frameLogginWindow->setFixedSize(LOGGIN_WINDOW_WIDTH, LOGGIN_WINDOW_HEIGHT);

    //Draw the components of the window
    drawComponents();

    //Connect the click of the play button with an action to perform
    connect(this->_playButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));

}


/**
 * @brief LogginWindow::~LogginWindow - Destructor of the class
 */
LogginWindow::~LogginWindow() {

}


/**
 * @brief LogginWindow::drawComponents - Function that draws the components of the Loggin screen
 */
void LogginWindow::drawComponents() {

    //A Label to place the logo of the game is created
    this->_airWarLogoImage = new QLabel(this->_frameLogginWindow);
    //The corresponding image is associated with the Label
    this->_airWarLogoImage->setPixmap(QPixmap(":/images/airWarLogo.png"));
    //The size of the label is defined in order that it adjust to the size of the image and places
    //in the position determined in screen
    this->_airWarLogoImage->setGeometry(90,95,415,100);

    //A Label to place a message for the player is created
    this->_nameTextMessage = new QLabel(this->_frameLogginWindow);
    //The content of the message is defined
    this->_nameTextMessage->setText("Welcome, please enter your name:");
    //The size of the Label adjusted in order that the message fits well
    this->_nameTextMessage->adjustSize();
    //The Label is placed in a position determined in the screen
    this->_nameTextMessage->move(177,250);

    //A text box for the player to enter his name is created
    this->_playerNameTextBox = new QLineEdit(this->_frameLogginWindow);
    //The size of the text box is defined
    this->_playerNameTextBox->resize(250,35);
    //The text box is placed in the position determined in the screen
    this->_playerNameTextBox->move(175,280);

    //A check box to know if the player wants to play with a mobile control is created
    this->_mobileControl = new QCheckBox(this->_frameLogginWindow);
    //The check box is placed in the position determined in the screen
    this->_mobileControl->move(217, 360);

    //A Label to place a message for the player about the mobile control is created
    this->_mobileControlTextMessage = new QLabel(this->_frameLogginWindow);
    //The content of the message is defined
    this->_mobileControlTextMessage->setText("Use mobile control");
    //The size of the Label adjusted in order that the message fits well
    this->_mobileControlTextMessage->adjustSize();
    //The Label is placed in a position determined in the screen
    this->_mobileControlTextMessage->move(239, 357);

    //A Label to place the current IP direction is created
    this->_ipDirectionTextMessage = new QLabel(this->_frameLogginWindow);

    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost)) {
            //The content of the message is defined
            this->_ipDirectionTextMessage->setText("IP Adress: " + address.toString());
        }
        /*else {
            //The content of the message is defined
            this->_ipDirectionTextMessage->setText("IP Direction: Not Found");
        }*/
    }
    //The size of the Label adjusted in order that the message fits well
    this->_ipDirectionTextMessage->adjustSize();
    //The Label is placed in a position determined in the screen
    this->_ipDirectionTextMessage->move(15, 442);

    //A Button to start the game is created
    this->_playButton = new QPushButton(this->_frameLogginWindow);
    //The text of the Button is defined
    this->_playButton->setText("Play");
    //The Buttons are placed in a position determined in the screen
    this->_playButton->move(470,440);

}


/**
 * @brief LogginWindow::buttonClicked - Function that detects if the start game button is pressed
 */
void LogginWindow::buttonClicked() {

    //Verify that the user enters a name
    if(!this->_playerNameTextBox->text().isEmpty()) {
        //Hide the loggin window
        this->hide(); // -- ?? --
        //The window of the game is created
        GameWindow* game = new GameWindow(this->_playerNameTextBox->text(), this->_mobileControl->isChecked());
        //The game window is displayed
        game->show();

    }

    //If the user does not enter a name
    else{
        //Display a warning message asking the user to enter a name
        QMessageBox::warning(this, tr("Ups"), tr("¡Please enter a name!"));
    }

}
