#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: DeepSkyBlue;");
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    QSqlQuery*query=new QSqlQuery();
    query->prepare("exec AddEmployee :first_name, :name, :last_name, :post");
    query->bindValue(":first_name", ui->lineEdit_2->text());
    query->bindValue(":name", ui->lineEdit->text());
    query->bindValue(":last_name", ui->lineEdit_3->text());
    query->bindValue(":post", ui->lineEdit_4->text());

    QMessageBox*mess=new QMessageBox();

    if(!query->exec())
    {
        mess->setText("запрос составлен неверно");
        mess->show();
    }
    emit refresh_table();
}
