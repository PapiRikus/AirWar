#include "estadisticas.h"

Estadisticas::Estadisticas(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle("Estadisticas");
    this->setFixedSize(LOGGIN_WINDOW_WIDTH,LOGGIN_WINDOW_HEIGHT);
    this->_frameStatsWindow = new QFrame(this);
            //The size of the Frame is define
    this->_frameStatsWindow->setFixedSize(LOGGIN_WINDOW_WIDTH, LOGGIN_WINDOW_HEIGHT);

    //Draw
     drawComponents();

     connect(this->_playButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));

}
Estadisticas::~Estadisticas() {

}
void Estadisticas::drawComponents(){

    this->_StatsLogoImage = new QLabel(this->_frameStatsWindow);
    this->_StatsLogoImage->setPixmap(QPixmap(":/images/Estadisticas.png"));
    this->_StatsLogoImage->setGeometry(90,95,415,100);

    this->_nameTextMessage=new QLabel(this->_frameStatsWindow);
    this->_nameTextMessage->setText("");
}
