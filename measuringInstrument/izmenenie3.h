#ifndef IZMENENIE3_H
#define IZMENENIE3_H

#include <QWidget>
#include <QSqlQuery>

namespace Ui {
class izmenenie3;
}

class izmenenie3 : public QWidget
{
    Q_OBJECT

public:
    explicit izmenenie3(QWidget *parent = nullptr);
    ~izmenenie3();

private slots:
    void obr_sendId(int);

    void on_pushButton_clicked();

private:
    Ui::izmenenie3 *ui;
};

#endif // IZMENENIE3_H
