#include "input_average.h"
#include "ui_input_average.h"
#include "result_average.h"

string Input_Average::student_id = "";
string Input_Average::student_name = "";
string Input_Average::course_id = "";
string Input_Average::course_name = "";
string Input_Average::class_ = "";

Input_Average::Input_Average(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Input_Average)
{
    ui->setupUi(this);
}


Input_Average::~Input_Average()
{
    delete ui;
}


void Input_Average::on_home_clicked()
{
    this->close();
    main->show();
}


void Input_Average::on_ok_clicked()
{
    student_id = ui->input_stu_id->toPlainText().toStdString();
    student_name = ui->input_stu_name->toPlainText().toStdString();
    course_id = ui->input_cou_id->toPlainText().toStdString();
    course_name = ui->input_cou_name->toPlainText().toStdString();
    class_ = ui->input_class->toPlainText().toStdString();
    this->close();
    res_ave = new Result_Average();
    res_ave->show();
}
