#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
//#include "mainwindow.h"

namespace Ui {
class Login;
}

class MainWindow;

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

    static int identity;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Login *ui;
    MainWindow *main;
};

#endif // LOGIN_H
