#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: DeepSkyBlue;");

    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), SLOT(CustomMenuReq(QPoint)));
    fl = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_triggered()
{
    logwin = new Login();
    logwin->show();
}

void MainWindow::on_pushButton_clicked()
{
    fl=1;
    model=new QSqlQueryModel();
    model->setQuery("SELECT id, name, accuracy_class, according_to_standard, Verification_interval FROM MeasuringInstrument");

    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"Наименование");
    model->setHeaderData(2,Qt::Horizontal,"Класс точности");
    model->setHeaderData(3,Qt::Horizontal,"Соответствие со стандартом");
    model->setHeaderData(4,Qt::Horizontal,"Меж поверочный интервал");

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    dobzap = new addrecord();
    connect(dobzap, SIGNAL(refresh_table()), this, SLOT(obt_ref_tab()));
    dobzap->show();
}

void MainWindow::obt_ref_tab(){
    on_pushButton_clicked();
}


void MainWindow::CustomMenuReq(QPoint pos)
{
    if(fl==1) {
        QModelIndex index = ui->tableView->indexAt(pos);
        globid = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toInt();
        recId = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 2)).toInt();

        QMenu* menu = new QMenu(this);
        QAction* izm = new QAction("Изменить инструмент", this);
        connect(izm, SIGNAL(triggered()), this, SLOT(izm_zap()));

        QAction* izm2 = new QAction("Изменить сотрудника", this);
        connect(izm2, SIGNAL(triggered()), this, SLOT(izm_zap2()));

        QAction* izm3 = new QAction("Изменить организацию", this);
        connect(izm3, SIGNAL(triggered()), this, SLOT(izm_zap3()));

        QAction* izm4 = new QAction("Изменить связь инструмента и сотрудника", this);
        connect(izm4, SIGNAL(triggered()), this, SLOT(izm_zap4()));

        QAction* izm5 = new QAction("Изменить запись истории поверки", this);
        connect(izm5, SIGNAL(triggered()), this, SLOT(izm_zap5()));

        QAction* ud = new QAction("Удалить инструмент", this);
        connect(ud, SIGNAL(triggered()), this, SLOT(del_zap()));

        QAction* ud2 = new QAction("Удалить сотрудника", this);
        connect(ud2, SIGNAL(triggered()), this, SLOT(del_zap2()));

        QAction* ud3 = new QAction("Удалить организацию", this);
        connect(ud3, SIGNAL(triggered()), this, SLOT(del_zap3()));

        QAction* ud4 = new QAction("Удалить связь инструмента и сотрудника", this);
        connect(ud4, SIGNAL(triggered()), this, SLOT(del_zap4()));

        QAction* ud5 = new QAction("Удалить историю поверки", this);
        connect(ud5, SIGNAL(triggered()), this, SLOT(del_zap5()));

        menu->addAction(izm);
        menu->addAction(izm2);
        menu->addAction(izm3);
        menu->addAction(izm4);
        menu->addAction(izm5);
        menu->addAction(ud);
        menu->addAction(ud2);
        menu->addAction(ud3);
        menu->addAction(ud4);
        menu->addAction(ud5);
        menu->popup(ui->tableView->viewport()->mapToGlobal(pos));
    }
}
void MainWindow::del_zap(){
    QSqlQuery* query = new QSqlQuery();

    query->prepare("exec DeleteMeasuring ?");
    query->bindValue(0, globid);
    if (query->exec()){
        on_pushButton_clicked();
    }
}

void MainWindow::del_zap2(){
    QSqlQuery* query = new QSqlQuery();

    query->prepare("exec DeleteEmployee ?");
    query->bindValue(0, globid);
    if (query->exec()){
        on_pushButton_9_clicked();
    }
}

void MainWindow::del_zap3(){
    QSqlQuery* query = new QSqlQuery();

    query->prepare("exec DeleteOrganization ?");
    query->bindValue(0, globid);
    if (query->exec()){
        on_pushButton_10_clicked();
    }
}

void MainWindow::del_zap4(){
    QSqlQuery* query = new QSqlQuery();

    query->prepare("exec DeleteEmployAndTool ?");
    query->bindValue(0, globid);
    if (query->exec()){
        on_pushButton_11_clicked();
    }
}

void MainWindow::del_zap5(){
    QSqlQuery* query = new QSqlQuery();

    query->prepare("exec DeleteHistory ?");
    query->bindValue(0, globid);
    if (query->exec()){
        on_pushButton_14_clicked();
    }
}

void MainWindow::izm_zap()
{
    izm = new izmenenie();
    connect(this, SIGNAL(sendId(int)), izm, SLOT(obr_sendId(int)));
    emit sendId(globid);
    izm->show();
    disconnect(this, SIGNAL(sendId(int)), izm, SLOT(obr_sendId(int)));
}

void MainWindow::izm_zap2()
{
    izm2 = new izmenenie2();
    connect(this, SIGNAL(sendId(int)), izm2, SLOT(obr_sendId(int)));
    emit sendId(globid);
    izm2->show();
    disconnect(this, SIGNAL(sendId(int)), izm2, SLOT(obr_sendId(int)));
}

void MainWindow::izm_zap3()
{
    izm3 = new izmenenie3();
    connect(this, SIGNAL(sendId(int)), izm3, SLOT(obr_sendId(int)));
    emit sendId(globid);
    izm3->show();
    disconnect(this, SIGNAL(sendId(int)), izm3, SLOT(obr_sendId(int)));
}

