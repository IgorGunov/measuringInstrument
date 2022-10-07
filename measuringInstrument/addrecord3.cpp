#include "addrecord3.h"
#include "ui_addrecord3.h"

addrecord3::addrecord3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addrecord3)
{
    ui->setupUi(this);

    QSqlQuery*query=new QSqlQuery();
    query->exec("SELECT id, name, first_name FROM ResponsibleEmployee");

    QSqlQuery*query2=new QSqlQuery();
    query2->exec("SELECT id, name, accuracy_class FROM MeasuringInstrument");

    while (query->next() && query2->next())
    {
        //ui->comboBox->addItem(query->value(0).toString()+' '+(query->value(1).toString())+' '+(query->value(2).toString()));
        //ui->comboBox_2->addItem(query2->value(0).toString()+' '+(query2->value(1).toString())+' '+(query2->value(2).toString()));

        ui->comboBox->addItem(query->value(0).toString());
        ui->comboBox_2->addItem(query2->value(0).toString());
    }

    postcombo=0;
    postcombo2=0;

    this->setStyleSheet("background-color: DeepSkyBlue;");
}

addrecord3::~addrecord3()
{
    delete ui;
}

void addrecord3::on_pushButton_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query->exec("exec AddEmployAndTool @employe_id = " + ui->comboBox->itemText(postcombo) + ",@tool_id = " + ui->comboBox_2->itemText(postcombo2));
    //query->bindValue(":employe_id", ui->comboBox->itemText(postcombo));
    //query->bindValue(":tool_id", ui->comboBox_2->itemText(postcombo2));

    /*QMessageBox* mess = new QMessageBox();

    if(!query->exec()){
        mess->setText("Запрос составлен неверно или у вас нет доступа ");
        mess->show();
    }*/

    emit refresh_table();
}

void addrecord3::on_comboBox_currentIndexChanged(int index)
{
    postcombo=index;
}

void addrecord3::on_comboBox_2_currentIndexChanged(int index)
{
    postcombo2=index;
}
