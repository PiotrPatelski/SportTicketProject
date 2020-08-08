#include "login.h"
#include "ui_login.h"
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    //ESTABLISHING CONNECTION TO DATABASE//
    db = QSqlDatabase::addDatabase("QSQLITE"); //DB ENGINE
    //db.setHostName("192.168.0.73");
    //db.setUserName("root");
    //db.setPassword("");
    //db.setDatabaseName(":/Resources/Resources/patelnia.db");
    db.setDatabaseName(QCoreApplication::applicationDirPath()+"/Resources/patelnia.db");
    //qDebug()<<QCoreApplication::applicationDirPath()+"/Resources/patelnia.db"<<endl;
    //db.setDatabaseName("C:/patelnia.db"); //DB PATH
    if(db.open()){
      QMessageBox::information(this,"Connected","Database Connected Successfully!");
    }else{
        QSqlError error = db.lastError();
        QMessageBox::information(this, "Connection", error.databaseText());
    }

    //INITIALIZING USERS LIST FROM DB
    accounts = new UserAccounts;

    //SETTING LOGIN UI
    ui->setupUi(this);

}

Login::~Login()
{
    delete ui;
}
int Login::session(bool logged, QApplication& app)
{

    this->setModal(true);
    this->exec();


    return this->checkLogin(logged, app);
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
    //EDITED 8.08.2020
    nickName = ui->userName_lineEdit->text();
    QString password = ui->password_lineEdit->text();
        //SEARCHING USERS LIST FOR VALID ACCOUNT NUMBER OR EMAIL
        for(auto users = accounts->accountList->begin(); users!=accounts->accountList->end(); users++)
        {
            if( (nickName == QString::number((*users)->accountNumber) || nickName ==(*users)->email )&&
                    password == (*users)->password ){
                logged=1;
                currentUser = *users;
                nickName = (*users)->name+ " " + (*users)->surname;
                QApplication::quit();
            }
            else
            {
                ui->validationLabel->setText("Invalid account number or password!\n Please try again.");
            }

        }



}

void Login::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, "PatelTicket",
                                                               tr("Are you sure?\n"),
                                                               QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                               QMessageBox::Yes);
        if (resBtn != QMessageBox::Yes) {
            event->ignore();
        } else {
            logged=0;
        }
}
