#include "mainwindow.h"
#include <vector>
#include <QMap>
#include <QApplication>
#include <QDebug>
#include <QString>
enum class State {active,suspended,inactive};
int main(int argc, char *argv[])
{
    QT_REQUIRE_VERSION(argc,argv,QT_VERSION_STR);
    qputenv("QT_DEBUG_PLUGINS", QByteArray("1"));
    QApplication a(argc, argv);
    MainWindow w;
    /////////////
    //TEST ROOM//
    /////////////
    qDebug()<<QCoreApplication::applicationDirPath();
//    QTime sometime = QTime::currentTime();
//    QThread::msleep(2000);
//    qDebug()<<"sometime= "<<sometime<<" and current is "<<QTime::currentTime()<<endl;
//    QMap<QString,std::vector<int>> mapa{{"karnet",std::vector<int>(4,3)},{"usluga",std::vector<int>()}};
//    qDebug()<<(mapa["karnet"]).at(3);
//    State valid = State::active;
//    if(valid == State::inactive)
//        qDebug()<<"valid"<<endl;
//    qDebug()<<QDateTime::currentDateTime();

    w.show();
    return a.exec();
}
