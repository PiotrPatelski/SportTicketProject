#ifndef CONFIGLOGIN_H
#define CONFIGLOGIN_H

#include <QDialog>
#include "config.h"
namespace Ui {
class ConfigLogin;
}

class ConfigLogin : public QDialog
{
    Q_OBJECT

public:
    QString name{""};
    QString password{""};
    Config* config{nullptr};
    explicit ConfigLogin(QWidget *parent = nullptr);
    ~ConfigLogin();

private slots:
    void on_submitButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::ConfigLogin *ui;
};

#endif // CONFIGLOGIN_H
