#include "mainwindow.h"
#include <vector>
#include <QMap>
#include <QApplication>
#include <QDebug>
#include <QString>
enum class State {active,suspended,inactive};
QString nickName{""};
bool logged{0};
QSqlDatabase db;
UserAccounts* accounts;
User* currentUser;
bool databaseIsSet{0};
int main(int argc, char *argv[])
{
    QT_REQUIRE_VERSION(argc,argv,QT_VERSION_STR);
    qputenv("QT_DEBUG_PLUGINS", QByteArray("1"));
    QApplication a(argc, argv);

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

    //CREATING LOGIN WINDOW OBJ AND EXECTUING
    //IF LOGIN CONDITION IS MET, RETURNED VALUE WILL BE MAIN WINDOW EXEC
    qDebug()<<QCoreApplication::applicationDirPath()+"/Resources/patelnia.db"<<"TESTTT"<<endl;
   Login loginWindow;
   loginWindow.setModal(true);
   loginWindow.exec();

   return loginWindow.checkLogin(logged, a);

    /////////////////////////


}

