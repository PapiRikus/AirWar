#ifndef LISTENINGTHREAD_H
#define LISTENINGTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QString>

class ListeningThread : public QThread
{
    Q_OBJECT
public:
    explicit ListeningThread(int ID, QObject *parent = 0);
    QStringList getData();
    void run();
signals:
    void error(QTcpSocket::SocketError socketerror);
public slots:
    void readyRead();
    void disconnected();
private:
    QTcpSocket *socket;
    int socketDescriptor;
};

#endif // LISTENINGTHREAD_H
