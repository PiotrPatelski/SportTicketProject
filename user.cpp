#include "user.h"

User::User(int id_,
           QString name_,
           QString surname_,
           int accountNumber_,
           QString password_,
           QString email_):
    id{std::move(id_)},
    name{std::move(name_)},
    surname{std::move(surname_)},
    accountNumber{std::move(accountNumber_)},
    password{std::move(password_)},
    email{std::move(email_)}
{


}
User::User(User& user)
{
    id=user.id;
    name=user.name;
    surname = user.surname;
    accountNumber = user.accountNumber;
    password = user.password;
    email = user.email;
}
void User::operator =(User& user)
{
    id=user.id;
    name=user.name;
    surname = user.surname;
    accountNumber = user.accountNumber;
    password = user.password;
    email = user.email;
}
QDebug operator<< ( QDebug d, const User& user)
{
    d<<
        user.id<<" "<<
        user.name<<" "<<
        user.surname<<" "<<
        user.accountNumber<<" "<<
        user.password<<" "<<
        user.email<<endl;
    return d;
}
User::~User()
{


}
