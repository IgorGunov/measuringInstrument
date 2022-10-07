#include "addrecord.h"
#include "ui_addrecord.h"

addrecord::addrecord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addrecord)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: DeepSkyBlue;");
}

addrecord::~addrecord()
{
    delete ui;
}

void addrecord::on_pushButton_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("exec AddMeasuring :name,:accuracy_class,:according_to_standard,:Verification_interval");
    query->bindValue(":name", ui->lineEdit->text());
    query->bindValue(":accuracy_class", ui->lineEdit_2->text());
    query->bindValue(":according_to_standard", ui->lineEdit_3->text());
    query->bindValue(":Verification_interval", ui->lineEdit_4->text());

    QMessageBox* mess = new QMessageBox();

    if(!query->exec()){
        mess->setText("Запрос составлен неверно или у вас нет доступа");
        mess->show();
    }

    emit refresh_table();
}
