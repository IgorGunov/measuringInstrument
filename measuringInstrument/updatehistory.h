#ifndef UPDATEHISTORY_H
#define UPDATEHISTORY_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class updatehistory;
}

class updatehistory : public QWidget
{
    Q_OBJECT

public:
    explicit updatehistory(QWidget *parent = nullptr);
    ~updatehistory();

    int postcombo;
    int postcombo2;

private slots:
    void obr_sendId(int);

    void on_pushButton_clicked();

signals:
    void refresh_table();

private:
    Ui::updatehistory *ui;
};

#endif // UPDATEHISTORY_H