void MainWindow::izm_zap4()
{
    izm4 = new izmenenie4();
    connect(this, SIGNAL(sendId(int)), izm4, SLOT(obr_sendId(int)));
    emit sendId(globid);
    izm4->show();
    disconnect(this, SIGNAL(sendId(int)), izm4, SLOT(obr_sendId(int)));
}

void MainWindow::izm_zap5()
{
    izm5 = new updatehistory();
    connect(this, SIGNAL(sendId(int)), izm5, SLOT(obr_sendId(int)));
    emit sendId(globid);
    izm5->show();
    disconnect(this, SIGNAL(sendId(int)), izm5, SLOT(obr_sendId(int)));
}


void MainWindow::on_pushButton_5_clicked()
{
    fl=1;
    model = new QSqlQueryModel();
    model->setQuery("SELECT id, name,CASE WHEN Verification_interval <= 6 THEN 'меньше 6' ELSE 'больше 6' END  AS interval FROM MeasuringInstrument;");

    model->setHeaderData(0, Qt::Horizontal,"ID");
    model->setHeaderData(1, Qt::Horizontal,"Наименование");
    model->setHeaderData(2, Qt::Horizontal,"Интервал поверки");

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

void MainWindow::on_pushButton_6_clicked()
{

}

void MainWindow::on_pushButton_7_clicked()
{
    sub = new subqueries();
    connect(sub, SIGNAL(refresh_table()), this, SLOT(obt_ref_tab()));
    sub->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    fl=1;
    model = new QSqlQueryModel();
    model->setQuery("SELECT name,measuring, data FROM verificationDate");

    model->setHeaderData(0, Qt::Horizontal,"Название организации");
    model->setHeaderData(1, Qt::Horizontal,"Название инструмента");
    model->setHeaderData(2, Qt::Horizontal,"Дата поверки");

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, false);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

void MainWindow::on_pushButton_9_clicked()
{
    fl=1;
    model = new QSqlQueryModel();
    model->setQuery("SELECT id,first_name, name, last_name,post FROM ResponsibleEmployee");

    model->setHeaderData(0, Qt::Horizontal,"ID");
    model->setHeaderData(1, Qt::Horizontal,"Фамилия");
    model->setHeaderData(2, Qt::Horizontal,"Имя");
    model->setHeaderData(3, Qt::Horizontal,"Отчество");
    model->setHeaderData(4, Qt::Horizontal,"Должность");

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

void MainWindow::on_pushButton_10_clicked()
{
    fl=1;
    model = new QSqlQueryModel();
    model->setQuery("SELECT id, name, INN, address FROM OrganizationOfVerification");

    model->setHeaderData(0, Qt::Horizontal,"ID");
    model->setHeaderData(1, Qt::Horizontal,"Наименование");
    model->setHeaderData(2, Qt::Horizontal,"ИНН");
    model->setHeaderData(3, Qt::Horizontal,"Адрес");

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

void MainWindow::on_pushButton_11_clicked()
{
    fl=1;
    model = new QSqlQueryModel();
    model->setQuery("SELECT t1.id, t2.name, t2.first_name, t3.name FROM EmployeeAndToolRelationship T1 JOIN ResponsibleEmployee   T2 ON T1.tool_id = T2.id JOIN MeasuringInstrument T3 ON T1.tool_id = T3.id");

    model->setHeaderData(0, Qt::Horizontal,"ID");
    model->setHeaderData(1, Qt::Horizontal,"Имя сотрудника");
    model->setHeaderData(2, Qt::Horizontal,"Фамилия сотрудника");
    model->setHeaderData(3, Qt::Horizontal,"Название инструмента");

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

void MainWindow::on_pushButton_12_clicked()
{
    dobzap2 = new Form();
    connect(dobzap2, SIGNAL(refresh_table()), this, SLOT(obt_ref_tab2()));
    dobzap2->show();
}

void MainWindow::obt_ref_tab2(){
    on_pushButton_9_clicked();
}

void MainWindow::on_pushButton_3_clicked()
{
    dobzap3 = new addrecord2();
    connect(dobzap3, SIGNAL(refresh_table()), this, SLOT(obt_ref_tab3()));
    dobzap3->show();
}

void MainWindow::obt_ref_tab3(){
    on_pushButton_10_clicked();
}

void MainWindow::on_pushButton_4_clicked()
{
    dobzap4 = new addrecord3();
    connect(dobzap4, SIGNAL(refresh_table()), this, SLOT(obt_ref_tab4()));
    dobzap4->show();
}

void MainWindow::obt_ref_tab4(){
    on_pushButton_11_clicked();
}

void MainWindow::on_pushButton_14_clicked()
{
    fl=1;
    QSqlQueryModel* model1;
    model1 = new QSqlQueryModel();
    model1->setQuery("SELECT t1.id, t2.name AS measuring_name, t3.name AS organization_name, T1.verification_date FROM HistoryOfVerifications T1 JOIN MeasuringInstrument  T2 ON T1.tool_id = T2.id JOIN OrganizationOfVerification T3 ON T1.organization_id = T3.id");

    model1->setHeaderData(1, Qt::Horizontal,"Название инструмента");
    model1->setHeaderData(2, Qt::Horizontal,"Название организации");
    model1->setHeaderData(3, Qt::Horizontal,"Дата поверки");

    ui->tableView->setModel(model1);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();

}

void MainWindow::on_pushButton_15_clicked()
{
    dobzap5 = new addHistory();
    connect(dobzap5, SIGNAL(refresh_table()), this, SLOT(obt_ref_tab5()));
    dobzap5->show();
}

void MainWindow::obt_ref_tab5(){
    on_pushButton_14_clicked();
}
