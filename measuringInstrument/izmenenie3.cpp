#include "izmenenie3.h"
#include "ui_izmenenie3.h"

izmenenie3::izmenenie3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::izmenenie3)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: DeepSkyBlue;");
}

izmenenie3::~izmenenie3()
{
    delete ui;
}

void izmenenie3::obr_sendId(int aa)
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT name, INN, address FROM OrganizationOfVerification WHERE id=?");
    query->bindValue(0, aa);

    if(query->exec())
    {
        query->next();
        ui->lineEdit->setText(QString::number(aa));
        ui->lineEdit_2->setText(query->value(0).toString());
        ui->lineEdit_3->setText(query->value(1).toString());
        ui->lineEdit_4->setText(query->value(2).toString());
    }
}

void izmenenie3::on_pushButton_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query->exec("exec UpdateOrganization @id="+ui->lineEdit->text()+",@name="+ui->lineEdit_2->text()+",@INN="+ui->lineEdit_3->text()+",@address="+ui->lineEdit_4->text());
    //query->bindValue(0,ui->lineEdit->text());
    //query->bindValue(1,ui->lineEdit_2->text());
    //query->bindValue(2,ui->lineEdit_3->text());
    //query->bindValue(3,ui->lineEdit_4->text());
}
