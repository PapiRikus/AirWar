#include "ListeningThread.h"

QString dataList("0/0/0/0");
//Constructor del hilo que recibe el id del socket
ListeningThread::ListeningThread(int ID, QObject *parent) : QThread(parent)
{
    this->socketDescriptor = ID;
}
//Método run del hilo
void ListeningThread::run(){
    qDebug() << "Iniciando...";
    socket = new QTcpSocket();//Crea un nuevo hilo
    //Caso de error al iniciar el socket
    if(!socket->setSocketDescriptor(this->socketDescriptor)){
        emit error(socket->error());
        return;
    }
    //Crear señales de lectura y de caso de desconección o de lectura
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);
    qDebug()<<socketDescriptor<<" cliente conectado";
    //Manda al cliente un mensaje de connección
    socket->write("CONECTADO CON EL SERVIDOR :D");
    exec();
}

QStringList ListeningThread::getData(){
    return dataList.split("/");
}

void ListeningThread::readyRead(){
    QByteArray data= socket->readAll();
    dataList = data;
    //qDebug() << socketDescriptor << " Dato: " << dataList;
    socket->write("Recibido por el servidor");
}

void ListeningThread::disconnected(){
    qDebug() << socketDescriptor << " desconectado";
    socket->deleteLater();
    exit(0);
}
