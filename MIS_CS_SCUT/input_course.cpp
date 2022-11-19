#include "input_course.h"
#include "ui_input_course.h"
#include "result_course.h"

string Input_Course::id = "";
string Input_Course::name = "";

Input_Course::Input_Course(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Input_Course)
{
    ui->setupUi(this);
}


Input_Course::~Input_Course()
{
    delete ui;
}


void Input_Course::on_home_clicked()
{
    main->show();
    this->close();
}


void Input_Course::on_ok_clicked()
{
    id = ui->input_ID->toPlainText().toStdString();
    name = ui->input_Name->toPlainText().toStdString();
    res_cou = new Result_Course();
    res_cou->show();
    this->close();
}
