#include "course_insert.h"
#include "ui_course_insert.h"
#include "prompt_box.h"

Course_Insert::Course_Insert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Course_Insert)
{
    ui->setupUi(this);
}


void Course_Insert::sqlHelper()
{
    Modify1_Administrator::flag = 8;
    QSqlQuery query;
    QString tempStr = QString("insert into Course (");
    bool first = true;
    if (ui->input_new_cou_id->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("Course_ID");
    }
    if (ui->input_new_name->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("Name");
    }
    if (ui->input_new_tea_id->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("Teacher_ID");
    }
    if (ui->input_new_credit->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("Credit");
    }
    if (ui->input_new_grade->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("Grade");
    }
    if (ui->input_new_canceled_year->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("Canceled_Year");
    }

    tempStr += QString(") values (");
    first = true;

    if (ui->input_new_cou_id->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("'") + ui->input_new_cou_id->toPlainText() + QString("'");
    }
    if (ui->input_new_name->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("'") + ui->input_new_name->toPlainText() + QString("'");
    }
    if (ui->input_new_tea_id->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("'") + ui->input_new_tea_id->toPlainText() + QString("'");
    }
    if (ui->input_new_credit->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("'") + ui->input_new_credit->toPlainText() + QString("'");
    }
    if (ui->input_new_grade->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("'") + ui->input_new_grade->toPlainText() + QString("'");
    }
    if (ui->input_new_canceled_year->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("'") + ui->input_new_canceled_year->toPlainText() + QString("'");
    }

    tempStr += QString(")");
    query.exec(tempStr);
}


Course_Insert::~Course_Insert()
{
    delete ui;
}


void Course_Insert::on_home_clicked()
{
    this->close();
    main->show();
}


void Course_Insert::on_ok_clicked()
{
    if (ui->input_new_cou_id->toPlainText() != "" && ui->input_new_name->toPlainText() != ""
            && ui->input_new_tea_id->toPlainText() != "" && ui->input_new_credit->toPlainText() != ""
            && ui->input_new_grade->toPlainText() != "")
    {
        sqlHelper();
        this->close();
        prompt = new Prompt_Box();
        prompt->show();
    }
}
