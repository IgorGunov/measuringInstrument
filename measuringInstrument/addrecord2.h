#ifndef ADDRECORD2_H
#define ADDRECORD2_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class addrecord2;
}

class addrecord2 : public QWidget
{
    Q_OBJECT

public:
    explicit addrecord2(QWidget *parent = nullptr);
    ~addrecord2();

private slots:
    void on_pushButton_clicked();

signals:
    void refresh_table();

private:
    Ui::addrecord2 *ui;
};

#endif // ADDRECORD2_H
