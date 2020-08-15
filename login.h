#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QCloseEvent>
#include <vector>
#include<QMessageBox>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include "user.h"
#include "mainwindow.h"
#include "useraccounts.h"
#include "user.h"
#include "configlogin.h"
extern QString nickName;
extern bool logged;
extern QSqlDatabase db;
extern UserAccounts* accounts;
namespace Ui {

class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    bool databaseIsSet{0};
    QSqlDatabase db;
    std::vector<User> users{};
    explicit Login(QWidget *parent = nullptr);
    int session(bool, QApplication&);
    int checkLogin(bool, QApplication&);
    void closeEvent(QCloseEvent *event) override;
    ~Login();

private slots:
    void on_pushButton_clicked();

    void on_configButton_clicked();

private:
    Ui::Login *ui;
};


#endif // LOGIN_H
