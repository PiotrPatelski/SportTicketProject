#include "config.h"
#include "ui_config.h"

/////////////////////////////
/// TO DO:
/// - SECOND TABLE FOR DATABASES FOUND ON COMPUTER,
/// - FILE BROWSER BUTTON TO SET A PATH FOR DESIRED DATABASE
/// - BUTTON FOR NEW DATABASE CREATION, SETTING ITS NAME, ETC.
/// - IF NO DATABASE IS CHOSEN AS SOURCE, ADD AND REMOVE USER CAN'T WORK
/// - ADD TO CONSTRUSTOR: CREATION OF CONFIG TEXT FILE,
/// TO WHICH VARIABLES THAT ARE SUPPOSED TO BE REMEMBERED THROUGH TIME,
/// ARE WRITTEN.
/// - SCRIPT FOR ADD USER BUTTON, INCLUDING EVENT WHEN USER IN TABLE
/// IS CLICKED.
/// - SCRIPT FOR REMOVE USER
/// - SCRIPT FOR SAVE CHANGES THROUGH QUERY DB UPDATE
/// -
//////////////////////////////
Config::Config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Config)
{
    ui->setupUi(this);
}

Config::~Config()
{
    delete ui;
}

void Config::on_addUserButton_clicked()
{

}

void Config::on_removeUserButton_clicked()
{

}

void Config::on_changeAdminPasswordButton_clicked()
{
    //this->
}
