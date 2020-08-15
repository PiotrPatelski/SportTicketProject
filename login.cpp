#include "login.h"
#include "ui_login.h"
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{


//13.08.2020 TO DO: CREATE FUNCTION FOR CONFIG FILE USAGE
    //TESTING CONFIG FILE CREATION AND EDITING
    QFile configFile(QCoreApplication::applicationDirPath()+"Config.txt");
    if (!configFile.exists()){ //CHECKS IF CONFIG FILE DOESNT EXIST
        QMessageBox::warning(this,"Config Error","Config file does not exist!\n Creating new config");
        if(!configFile.open(QFile::WriteOnly | QFile::Text)){// CHECKS IF CONFIG FILE CANT BE OPENED
            QMessageBox::warning(this,"Config Error","Config file can't be opened!");
        }
        else{ //IF CONFIG FILE DOESNT EXIT, WE'RE CREATING NEW ONE WITH DEFAULT PARAMETERS FOR FURTHER EDITING
            QTextStream out(&configFile);
            QString textToConfig = "           //CONFIG FILE//           \n"
                                   "databaseName = 0\n"
                                   "adminLogin = admin\n"
                                   "adminPassword = 696930989\n"
                                   "recentDataBases = \n";
            out << textToConfig;
            configFile.flush();
            configFile.close();
            QMessageBox::information(this,"Wrote Message",textToConfig);
            ConfigLogin conflog;
            conflog.exec();
        }

    }
    else{// IF CONFIG FILE ALREADY EXIST
        if(!configFile.open(QFile::ReadOnly | QFile::Text)){// CHECKS IF CONFIG FILE CANT BE OPENED
           QMessageBox::warning(this,"Config Error","Config file can't be opened!");
        }
        else{// FETCHING DATA FROM CONFIG FILE TO INITIALIZE DATABASE, ADMIN AND CONFIG SETTINGS
            QTextStream in(&configFile);
            QString textFromConfig = in.readAll();
            QMessageBox::information(this,"Read Message",textFromConfig);
        }

    }
/////////////////////////////////////////////////


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

void Login::on_configButton_clicked()
{
    ConfigLogin conflog;
    conflog.exec();
}
