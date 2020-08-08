#ifndef USER_H
#define USER_H
#include <QString>
#include <iostream>
#include <QDebug>
class User
{
public:
    User(int, QString, QString, int, QString, QString);
    int id;
    QString name;
    QString surname;
    int accountNumber;
    QString password;
    QString email;
    User(User&);
    void operator = (User&);
    friend QDebug operator<<(QDebug, const User&);
    ~User();
};

#endif // USER_H
