#include "addhistory.h"
#include "ui_addhistory.h"

addHistory::addHistory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addHistory)
{
    ui->setupUi(this);
    QSqlQuery*query=new QSqlQuery();
    query->exec("SELECT id, name, accuracy_class FROM MeasuringInstrument");

    QSqlQuery*query2=new QSqlQuery();
    query2->exec("SELECT id, name, inn FROM OrganizationOfVerification");

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

addHistory::~addHistory()
{
    delete ui;
}

void addHistory::on_pushButton_clicked()
{
    QSqlQuery* query = new QSqlQuery();

    query->prepare("exec AddHistory ?,?,?");
    query->bindValue(0, ui->comboBox->itemText(postcombo));
    query->bindValue(1, ui->comboBox_2->itemText(postcombo2));
    query->bindValue(2, ui->dateEdit->date().toString("yyyy.MM.dd"));

    QMessageBox* mess = new QMessageBox();

    if(!query->exec()){
        mess->setText("Запрос составлен неверно или у вас нет доступа");
        mess->show();
    }

    emit refresh_table();
}

void addHistory::on_comboBox_currentIndexChanged(int index)
{
    postcombo=index;
}


void addHistory::on_comboBox_2_currentIndexChanged(int index)
{
    postcombo2=index;
}

