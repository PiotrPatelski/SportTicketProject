#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTabBar>
#include "CustomTabStyle.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->MainTabWidget);
    ui->MainTabWidget->tabBar()->setStyle(new CustomTabStyle);
}

MainWindow::~MainWindow()
{
    delete ui;
}


///////////////////
//SERVICE TAB BAR//
///////////////////

void MainWindow::on_ClientsButton_clicked()
{

}

void MainWindow::on_EntranceButton_clicked()
{

}

void MainWindow::on_SaleButton_clicked()
{

}

void MainWindow::on_BookingScheduleButton_clicked()
{

}

void MainWindow::on_BookingsButton_clicked()
{

}

void MainWindow::on_PeoplePresentButton_clicked()
{

}

void MainWindow::on_ClientDebtsButton_clicked()
{

}

void MainWindow::on_TransactionsButton_clicked()
{

}

void MainWindow::on_CashReportsButton_clicked()
{

}

void MainWindow::on_CompaniesButton_clicked()
{

}

void MainWindow::on_LockersButton_clicked()
{

}

void MainWindow::on_NotificationsHistoryButton_clicked()
{

}

void MainWindow::on_ShiftJournalButton_clicked()
{

}


//////////////////////
//MANAGEMENT TAB BAR//
//////////////////////

void MainWindow::on_ScheduleButton_clicked()
{

}

void MainWindow::on_GoodsandServicesButton_clicked()
{

}

void MainWindow::on_TicketsButton_clicked()
{

}

void MainWindow::on_ContractDefinitionsButton_clicked()
{

}

void MainWindow::on_ReceptionButton_clicked()
{

}

void MainWindow::on_ClientGroupsButton_clicked()
{

}

void MainWindow::on_CalendarButton_clicked()
{

}

void MainWindow::on_TemplatesButton_clicked()
{

}

void MainWindow::on_EmployeesButton_clicked()
{

}

void MainWindow::on_PaymentButton_clicked()
{

}

void MainWindow::on_CostsButton_clicked()
{

}

void MainWindow::on_OtherIncomesButton_clicked()
{

}

void MainWindow::on_GeneralDiscountsButton_clicked()
{

}
