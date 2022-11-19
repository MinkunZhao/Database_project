#include "modify_teacher.h"
#include "ui_modify_teacher.h"
#include "prompt_box.h"

int Modify_Teacher::flag = -1;

Modify_Teacher::Modify_Teacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modify_Teacher)
{
    ui->setupUi(this);
}


void Modify_Teacher::sqlHelper()
{
    if (ui->input_score->toPlainText().toInt() < 0 || ui->input_score->toPlainText().toInt() > 100)
    {
        Modify_Teacher::flag = 1;
        return;
    }

    QString tempStr = QString("Student_ID = '") + ui->input_stu_id->toPlainText() + QString("' and Course_ID = '") + ui->input_cou_id->toPlainText() + QString("'");
    QSqlQuery query;

    query.exec("select * from Choosing where " + tempStr);
    if (query.isNull(0))
    {
        Modify1_Administrator::flag = 1;
        return;
    }

    Modify1_Administrator::flag = 0;
    query.exec("update Choosing set Score = '" + ui->input_score->toPlainText() + "' where " + tempStr);
}


Modify_Teacher::~Modify_Teacher()
{
    delete ui;
}


void Modify_Teacher::on_home_clicked()
{
    this->close();
    main->show();
}


void Modify_Teacher::on_ok_clicked()
{
    if (ui->input_score->toPlainText() != "" && ui->input_stu_id->toPlainText() != "" && ui->input_cou_id->toPlainText() != "")
    {
        //sqlHelper();
        this->close();
        prompt = new Prompt_Box();
        prompt->show();
    }
}
