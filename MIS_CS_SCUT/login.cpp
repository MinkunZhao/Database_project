#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

int Login::identity = -1;

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_buttonBox_accepted()
{
    int cnt = 0;
    if (ui->teacher->isChecked())
    {
        cnt++;
        identity = 0;
    }
    if (ui->student->isChecked())
    {
        cnt++;
        identity = 1;
    }
    if (ui->administrator->isChecked())
    {
        cnt++;
        identity = 2;
    }
    if (cnt == 1 && ui->account_input->toPlainText() != "" && ui->password_input->toPlainText() != "")
    {
        this->close();
        main = new MainWindow();
        main->show();
    }
    else
        this->show();
}

void Login::on_buttonBox_rejected()
{
    this->close();
}
