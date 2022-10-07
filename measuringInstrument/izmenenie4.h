#ifndef IZMENENIE4_H
#define IZMENENIE4_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class izmenenie4;
}

class izmenenie4 : public QWidget
{
    Q_OBJECT

public:
    explicit izmenenie4(QWidget *parent = nullptr);
    ~izmenenie4();
    int postcombo;
    int postcombo2;


private slots:
    void obr_sendId(int);

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

private:
    Ui::izmenenie4 *ui;
};

#endif // IZMENENIE4_H
