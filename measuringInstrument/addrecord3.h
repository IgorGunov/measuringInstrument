#ifndef ADDRECORD3_H
#define ADDRECORD3_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class addrecord3;
}

class addrecord3 : public QWidget
{
    Q_OBJECT

public:
    explicit addrecord3(QWidget *parent = nullptr);
    ~addrecord3();

    int postcombo;
    int postcombo2;

private slots:
    void on_pushButton_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_currentIndexChanged(int index);

signals:
    void refresh_table();

private:
    Ui::addrecord3 *ui;
};

#endif // ADDRECORD3_H
