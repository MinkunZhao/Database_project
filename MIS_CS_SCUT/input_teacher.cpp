#include "input_teacher.h"
#include "ui_input_teacher.h"
#include "result_teacher.h"

string Input_Teacher::id = "";
string Input_Teacher::name = "";

Input_Teacher::Input_Teacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Input_Teacher)
{
    ui->setupUi(this);
}


Input_Teacher::~Input_Teacher()
{
    delete ui;
}


void Input_Teacher::on_home_clicked()
{
    this->close();
    main->show();
}


void Input_Teacher::on_ok_clicked()
{
    id = ui->input_ID->toPlainText().toStdString();
    name = ui->input_Name->toPlainText().toStdString();
    this->close();
    res_tea = new Result_Teacher();
    res_tea->show();
}
