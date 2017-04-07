#ifndef LOGGINWINDOW_H
#define LOGGINWINDOW_H

#include <QMainWindow>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QCheckBox>
#include <QNetworkInterface>
#include "GameWindow.h"

const int LOGGIN_WINDOW_WIDTH = 600;
const int LOGGIN_WINDOW_HEIGHT = 500;

class LogginWindow: public QMainWindow {

    Q_OBJECT

    private:

        //Attributes
        QFrame* _frameLogginWindow;
        QLabel* _airWarLogoImage;
        QLabel* _nameTextMessage;
        QLineEdit* _playerNameTextBox;
        QLabel* _mobileControlTextMessage;
        QCheckBox* _mobileControl;
        QLabel* _ipDirectionTextMessage;
        QPushButton* _playButton;

        //Methods
        void drawComponents();

    private slots:

        void buttonClicked();

    public:

        LogginWindow(QWidget* parent=0);
        ~LogginWindow();

};

#endif // LOGGINWINDOW_H
