#include "configlogin.h"
#include "ui_configlogin.h"

ConfigLogin::ConfigLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigLogin)
{
    ui->setupUi(this);
}

ConfigLogin::~ConfigLogin()
{
    delete ui;
    delete config;
}

void ConfigLogin::on_submitButton_clicked()
{
    config = new Config;
    this->name = ui->usernameLineEdit->text();
    this->password = ui->passwordLineEdit->text();
    if(name==config->name && password == config->password)
    {

        this->hide();
        config->exec();
    }
}

void ConfigLogin::on_cancelButton_clicked()
{
    ConfigLogin::close();
}
