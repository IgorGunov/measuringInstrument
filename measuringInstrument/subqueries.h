#ifndef SUBQUERIES_H
#define SUBQUERIES_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class subqueries;
}

class subqueries : public QWidget
{
    Q_OBJECT

public:
    explicit subqueries(QWidget *parent = nullptr);
    ~subqueries();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::subqueries *ui;
    QSqlQueryModel* model;
};

#endif // SUBQUERIES_H
