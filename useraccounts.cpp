#include "useraccounts.h"
#include "ui_useraccounts.h"

UserAccounts::UserAccounts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserAccounts)
{
    accountList = new QVector<User*>;
    QSqlQuery query("SELECT * FROM Konta");
    while (query.next()) {
        User* user= new User(query.value(0).toInt(),
                             query.value(1).toString(),
                             query.value(2).toString(),
                             query.value(3).toInt(),
                             query.value(4).toString(),
                             query.value(5).toString());
        accountList->push_back(user);
        userCount++;
    }
    ui->setupUi(this);
}

UserAccounts::~UserAccounts()
{
    delete accountList;
    delete ui;
}

void UserAccounts::on_addUserButton_clicked()
{
    ui->accountNumberLabel->clear();
    ui->passwordLabel->clear();
    ui->emailLabel->clear();
    ui->messageLabel->clear();
    if(ui->emailLineEdit->text() == ""&&
            ui->nameLineEdit->text()== ""&&
            ui->surnameLineEdit->text()== ""&&
            ui->accountNumberLineEdit->text()== ""&&
            ui->passwordLineEdit->text()== ""&&
            ui->repeatPasswordLlineEdit->text()== ""){
        addError=1;
        ui->messageLabel->setText("<font color='red'>Please fill all lines!</font>");
    }

    else{
        addError = 0;
        for(auto itr = accountList->begin();itr!=accountList->end();itr++)
        {
            if(ui->accountNumberLineEdit->text().toInt()==(*itr)->accountNumber){
                ui->accountNumberLabel->setText("<font color='red'>This account number already exists!</font>");
                addError=1;
            }
            else if(ui->passwordLineEdit->text()!=ui->repeatPasswordLlineEdit->text()){
                ui->passwordLabel->setText("<font color='red'>Repeated password must be the same!</font>");
                addError=1;
            }
            else if (ui->emailLineEdit->text()==(*itr)->email){
                ui->emailLabel->setText("<font color='red'>This email already exists!</font>");
                addError=1;
            }
        }
        if(addError==0)
        {
            ++userCount;
            User* user= new User(userCount,
                                 ui->nameLineEdit->text(),
                                 ui->surnameLineEdit->text(),
                                 ui->accountNumberLineEdit->text().toInt(),
                                 ui->passwordLineEdit->text(),
                                 ui->emailLineEdit->text());
            accountList->push_back(user);
            QMessageBox::information(this,"Message","New user added succesfully!");
            this->close();
        }
    }

}

void UserAccounts::on_cancelButton_clicked()
{

}
