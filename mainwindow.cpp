#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTabBar>
#include "CustomTabStyle.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //TO DO: INTERFACE WINDOW INIT FUNCTION
    //WILL ASSEMBLE TO A FUNCTION WHEN MORE WIDGETS ARE ADDED
    ui->setupUi(this);
    this->setCentralWidget(ui->MainTabWidget);
    ui->MainTabWidget->tabBar()->setStyle(new CustomTabStyle);

    // PACK INTO SET_STATUS FUNC//
    //WYŚWIETLAM KOMUNIKAT W statusbar
    usernameBuff = "Logged as: " + nickName;
    ui->statusbar->showMessage(usernameBuff);
    ui->statusbar->addPermanentWidget(ui->label_statusbar);
    // PACK INTO SET_STATUS FUNC//

    // CLOCK INITIALIZATION //
    clockInit(timer);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;

}

//TIME TO STRING CONVERTION//
void MainWindow::guiClock()
{
    QDateTime time = QDateTime::currentDateTime();
    QString time_text = time.toString("dd.MM.yyyy                 hh : mm : ss");
    ui->label_statusbar->setText(time_text);
}

//CLOCK INITIALIZATION//
void MainWindow::clockInit(QTimer* timer)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(guiClock()));
    timer->start(1000);
}

///////////
//DESKTOP//  W.I.P SECTION TO TEST DATABASE CONNECTION FOR FURTHER IMPLEMENTATION
///////////

void MainWindow::on_DBconnectButton_clicked()
{


        QString SelectString;
        QSqlQuery* SelectQuery = new QSqlQuery(db);
        QSqlQueryModel * Modal = new QSqlQueryModel();
        SelectQuery->prepare("select * from Klienci");
        SelectQuery->exec();
        if(!SelectQuery->exec()) {
            qDebug() << "SQL Statement Error 2" << SelectQuery->lastError();
        }
        qDebug()<<"success!"<<endl;
        Modal->setQuery(*SelectQuery);
        ui->tableView->setModel(Modal);

//        QSqlQuery query("SELECT * FROM Towary");
//             while (query.next()) {
//                 QString country = query.value(3).toString(); //INDEX W query.value() OZNACZA KOLUMNE W KTÓREJ WARTOŚCI TRAFIĄ DO STRINGA//
//                 qDebug()<<country<<endl;
//             }
        QSqlQuery query("SELECT * FROM Towary");
        query.next();
        QString country = query.value(3).toString();
        qDebug()<<country<<endl;
        query.next();
        QString country2 = query.value(3).toString();
        qDebug()<<country2<<endl;
//    QString query = "CREATE TABLE testtable ("
//                    "ID INTEGER,"
//                    "FirstName TEXT,"
//                    "LastName TEXT,"
//                    "Birthdate NUMERIC,"
//                    "Weight REAL);";
//    QSqlQuery qry;

//    if(!qry.exec(query))
//    {
//        qDebug()<<"error creating table";

//    }

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

