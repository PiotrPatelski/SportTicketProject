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
int Login::checkLogin(bool logged, QApplication& app)
{
    if(logged==0)
    {

        return 0;
    }
    else{
        this->hide();
        MainWindow w;
        w.show();
        return app.exec();
    }
}
void Login::on_pushButton_clicked()
{
    nickName = ui->userName_textEdit->toPlainText();

    if( nickName == "test"){
        logged=1;
        db = QSqlDatabase::addDatabase("QSQLITE");
        //db.setHostName("192.168.0.73");
        //db.setUserName("root");
        //db.setPassword("");
        //db.setDatabaseName(":/Resources/Resources/patelnia.db");
        //db.setDatabaseName(QCoreApplication::applicationDirPath()+"/Resources/patelnia.db");
        db.setDatabaseName("C:/patelnia.db");
        if(db.open()){
          QMessageBox::information(this,"Connected","Database Connected Successfully!");
        }else{
            QSqlError error = db.lastError();
            QMessageBox::information(this, "Connection", error.databaseText());
        }
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
            logged=0;
        }
}
