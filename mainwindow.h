#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include "customer.h"
#include "article.h"
#include "login.h"
#include "user.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

extern QString nickName;
extern QSqlDatabase db;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void clockInit(QTimer*);
    QString usernameBuff;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void guiClock();
private slots:

    ///////////////////
    //SERVICE TAB BAR//
    ///////////////////
    void on_ClientsButton_clicked();

    void on_EntranceButton_clicked();

    void on_SaleButton_clicked();

    void on_BookingScheduleButton_clicked();

    void on_BookingsButton_clicked();

    void on_PeoplePresentButton_clicked();

    void on_ClientDebtsButton_clicked();

    void on_TransactionsButton_clicked();

    void on_CashReportsButton_clicked();

    void on_CompaniesButton_clicked();

    void on_LockersButton_clicked();

    void on_NotificationsHistoryButton_clicked();

    void on_ShiftJournalButton_clicked();


    //////////////////////
    //MANAGEMENT TAB BAR//
    //////////////////////
    void on_ScheduleButton_clicked();

    void on_GoodsandServicesButton_clicked();

    void on_TicketsButton_clicked();

    void on_ContractDefinitionsButton_clicked();

    void on_ReceptionButton_clicked();

    void on_ClientGroupsButton_clicked();

    void on_CalendarButton_clicked();

    void on_TemplatesButton_clicked();

    void on_EmployeesButton_clicked();

    void on_PaymentButton_clicked();

    void on_CostsButton_clicked();

    void on_OtherIncomesButton_clicked();

    void on_GeneralDiscountsButton_clicked();

    void on_DBconnectButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;

};

#endif // MAINWINDOW_H
