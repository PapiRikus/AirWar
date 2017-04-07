#include "archivos.h"

Archivos::Archivos(QString ruta)
{
    this->ruta=ruta;
}
void Archivos::guardar(QString text){

    QFile file_for_writing(this->ruta);

    file_for_writing.open(QIODevice::WriteOnly | QIODevice::Truncate); //

    QTextStream text_stream_for_writing(&file_for_writing);
        //set the text of the file
        //Write the text on the stream
        text_stream_for_writing << text;
        //close the file
        file_for_writing.close();
}

QString Archivos::leer(){
        QString text;
        QFile file_for_reading(this->ruta);
        file_for_reading.open(QIODevice::ReadOnly);
        QTextStream text_stream_for_reading(&file_for_reading);
        //read 6 characters
        qDebug() << text_stream_for_reading.read(6);
        //Reset the position on the file
        text_stream_for_reading.seek(0);
        //read a word
        text_stream_for_reading >> text;
            qDebug() << text;
        //Reset the position on the file
        text_stream_for_reading.seek(0);
        //read a line
        text+=text_stream_for_reading.readLine();



        //Reset the position on the file

        text_stream_for_reading.seek(0);

        //read the entire content of the file

        qDebug() << text_stream_for_reading.readAll();

        //close the file
        file_for_reading.close();
        return text;
}
