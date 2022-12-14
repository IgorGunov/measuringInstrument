#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_pushButton_clicked();

signals:
    void refresh_table();

private:
    Ui::Form *ui;
};

#endif // FORM_H
