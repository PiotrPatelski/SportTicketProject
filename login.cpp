#include "login.h"
#include "ui_login.h"
#include "QMessageBox"
#include "QDebug"
#include "mainwindow.h"
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
     user.userName = ui->userName_textEdit->toPlainText();
    if( user.userName == "test"){

        state=1;

        QApplication::quit();

    }
}

void Login::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "PatelTicket",
                                                                    tr("Are you sure?\n"),
                                                                    QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                    QMessageBox::Yes);
        if (resBtn != QMessageBox::Yes) {
            event->ignore();
        } else {

            state=0;

        }
}
