#ifndef NEWDB_H
#define NEWDB_H

#include <QDialog>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>

namespace Ui {
class NewDB;
}

class NewDB : public QDialog
{
    Q_OBJECT

public:
    QString dbName{""};
    QString dbPath{""};
    explicit NewDB(QWidget *parent = nullptr);
    ~NewDB();

private slots:
    void on_acceptButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::NewDB *ui;
};

#endif // NEWDB_H
