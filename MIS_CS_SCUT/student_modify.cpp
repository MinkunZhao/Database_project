#include "student_modify.h"
#include "ui_student_modify.h"
#include "prompt_box.h"

Student_Modify::Student_Modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Student_Modify)
{
    ui->setupUi(this);
}


void Student_Modify::sqlHelper()
{
    QString tempStr1 = QString("");
    bool first = true;
    QSqlQuery query;

    if (ui->input_old_stu_id->toPlainText() != "")
    {
        if (!first)
            tempStr1 += QString(" and ");
        else
            first = false;
        tempStr1 += QString("Student_ID = '") + ui->input_old_stu_id->toPlainText() + QString("'");
    }
    if (ui->input_old_name->toPlainText() != "")
    {
        if (!first)
            tempStr1 += QString(" and ");
        else
            first = false;
        tempStr1 += QString("Name = '") + ui->input_old_name->toPlainText() + QString("'");
    }
    if (ui->input_old_sex->toPlainText() != "")
    {
        if (!first)
            tempStr1 += QString(" and ");
        else
            first = false;
        tempStr1 += QString("Sex = '") + ui->input_old_sex->toPlainText() + QString("'");
    }
    if (ui->input_old_entrance_age->toPlainText() != "")
    {
        if (!first)
            tempStr1 += QString(" and ");
        else
            first = false;
        tempStr1 += QString("Entrance_Age = '") + ui->input_old_entrance_age->toPlainText() + QString("'");
    }
    if (ui->input_old_entrance_year->toPlainText() != "")
    {
        if (!first)
            tempStr1 += QString(" and ");
        else
            first = false;
        tempStr1 += QString("Entrance_Year = '") + ui->input_old_entrance_year->toPlainText() + QString("'");
    }
    if (ui->input_old_class->toPlainText() != "")
    {
        if (!first)
            tempStr1 += QString(" and ");
        else
            first = false;
        tempStr1 += QString("Class = '") + ui->input_old_class->toPlainText() + QString("'");
    }

    query.exec("select 1 from Student where " + tempStr1 + " limit 1");
    if (query.isNull(0))
    {
        Modify1_Administrator::flag = 1;
        return;
    }

    Modify1_Administrator::flag = 0;
    QString tempStr2;
    first = true;

    if (ui->input_new_stu_id->toPlainText() != "")
    {
        if (!first)
            tempStr2 += QString(", ");
        else
            first = false;
        tempStr2 += QString("Student_ID = '") + ui->input_new_stu_id->toPlainText() + QString("'");
    }
    if (ui->input_new_name->toPlainText() != "")
    {
        if (!first)
            tempStr2 += QString(", ");
        else
            first = false;
        tempStr2 += QString("Name = '") + ui->input_new_name->toPlainText() + QString("'");
    }
    if (ui->input_new_sex->toPlainText() != "")
    {
        if (!first)
            tempStr2 += QString(", ");
        else
            first = false;
        tempStr2 += QString("Sex = '") + ui->input_new_sex->toPlainText() + QString("'");
    }
    if (ui->input_new_entrance_age->toPlainText() != "")
    {
        if (!first)
            tempStr2 += QString(", ");
        else
            first = false;
        tempStr2 += QString("Entrance_Age = '") + ui->input_new_entrance_age->toPlainText() + QString("'");
    }
    if (ui->input_new_entrance_year->toPlainText() != "")
    {
        if (!first)
            tempStr2 += QString(", ");
        else
            first = false;
        tempStr2 += QString("Entrance_Year = '") + ui->input_new_entrance_year->toPlainText() + QString("'");
    }
    if (ui->input_new_class->toPlainText() != "")
    {
        if (!first)
            tempStr2 += QString(", ");
        else
            first = false;
        tempStr2 += QString("Class = '") + ui->input_new_class->toPlainText() + QString("'");
    }

    query.exec("update Student set " + tempStr2 + " where " + tempStr1);
}


Student_Modify::~Student_Modify()
{
    delete ui;
}


void Student_Modify::on_home_clicked()
{
    this->close();
    main->show();
}


void Student_Modify::on_ok_clicked()
{
    if ((ui->input_old_stu_id->toPlainText() != "" || ui->input_old_name->toPlainText() != ""
         || ui->input_old_sex->toPlainText() != "" || ui->input_old_entrance_age->toPlainText() != ""
         || ui->input_old_entrance_year->toPlainText() != "" || ui->input_old_class->toPlainText() != "")
         && (ui->input_new_stu_id->toPlainText() != "" || ui->input_new_name->toPlainText() != ""
         || ui->input_new_sex->toPlainText() != "" || ui->input_new_entrance_age->toPlainText() != ""
         || ui->input_new_entrance_year->toPlainText() != "" || ui->input_new_class->toPlainText() != ""))
    {
        sqlHelper();
        this->close();
        prompt = new Prompt_Box();
        prompt->show();
    }
}
