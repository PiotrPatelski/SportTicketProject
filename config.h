#ifndef CONFIG_H
#define CONFIG_H

#include <QDialog>

namespace Ui {
class Config;
}

class Config : public QDialog
{
    Q_OBJECT

public:
    QString name{"admin"}; //TO CONFIG FILE
    QString password{"696930989"}; //TO CONFIG FILE
    explicit Config(QWidget *parent = nullptr);
    ~Config();

private slots:
    void on_addUserButton_clicked();

    void on_removeUserButton_clicked();

    void on_changeAdminPasswordButton_clicked();

private:
    Ui::Config *ui;
};
    static QString name{"admin"};
#endif // CONFIG_H
