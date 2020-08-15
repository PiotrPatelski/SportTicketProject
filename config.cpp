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
    QFile configFile(QCoreApplication::applicationDirPath()+"Config.txt");
    //if(databaseIsSet==1){
//    int cnt =0;
//        QSqlTableModel* model = new QSqlTableModel;
//        for (auto itr=accounts->accountList->begin();itr!=accounts->accountList->end();itr++)
//        {
//            model->setHeaderData(0,Qt::Horizontal,QObject::tr(cnt))
//        }

        //ui->usersTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //{

    ui->setupUi(this);
    reloadDBTable();
}

Config::~Config()
{
    delete ui;
}
//////////////////////////
//USER AND ADMIN OPTIONS//
//////////////////////////
void Config::on_addUserButton_clicked()
{
    //if(databaseIsSet==1){
        accounts->exec();

    //}
}

void Config::on_removeUserButton_clicked()
{
    //16.08.2020 UNFINISHED/////////////////
    ////////////////////////////////////////

    /*QString index=ui->usersTableView->selectedValues().at(ui->usersTableView->selectionModel()->currentIndex().row())*/;
    //QVariant value=index.sibling(index.row(),0).data().Int;
    //qDebug()<<value<<" row";
//    QModelIndexList selectedList = ui->usersTableView->selectionModel()->selectedRows();
    for(auto itr:(*accounts->accountList)){
        qDebug()<<(*itr);
    }
    QModelIndex index= ui->usersTableView->selectionModel()->currentIndex();
    //QVariant value=index.sibling(index.row(),0).data().toInt();

    int cnt = 0;
    //accounts->accountList->removeAt(index.sibling(index.row(),0).data().toInt()-1);
    for(auto itr:(*accounts->accountList)){
        if((*itr).id == index.sibling(index.row(),0).data().toInt()){
            accounts->accountList->removeAt(cnt);
            ui->usersTableView->model()->removeRow(1);
            ui->usersTableView->model()->submit();
        }

        cnt++;
    }
    qDebug()<<index.sibling(index.row(),0).data().toInt()<<" debug"<<endl;
    for(auto itr:(*accounts->accountList)){
       qDebug()<<itr->id<<" id"<<endl;
    }

//    for( int i=0; i<selectedList.count(); i++)
//            QMessageBox::information(this,"", QString::number(selectedList.at(i).row()));
//    for(auto itr : (*accounts->accountList))
//    {
//        if(itr->id==)
//    }
}

void Config::on_changeAdminPasswordButton_clicked()
{
    //this->
}
void Config::on_reloadUsersTableButton_clicked()
{
    reloadDBTable();
}
////////////////////
//DATABASE OPTIONS//
////////////////////
void Config::on_createNewDBButton_clicked()
{
    NewDB dialog;
    dialog.exec();
    addDB(dialog.dbPath);
    dialog.close();
}

void Config::on_browseDBButton_clicked()
{
    addDB(QFileDialog::getOpenFileName(this,
                                       "Open a File",
                                       QCoreApplication::applicationDirPath() + "/Resources",
                                       "Data Base File (*.db*)"));
}

void Config::on_setDBButton_clicked()
{
    if(ui->databaseListWidget->currentItem())
    {
        QFile file(recentDataBases[ui->databaseListWidget->currentItem()->text()]);
        if(file.exists())
            filePath = file.fileName();
    }
}
//////////////////////////
//SAVE SETTINGS AND QUIT//
//////////////////////////
void Config::on_confirmChangesButton_clicked()
{

}

void Config::on_cancelButton_clicked()
{
    this->close();

}
///////////////////////////
//UTILITY FUNCTIONS////////
///////////////////////////
void Config::addDB(QString path){
    QFile file(path);
    if(file.exists()){
        QFileInfo fileInfo(file);
        QString fileName(fileInfo.fileName());
        recentDataBases.insert({fileName},{path});
        QListWidgetItem *item = new QListWidgetItem(QIcon(":/Resources/Resources/Icons/db_image.jpg"),fileName);
        ui->databaseListWidget->addItem(item);
        ui->databaseListWidget->setCurrentItem(item);
    }

}

void Config::reloadDBTable(){
    QSqlQuery* selectQuery = new QSqlQuery(db);
    QSqlQueryModel * model = new QSqlQueryModel();
    selectQuery->prepare("select * from Konta");
    selectQuery->exec();
    if(!selectQuery->exec()) {
        qDebug() << "SQL Statement Error 2" << selectQuery->lastError();
    }
    model->setQuery(*selectQuery);
    ui->usersTableView->setModel(model);
    ui->usersTableView->setColumnHidden(0, true);
    delete selectQuery;
}








