#include "izmenenie4.h"
#include "ui_izmenenie4.h"

izmenenie4::izmenenie4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::izmenenie4)
{
    ui->setupUi(this);
    QSqlQuery*query1=new QSqlQuery();
    query1->exec("SELECT id, name, first_name FROM ResponsibleEmployee");

    QSqlQuery*query2=new QSqlQuery();
    query2->exec("SELECT id, name, accuracy_class FROM MeasuringInstrument");

    while (query1->next() && query2->next())
    {
        //ui->comboBox->addItem(query1->value(0).toString()+' '+(query1->value(1).toString())+' '+(query1->value(2).toString()));
        //ui->comboBox_2->addItem(query2->value(0).toString()+' '+(query2->value(1).toString())+' '+(query2->value(2).toString()));

        ui->comboBox->addItem(query1->value(0).toString());
        ui->comboBox_2->addItem(query2->value(0).toString());
    }

    postcombo=0;
    postcombo2=0;
    this->setStyleSheet("background-color: DeepSkyBlue;");
}

izmenenie4::~izmenenie4()
{
    delete ui;
}

void izmenenie4::obr_sendId(int aa)
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT employe_id, tool_id FROM EmployeeAndToolRelationship WHERE id=?");
    query->bindValue(0, aa);

    if(query->exec())
    {
        query->next();
        ui->lineEdit->setText(QString::number(aa));
        ui->comboBox->itemText(query->value(0).toInt());
        ui->comboBox_2->itemText(query->value(1).toInt());
    }
}

void izmenenie4::on_pushButton_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query->exec("exec UpdateEmployAndTool @id="+ui->lineEdit->text()+", @employe_id = " + ui->comboBox->itemText(postcombo) + ",@tool_id = " + ui->comboBox_2->itemText(postcombo2));

    /*QMessageBox* mess = new QMessageBox();

    if(!query->exec()){
        mess->setText("Запрос составлен неверно или у вас нет доступа ");
        mess->show();
    }*/

}

void izmenenie4::on_comboBox_currentIndexChanged(int index)
{
    postcombo=index;
}

void izmenenie4::on_comboBox_2_currentIndexChanged(int index)
{
    postcombo2=index;
}
