#include "izmenenie2.h"
#include "ui_izmenenie2.h"

izmenenie2::izmenenie2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::izmenenie2)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: DeepSkyBlue;");
}

izmenenie2::~izmenenie2()
{
    delete ui;
}

void izmenenie2::obr_sendId(int aa)
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT first_name, name, last_name, post FROM ResponsibleEmployee WHERE id=?");
    query->bindValue(0, aa);

    if(query->exec())
    {
        query->next();
        ui->lineEdit->setText(QString::number(aa));
        ui->lineEdit_2->setText(query->value(0).toString());
        ui->lineEdit_3->setText(query->value(1).toString());
        ui->lineEdit_4->setText(query->value(2).toString());
        ui->lineEdit_5->setText(query->value(3).toString());
    }
}

void izmenenie2::on_pushButton_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("exec UpdateEmployee ?,?,?,?,?");
    query->bindValue(0,ui->lineEdit->text());
    query->bindValue(1,ui->lineEdit_3->text());
    query->bindValue(2,ui->lineEdit_2->text());
    query->bindValue(3,ui->lineEdit_4->text());
    query->bindValue(4,ui->lineEdit_5->text());

    if (query->exec()){
    }
}
