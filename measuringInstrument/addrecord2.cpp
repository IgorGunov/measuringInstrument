#include "addrecord2.h"
#include "ui_addrecord2.h"

addrecord2::addrecord2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addrecord2)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: DeepSkyBlue;");
}

addrecord2::~addrecord2()
{
    delete ui;
}

void addrecord2::on_pushButton_clicked()
{
    QSqlQuery*query=new QSqlQuery();
    query->prepare("exec AddOrganization :name, :INN, :address");
    query->bindValue(":INN", ui->lineEdit->text());
    query->bindValue(":name", ui->lineEdit_2->text());
    query->bindValue(":address", ui->lineEdit_3->text());

    QMessageBox*mess=new QMessageBox();

    if(!query->exec())
    {
        mess->setText("запрос составлен неверно");
        mess->show();
    }
    emit refresh_table();
}
