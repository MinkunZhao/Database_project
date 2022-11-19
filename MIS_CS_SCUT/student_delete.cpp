#include "student_delete.h"
#include "ui_student_delete.h"
#include "prompt_box.h"

Student_Delete::Student_Delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Student_Delete)
{
    ui->setupUi(this);
}


void Student_Delete::sqlHelper()
{
    QSqlQuery query;
    QString tempStr = QString("");
    bool first = true;

    if (ui->input_old_stu_id->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(" and ");
        else
            first = false;
        tempStr += QString("Student_ID = '") + ui->input_old_stu_id->toPlainText() + QString("'");
    }
    if (ui->input_old_name->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(" and ");
        else
            first = false;
        tempStr += QString("Name = '") + ui->input_old_name->toPlainText() + QString("'");
    }
    if (ui->input_old_sex->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(" and ");
        else
            first = false;
        tempStr += QString("Sex = '") + ui->input_old_sex->toPlainText() + QString("'");
    }
    if (ui->input_old_entrance_age->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(" and ");
        else
            first = false;
        tempStr += QString("Entrance_Age = '") + ui->input_old_entrance_age->toPlainText() + QString("'");
    }
    if (ui->input_old_entrance_year->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(" and ");
        else
            first = false;
        tempStr += QString("Entrance_Year = '") + ui->input_old_entrance_year->toPlainText() + QString("'");
    }
    if (ui->input_old_class->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(" and ");
        else
            first = false;
        tempStr += QString("Class = '") + ui->input_old_class->toPlainText() + QString("'");
    }

    query.exec("select 1 from Student where " + tempStr + " limit 1");
    if (query.isNull(0))
    {
        Modify1_Administrator::flag = 5;
        return;
    }

    Modify1_Administrator::flag = 4;
    query.exec("delete from Student where " + tempStr);
}


Student_Delete::~Student_Delete()
{
    delete ui;
}


void Student_Delete::on_home_clicked()
{
    this->close();
    main->show();
}


void Student_Delete::on_ok_clicked()
{
    if (ui->input_old_stu_id->toPlainText() != "" || ui->input_old_name->toPlainText() != ""
            || ui->input_old_sex->toPlainText() != "" || ui->input_old_entrance_age->toPlainText() != ""
            || ui->input_old_entrance_year->toPlainText() != "" || ui->input_old_class->toPlainText() != "")
    {
        sqlHelper();
        this->close();
        prompt = new Prompt_Box();
        prompt->show();
    }
}
