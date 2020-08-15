#ifndef CONFIG_H
#define CONFIG_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "newdb.h"
#include "useraccounts.h"
extern QSqlDatabase db;
extern bool databaseIsSet;
extern UserAccounts* accounts;
namespace Ui {
class Config;
}

class Config : public QDialog
{
    Q_OBJECT

public:
    QString name{"admin"}; //TO CONFIG FILE
    QString password{"696930989"}; //TO CONFIG FILE
    QString filePath{""};
    QMap<QString,QString> recentDataBases{};
    QString currentDBName{""};
    explicit Config(QWidget *parent = nullptr);
    void addDB(QString);
    void reloadDBTable();
    ~Config();

private slots:
    void on_addUserButton_clicked();

    void on_removeUserButton_clicked();

    void on_changeAdminPasswordButton_clicked();

    void on_createNewDBButton_clicked();

    void on_browseDBButton_clicked();

    void on_confirmChangesButton_clicked();

    void on_cancelButton_clicked();

    void on_setDBButton_clicked();

    void on_reloadUsersTableButton_clicked();

private:
    Ui::Config *ui;
};
#endif // CONFIG_H
