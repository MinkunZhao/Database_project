#include "course_delete.h"
#include "ui_course_delete.h"
#include "prompt_box.h"

Course_Delete::Course_Delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Course_Delete)
{
    ui->setupUi(this);
}


void Course_Delete::sqlHelper()
{
    QSqlQuery query;
    QString tempStr = QString("");
    bool first = true;

    if (ui->input_old_cou_id->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(" and ");
        else
            first = false;
        tempStr += QString("Course_ID = '") + ui->input_old_cou_id->toPlainText() + QString("'");
    }
    if (ui->input_old_name->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(" and ");
        else
            first = false;
        tempStr += QString("Name = '") + ui->input_old_name->toPlainText() + QString("'");
    }
    if (ui->input_old_tea_id->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(" and ");
        else
            first = false;
        tempStr += QString("Teacher_ID = '") + ui->input_old_tea_id->toPlainText() + QString("'");
    }
    if (ui->input_old_credit->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(" and ");
        else
            first = false;
        tempStr += QString("Credit = '") + ui->input_old_credit->toPlainText() + QString("'");
    }
    if (ui->input_old_grade->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(" and ");
        else
            first = false;
        tempStr += QString("Grade = '") + ui->input_old_grade->toPlainText() + QString("'");
    }
    if (ui->input_old_canceled_year->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(" and ");
        else
            first = false;
        tempStr += QString("Canceled_Year = '") + ui->input_old_canceled_year->toPlainText() + QString("'");
    }

    query.exec("select 1 from Course where " + tempStr + " limit 1");
    if (query.isNull(0))
    {
        Modify1_Administrator::flag = 11;
        return;
    }

    Modify1_Administrator::flag = 10;
    query.exec("delete from Course where " + tempStr);
}


Course_Delete::~Course_Delete()
{
    delete ui;
}


void Course_Delete::on_home_clicked()
{
    this->close();
    main->show();
}


void Course_Delete::on_ok_clicked()
{
    if (ui->input_old_cou_id->toPlainText() != "" || ui->input_old_name->toPlainText() != ""
            || ui->input_old_tea_id->toPlainText() != "" || ui->input_old_credit->toPlainText() != ""
            || ui->input_old_grade->toPlainText() != "" || ui->input_old_canceled_year->toPlainText() != "")
    {
        sqlHelper();
        this->close();
        prompt = new Prompt_Box();
        prompt->show();
    }
}
