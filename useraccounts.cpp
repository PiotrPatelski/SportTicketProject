#include "useraccounts.h"

UserAccounts::UserAccounts()
{
    accountList = new QVector<User*>;
    QSqlQuery query("SELECT * FROM Konta");
          while (query.next()) {
              User* user= new User(query.value(0).toInt(),
                                   query.value(1).toString(),
                                   query.value(2).toString(),
                                   query.value(3).toInt(),
                                   query.value(4).toString(),
                                   query.value(5).toString());


              accountList->push_back(user);
              qDebug()<< *user<<"USERer"<<endl;
             }
}
UserAccounts::~UserAccounts()
{
    delete accountList;
}

