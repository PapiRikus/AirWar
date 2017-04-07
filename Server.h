#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include "ListeningThread.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    void StartServer();
    ListeningThread *thread;
    int getData(int position);
protected:
    void incomingConnection(qintptr socketDescriptor);
};



#endif // SERVER_H
