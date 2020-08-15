#ifndef USERACCOUNTS_H
#define USERACCOUNTS_H

#include <QDialog>
#include <QMap>
#include <QPair>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QVector>
#include "user.h"
extern QSqlDatabase db;
extern bool databaseIsSet;

namespace Ui {
class UserAccounts;
}

class UserAccounts : public QDialog
{
    Q_OBJECT

public:
    bool addError{1};
    int userCount{0};
    QVector<User*>* accountList;
    explicit UserAccounts(QWidget *parent = nullptr);
    void addNewUser(QString, QString, int, QString, QString);
    void deleteUser(); //LATER
    ~UserAccounts();

private slots:
    void on_addUserButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::UserAccounts *ui;
};

#endif // USERACCOUNTS_H
