#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "login.h"
#include "ui_login.h"
#include "addrecord.h"
#include "ui_addrecord.h"
#include "addrecord2.h"
#include "ui_addrecord2.h"
#include "addrecord3.h"
#include "ui_addrecord3.h"
#include "izmenenie.h"
#include "ui_izmenenie.h"
#include "izmenenie2.h"
#include "ui_izmenenie2.h"
#include "izmenenie3.h"
#include "ui_izmenenie3.h"
#include "izmenenie4.h"
#include "ui_izmenenie4.h"
#include "form.h"
#include "ui_form.h"
#include "addhistory.h"
#include "ui_addhistory.h"
#include "subqueries.h"
#include "ui_subqueries.h"
#include "updatehistory.h"
#include "ui_updatehistory.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Login* logwin;
    addrecord* dobzap;
    izmenenie* izm;
    izmenenie2* izm2;
    izmenenie3* izm3;
    izmenenie4* izm4;
    updatehistory* izm5;
    Form* dobzap2;
    addrecord2* dobzap3;
    addrecord3* dobzap4;
    addHistory* dobzap5;
    subqueries* sub;

    int globid;
    int recId;
    int fl;

private slots:
    void on_action_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void obt_ref_tab();

    void CustomMenuReq(QPoint);

    void del_zap();

    void del_zap2();

    void del_zap3();

    void del_zap4();

    void del_zap5();

    void izm_zap();

    void izm_zap2();

    void izm_zap3();

    void izm_zap4();

    void izm_zap5();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void obt_ref_tab2();

    void on_pushButton_3_clicked();

    void obt_ref_tab3();

    void on_pushButton_4_clicked();

    void obt_ref_tab4();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void obt_ref_tab5();

signals:
    void sendId(int);

private:
    Ui::MainWindow *ui;
    QSqlQueryModel* model;
};
#endif // MAINWINDOW_H
