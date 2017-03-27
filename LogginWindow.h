#ifndef LOGGINWINDOW_H
#define LOGGINWINDOW_H

#include <QMainWindow>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include "GameWindow.h"

class LogginWindow: public QMainWindow {

    Q_OBJECT

    private:
        //Attributes
        QFrame* frameLogginWindow;
        QLabel* airWarLogoImage;
        QLabel* nameTextMessage;
        QLineEdit* playerNameTextBox;
        QPushButton* playButton;

    private slots:
        void buttonClicked();

    public:
        LogginWindow(QWidget* parent=0);
        ~LogginWindow();

};

#endif // LOGGINWINDOW_H
