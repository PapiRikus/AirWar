#include "Server.h"

Server::Server(QObject *parent) : QTcpServer(parent)
{

}

void Server::StartServer(){
    if(!this->listen(QHostAddress::Any,8080)){
        qDebug()<<"El servidor no se inició correctamente :X";
    }else{
        qDebug()<<"El servidor se inició correctamente :D";
    }
}

void Server::incomingConnection(qintptr socketDescriptor){
    qDebug()<<socketDescriptor<<" Conectando";
    thread = new ListeningThread(socketDescriptor,this);
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    thread->start();
}

int Server::getData(int position){
    return ((QString)(thread->getData()[position])).toInt();
}
