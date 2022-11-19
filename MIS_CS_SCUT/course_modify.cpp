#include "course_modify.h"
#include "ui_course_modify.h"
#include "prompt_box.h"

Course_Modify::Course_Modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Course_Modify)
{
    ui->setupUi(this);
}


void Course_Modify::sqlHelper()
{
    QString tempStr1 = QString("");
    bool first = true;
    QSqlQuery query;

    if (ui->input_old_cou_id->toPlainText() != "")
    {
        if (!first)
            tempStr1 += QString(" and ");
        else
            first = false;
        tempStr1 += QString("Course_ID = '") + ui->input_old_cou_id->toPlainText() + QString("'");
    }
    if (ui->input_old_name->toPlainText() != "")
    {
        if (!first)
            tempStr1 += QString(" and ");
        else
            first = false;
        tempStr1 += QString("Name = '") + ui->input_old_name->toPlainText() + QString("'");
    }
    if (ui->input_old_tea_id->toPlainText() != "")
    {
        if (!first)
            tempStr1 += QString(" and ");
        else
            first = false;
        tempStr1 += QString("Teacher_ID = '") + ui->input_old_tea_id->toPlainText() + QString("'");
    }
    if (ui->input_old_credit->toPlainText() != "")
    {
        if (!first)
            tempStr1 += QString(" and ");
        else
            first = false;
        tempStr1 += QString("Credit = '") + ui->input_old_credit->toPlainText() + QString("'");
    }
    if (ui->input_old_grade->toPlainText() != "")
    {
        if (!first)
            tempStr1 += QString(" and ");
        else
            first = false;
        tempStr1 += QString("Grade = '") + ui->input_old_grade->toPlainText() + QString("'");
    }
    if (ui->input_old_canceled_year->toPlainText() != "")
    {
        if (!first)
            tempStr1 += QString(" and ");
        else
            first = false;
        tempStr1 += QString("Canceled_Year = '") + ui->input_old_canceled_year->toPlainText() + QString("'");
    }

    query.exec("select 1 from Course where " + tempStr1 + " limit 1");
    if (query.isNull(0))
    {
        Modify1_Administrator::flag = 7;
        return;
    }

    Modify1_Administrator::flag = 6;
    QString tempStr2;
    first = true;

    if (ui->input_new_cou_id->toPlainText() != "")
    {
        if (!first)
            tempStr2 += QString(", ");
        else
            first = false;
        tempStr2 += QString("Course_ID = '") + ui->input_new_cou_id->toPlainText() + QString("'");
    }
    if (ui->input_new_name->toPlainText() != "")
    {
        if (!first)
            tempStr2 += QString(", ");
        else
            first = false;
        tempStr2 += QString("Name = '") + ui->input_new_name->toPlainText() + QString("'");
    }
    if (ui->input_new_tea_id->toPlainText() != "")
    {
        if (!first)
            tempStr2 += QString(", ");
        else
            first = false;
        tempStr2 += QString("Teacher_ID = '") + ui->input_new_tea_id->toPlainText() + QString("'");
    }
    if (ui->input_new_credit->toPlainText() != "")
    {
        if (!first)
            tempStr2 += QString(", ");
        else
            first = false;
        tempStr2 += QString("Credit = '") + ui->input_new_credit->toPlainText() + QString("'");
    }
    if (ui->input_new_grade->toPlainText() != "")
    {
        if (!first)
            tempStr2 += QString(", ");
        else
            first = false;
        tempStr2 += QString("Grade = '") + ui->input_new_grade->toPlainText() + QString("'");
    }
    if (ui->input_new_canceled_year->toPlainText() != "")
    {
        if (!first)
            tempStr2 += QString(", ");
        else
            first = false;
        tempStr2 += QString("Canceled_Year = '") + ui->input_new_canceled_year->toPlainText() + QString("'");
    }

    query.exec("update Course set " + tempStr2 + " where " + tempStr1);
}


Course_Modify::~Course_Modify()
{
    delete ui;
}


void Course_Modify::on_home_clicked()
{
    this->close();
    main->show();
}


void Course_Modify::on_ok_clicked()
{
    if ((ui->input_old_cou_id->toPlainText() != "" || ui->input_old_name->toPlainText() != ""
         || ui->input_old_tea_id->toPlainText() != "" || ui->input_old_credit->toPlainText() != ""
         || ui->input_old_grade->toPlainText() != "" || ui->input_old_canceled_year->toPlainText() != "")
         && (ui->input_new_cou_id->toPlainText() != "" || ui->input_new_name->toPlainText() != ""
         || ui->input_new_tea_id->toPlainText() != "" || ui->input_new_credit->toPlainText() != ""
         || ui->input_new_grade->toPlainText() != "" || ui->input_new_canceled_year->toPlainText() != ""))
    {
        sqlHelper();
        this->close();
        prompt = new Prompt_Box();
        prompt->show();
    }
}
