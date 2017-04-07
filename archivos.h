#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <QObject>
#include<QFile>
#include <QTextStream>
#include<QDebug>
class Archivos:public QObject
{

public:
    Archivos(QString ruta);
    QString leer();
    void guardar(QString);
private:
    QString ruta;
};

#endif // ARCHIVOS_H
