#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QCloseEvent>
#include "user.h"
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    User user;
    bool state{0};
    explicit Login(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent *event) override;
    ~Login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
};


#endif // LOGIN_H
