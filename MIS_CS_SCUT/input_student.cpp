#include "input_student.h"
#include "ui_input_student.h"
#include "result_student.h"

string Input_Student::id = "";
string Input_Student::name = "";

Input_Student::Input_Student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Input_Student)
{
    ui->setupUi(this);
}


Input_Student::~Input_Student()
{
    delete ui;
}


void Input_Student::on_home_clicked()
{
    main->show();
    this->close();
}


void Input_Student::on_ok_clicked()
{
    id = ui->input_ID->toPlainText().toStdString();
    name = ui->input_Name->toPlainText().toStdString();
    res_stu = new Result_Student();
    res_stu->show();
    this->close();
}
