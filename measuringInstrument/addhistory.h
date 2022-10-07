#ifndef ADDHISTORY_H
#define ADDHISTORY_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>
#include <QTimer>

namespace Ui {
class addHistory;
}

class addHistory : public QWidget
{
    Q_OBJECT

public:
    explicit addHistory(QWidget *parent = nullptr);
    ~addHistory();

    int postcombo;
    int postcombo2;

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

signals:
    void refresh_table();

private:
    Ui::addHistory *ui;
};

#endif // ADDHISTORY_H
