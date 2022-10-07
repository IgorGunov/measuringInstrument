#ifndef IZMENENIE2_H
#define IZMENENIE2_H

#include <QWidget>
#include <QSqlQuery>

namespace Ui {
class izmenenie2;
}

class izmenenie2 : public QWidget
{
    Q_OBJECT

public:
    explicit izmenenie2(QWidget *parent = nullptr);
    ~izmenenie2();

private slots:
    void obr_sendId(int);

    void on_pushButton_clicked();

private:
    Ui::izmenenie2 *ui;
};

#endif // IZMENENIE2_H
