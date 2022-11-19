#include "input_score.h"
#include "ui_input_score.h"
#include "result_score.h"

string Input_Score::student_id = "";
string Input_Score::student_name = "";
string Input_Score::course_id = "";
string Input_Score::course_name = "";

Input_Score::Input_Score(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Input_Score)
{
    ui->setupUi(this);
}


Input_Score::~Input_Score()
{
    delete ui;
}


void Input_Score::on_home_clicked()
{
    this->close();
    main->show();
}


void Input_Score::on_ok_clicked()
{
    student_id = ui->input_stu_id->toPlainText().toStdString();
    student_name = ui->input_stu_name->toPlainText().toStdString();
    course_id = ui->input_cou_id->toPlainText().toStdString();
    course_name = ui->input_cou_name->toPlainText().toStdString();
    res_sco = new Result_Score();
    this->close();
    res_sco->show();
}
