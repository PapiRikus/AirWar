#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H

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
class Estadisticas : public QMainWindow
{
    Q_OBJECT
public:
    explicit Estadisticas(QWidget *parent = 0);
    ~Estadisticas();

private:

    //Attributes
    QFrame* _frameStatsWindow;
    QLabel* _StatsLogoImage;
    QLabel* _nameTextMessage;
    QLineEdit* _playerNameTextBox;
    QLabel* _mobileControlTextMessage;
    QCheckBox* _mobileControl;
    QPushButton* _playButton;


    void drawComponents();

signals:

public slots:
};

#endif // ESTADISTICAS_H
