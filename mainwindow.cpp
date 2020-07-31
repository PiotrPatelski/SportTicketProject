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


    //WYŚWIETLAM KOMUNIKAT W statusbar
    if(user.userName==0)
        ui->statusbar->showMessage("Not logged in.");
    else
        usernameBuff = "Logged as: " + user.userName;
        ui->statusbar->showMessage(usernameBuff);


    //DODAJE PERMANENTNY WIDGET DO statusbar PARAMETREM FUNKCJI PO PRZECINKU JEST LICZBA OZNACZAJĄCA CZĘŚĆ PASKA JAKI WIDGET MA ZAJMOWAĆ
    ui->statusbar->addPermanentWidget(ui->label_statusbar);

    timer = new QTimer(this);


    connect(timer, SIGNAL(timeout()),this,SLOT(guiClock()));
    timer->start(1000);



}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::guiClock()
{
    QDateTime time = QDateTime::currentDateTime();
    QString time_text = time.toString("dd.MM.yyyy                 hh : mm : ss");
    ui->label_statusbar->setText(time_text);
}


///////////
//DESKTOP//
///////////

void MainWindow::on_DBconnectButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setHostName("192.168.0.73");
   // db.setUserName("root");
    //db.setPassword("Q29zjyip.");
    //db.setDatabaseName(":/Resources/Resources/patelnia.db");
    db.setDatabaseName(QCoreApplication::applicationDirPath()+"/Resources/patelnia.db");
    if(db.open()){
      QMessageBox::information(this,"Connected","Database Connected Successfully!");
    }else{
        QSqlError error = db.lastError();
        QMessageBox::information(this, "Connection", error.databaseText());

    }

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

