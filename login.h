#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QCloseEvent>
#include <vector>

#include "user.h"
#include "mainwindow.h"

extern QString nickName;
extern bool logged;
extern QSqlDatabase db;
namespace Ui {

class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:

    QSqlDatabase db;
    std::vector<User> users{};
    explicit Login(QWidget *parent = nullptr);
    int session(bool, QApplication&);
    int checkLogin(bool, QApplication&);
    void closeEvent(QCloseEvent *event) override;
    ~Login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
};


#endif // LOGIN_H
