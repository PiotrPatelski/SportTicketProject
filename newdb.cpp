#include "newdb.h"
#include "ui_newdb.h"

NewDB::NewDB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDB)
{
    ui->setupUi(this);
}

NewDB::~NewDB()
{
    delete ui;
}

void NewDB::on_acceptButton_clicked()
{
    dbName = ui->newDBLineEdit->text() + ".db";
    QString path = QFileDialog::getExistingDirectory(this, "Chose a directory", QCoreApplication::applicationDirPath());
    dbPath = path + "/" + dbName;
    QSqlDatabase dB = QSqlDatabase::addDatabase("QSQLITE");//not dbConnection
    dB.setDatabaseName(dbPath);
    if(dB.open()){
      QMessageBox::information(this,"Connected","Database Connected Successfully!");
    }else{
        QSqlError error = dB.lastError();
        QMessageBox::information(this, "Connection", error.databaseText());
    }
    QSqlQuery query;
    query.exec("CREATE TABLE Klienci"
               "(   NumerKlienta	TEXT NOT NULL,"
               "    Imie	TEXT,"
               "    Nazwisko	TEXT,"
               "    NumerTelefonu	INTEGER UNIQUE,"
               "    Adres	TEXT,"
               "    Miejscowosc	TEXT,"
               "    Status	TEXT,"
               "    Email	TEXT UNIQUE,"
               "    PRIMARY KEY(NumerKlienta))");
    query.exec("CREATE TABLE Konta"
               "(   Id	INTEGER NOT NULL UNIQUE,"
               "    Imie	TEXT NOT NULL,"
               "    Nazwisko	TEXT,"
               "    NumerKonta	INTEGER NOT NULL UNIQUE,"
               "    Haslo	TEXT NOT NULL,"
               "    Email	TEXT UNIQUE,"
               "    PRIMARY KEY(Id AUTOINCREMENT))");
    query.exec("CREATE TABLE Koszyk"
               "(   Id	INTEGER NOT NULL UNIQUE,"
               "    NumerKlienta	TEXT,"
               "    NazwaTowaru	TEXT,"
               "    TerminWaznosci	TEXT,"
               "    Wartosc	NUMERIC,"
               "    UmowaDo	TEXT,"
               "    DataObciazenia	TEXT,"
               "    Znizka	TEXT,"
               "    PRIMARY KEY(Id AUTOINCREMENT),"
               "    FOREIGN KEY(NazwaTowaru) REFERENCES Towary(NazwaTowaru),"
               "    FOREIGN KEY(NumerKlienta) REFERENCES Klienci(NumerKlienta),"
               "    FOREIGN KEY(Znizka) REFERENCES Znizki(NazwaZnizki))");
    query.exec("CREATE TABLE Towary"
               "(   NazwaTowaru	TEXT,"
               "    Cena	NUMERIC,"
               "    TypTowaru	TEXT,"
               "    CzasTrwania_msc	INTEGER,"
               "    PRIMARY KEY(NazwaTowaru))");
    query.exec("CREATE TABLE Znizki"
               "(   NazwaZnizki	TEXT UNIQUE,"
               "    ObnizenieCeny_procent	INTEGER,"
               "    PRIMARY KEY(NazwaZnizki))");
    this->hide();

}

void NewDB::on_cancelButton_clicked()
{
    this->close();
}
