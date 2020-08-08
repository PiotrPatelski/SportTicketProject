#ifndef USERACCOUNTS_H
#define USERACCOUNTS_H
#include <QMap>
#include <QPair>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QVector>
#include "user.h"

class UserAccounts
{
public:
    QVector<User*>* accountList;
    UserAccounts();
    void addNewUser(QString, QString, int, QString, QString);
    void deleteUser(); //LATER
    ~UserAccounts();
};

#endif // USERACCOUNTS_H
