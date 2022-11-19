#include "choosing_modify.h"
#include "ui_choosing_modify.h"
#include "prompt_box.h"

Choosing_Modify::Choosing_Modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Choosing_Modify)
{
    ui->setupUi(this);
}


void Choosing_Modify::sqlHelper()
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
    if (ui->input_old_cou_id->toPlainText() != "")
    {
        if (!first)
            tempStr1 += QString(" and ");
        else
            first = false;
        tempStr1 += QString("Course_ID = '") + ui->input_old_cou_id->toPlainText() + QString("'");
    }
    if (ui->input_old_tea_id->toPlainText() != "")
    {
        if (!first)
            tempStr1 += QString(" and ");
        else
            first = false;
        tempStr1 += QString("Teacher_ID = '") + ui->input_old_tea_id->toPlainText() + QString("'");
    }
    if (ui->input_old_chosen_year->toPlainText() != "")
    {
        if (!first)
            tempStr1 += QString(" and ");
        else
            first = false;
        tempStr1 += QString("Chosen_Year = '") + ui->input_old_chosen_year->toPlainText() + QString("'");
    }

    query.exec("select 1 from Choosing where " + tempStr1 + " limit 1");
    if (query.isNull(0))
    {
        Modify1_Administrator::flag = 13;
        return;
    }

    Modify1_Administrator::flag = 12;
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
    if (ui->input_new_cou_id->toPlainText() != "")
    {
        if (!first)
            tempStr2 += QString(", ");
        else
            first = false;
        tempStr2 += QString("Course_ID = '") + ui->input_new_cou_id->toPlainText() + QString("'");
    }
    if (ui->input_new_tea_id->toPlainText() != "")
    {
        if (!first)
            tempStr2 += QString(", ");
        else
            first = false;
        tempStr2 += QString("Teacher_ID = '") + ui->input_new_tea_id->toPlainText() + QString("'");
    }
    if (ui->input_new_chosen_year->toPlainText() != "")
    {
        if (!first)
            tempStr2 += QString(", ");
        else
            first = false;
        tempStr2 += QString("Chosen_Year = '") + ui->input_new_chosen_year->toPlainText() + QString("'");
    }

    query.exec("update Choosing set " + tempStr2 + " where " + tempStr1);
}


Choosing_Modify::~Choosing_Modify()
{
    delete ui;
}


void Choosing_Modify::on_home_clicked()
{
    this->close();
    main->show();
}


void Choosing_Modify::on_ok_clicked()
{
    if ((ui->input_old_stu_id->toPlainText() != "" || ui->input_old_cou_id->toPlainText() != ""
         || ui->input_old_tea_id->toPlainText() != "" || ui->input_old_chosen_year->toPlainText() != "")
         && (ui->input_new_stu_id->toPlainText() != "" || ui->input_new_cou_id->toPlainText() != ""
         || ui->input_new_tea_id->toPlainText() != "" || ui->input_new_chosen_year->toPlainText() != ""))
    {
        sqlHelper();
        this->close();
        prompt = new Prompt_Box();
        prompt->show();
    }
}
