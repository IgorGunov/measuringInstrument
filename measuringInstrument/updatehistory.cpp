#include "updatehistory.h"
#include "ui_updatehistory.h"

updatehistory::updatehistory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::updatehistory)
{
    ui->setupUi(this);
    QSqlQuery*query=new QSqlQuery();
    query->exec("SELECT id, name, accuracy_class FROM MeasuringInstrument");

    QSqlQuery*query2=new QSqlQuery();
    query2->exec("SELECT id, name FROM OrganizationOfVerification");

    while (query->next() && query2->next())
    {
        //ui->comboBox->addItem(query->value(0).toString()+' '+(query->value(1).toString())+' '+(query->value(2).toString()));
        //ui->comboBox_2->addItem(query2->value(0).toString()+' '+(query2->value(1).toString()));

        ui->comboBox->addItem(query->value(0).toString());
        ui->comboBox_2->addItem(query2->value(0).toString());
    }

    postcombo=0;
    postcombo2=0;

    this->setStyleSheet("background-color: DeepSkyBlue;");
}

updatehistory::~updatehistory()
{
    delete ui;
}

void updatehistory::obr_sendId(int aa)
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT tool_id, organization_id, verification_date FROM HistoryOfVerifications WHERE id=?");
    query->bindValue(0, aa);

    if(query->exec())
    {
        query->next();
        ui->lineEdit->setText(QString::number(aa));
        ui->comboBox->itemText(query->value(0).toInt());
        ui->comboBox_2->itemText(query->value(1).toInt());
        ui->dateEdit->setDate(query->value(2).toDate());
    }
}

void updatehistory::on_pushButton_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("exec UpdateHistory ?,?,?,?");
    query->bindValue(0, ui->lineEdit->text());
    query->bindValue(1, ui->comboBox->itemText(postcombo));
    query->bindValue(2, ui->comboBox->itemText(postcombo2));
    query->bindValue(3, ui->dateEdit->date().toString("yyyy.MM.dd"));

    QMessageBox* mess = new QMessageBox();

    if(!query->exec()){
        mess->setText("Запрос составлен неверно или у вас нет доступа");
        mess->show();
    }

    emit refresh_table();
}

