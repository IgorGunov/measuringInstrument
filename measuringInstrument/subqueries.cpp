#include "subqueries.h"
#include "ui_subqueries.h"

subqueries::subqueries(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::subqueries)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: DeepSkyBlue;");
}

subqueries::~subqueries()
{
    delete ui;
}

void subqueries::on_pushButton_clicked()
{
    model = new QSqlQueryModel();
    model->setQuery("SELECT name, INN FROM OrganizationOfVerification  WHERE address = ( SELECT address FROM OrganizationOfVerification  WHERE INN=123)");

    model->setHeaderData(0, Qt::Horizontal,"Номер организации");
    model->setHeaderData(1, Qt::Horizontal,"INN");

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

void subqueries::on_pushButton_2_clicked()
{
    model = new QSqlQueryModel();
    model->setQuery("SELECT T1.name, (SELECT T2.name FROM measuringInstrument T2  WHERE T3.organization_id=T1.id AND T3.tool_id=T2.id) AS measuring FROM OrganizationOfVerification T1, HistoryOfVerifications T3");

    model->setHeaderData(0, Qt::Horizontal,"Организация");
    model->setHeaderData(1, Qt::Horizontal,"Инструмент");

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

void subqueries::on_pushButton_3_clicked()
{
    model = new QSqlQueryModel();
    model->setQuery("SELECT name FROM measuringInstrument GROUP BY name, accuracy_class HAVING accuracy_class < 3");

    model->setHeaderData(0, Qt::Horizontal,"Название инструмента");

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

void subqueries::on_pushButton_4_clicked()
{
    model = new QSqlQueryModel();
    model->setQuery("SELECT name, accuracy_class, according_to_standard, Verification_interval FROM measuringInstrument WHERE Verification_interval < ALL (SELECT AVG(Verification_interval) FROM measuringInstrument)");

    model->setHeaderData(0, Qt::Horizontal,"Название инструмента");
    model->setHeaderData(1, Qt::Horizontal,"Класс точности");
    model->setHeaderData(2, Qt::Horizontal,"Соответствие госту");
    model->setHeaderData(3, Qt::Horizontal,"Интервал поверки");

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

void subqueries::on_pushButton_5_clicked()
{
    model = new QSqlQueryModel();
    model->setQuery("SELECT name, measuring, CASE WHEN data < GETDATE()THEN 'пора на проверку' ELSE 'все в порядке' END AS chek FROM verificationDate;");

    model->setHeaderData(0, Qt::Horizontal,"Организация");
    model->setHeaderData(1, Qt::Horizontal,"Инструмент");
    model->setHeaderData(2, Qt::Horizontal,"просрочено или нет");

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

void subqueries::on_pushButton_6_clicked()
{
    model = new QSqlQueryModel();
    model->setQuery("SELECT post, COUNT(name) AS count FROM ResponsibleEmployee GROUP BY post");

    model->setHeaderData(0, Qt::Horizontal,"Должность");
    model->setHeaderData(1, Qt::Horizontal,"Колличество сотрудников");

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}
