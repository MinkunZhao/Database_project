#include "student_insert.h"
#include "ui_student_insert.h"
#include "prompt_box.h"

Student_Insert::Student_Insert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Student_Insert)
{
    ui->setupUi(this);
}


void Student_Insert::sqlHelper()
{
    Modify1_Administrator::flag = 2;
    QSqlQuery query;
    QString tempStr = QString("insert into Student (");
    bool first = true;
    if (ui->input_new_stu_id->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("Student_ID");
    }
    if (ui->input_new_name->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("Name");
    }
    if (ui->input_new_sex->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("Sex");
    }
    if (ui->input_new_entrance_age->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("Entrance_Age");
    }
    if (ui->input_new_entrance_year->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("Entrance_Year");
    }
    if (ui->input_new_class->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("Class");
    }

    tempStr += QString(") values (");
    first = true;

    if (ui->input_new_stu_id->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("'") + ui->input_new_stu_id->toPlainText() + QString("'");
    }
    if (ui->input_new_name->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("'") + ui->input_new_name->toPlainText() + QString("'");
    }
    if (ui->input_new_sex->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("'") + ui->input_new_sex->toPlainText() + QString("'");
    }
    if (ui->input_new_entrance_age->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("'") + ui->input_new_entrance_age->toPlainText() + QString("'");
    }
    if (ui->input_new_entrance_year->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("'") + ui->input_new_entrance_year->toPlainText() + QString("'");
    }
    if (ui->input_new_class->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("'") + ui->input_new_class->toPlainText() + QString("'");
    }

    tempStr += QString(")");
    query.exec(tempStr);
}


Student_Insert::~Student_Insert()
{
    delete ui;
}


void Student_Insert::on_home_clicked()
{
    this->close();
    main->show();
}


void Student_Insert::on_ok_clicked()
{
    if (ui->input_new_stu_id->toPlainText() != "" && ui->input_new_name->toPlainText() != ""
            && ui->input_new_sex->toPlainText() != "" && ui->input_new_entrance_age->toPlainText() != ""
            && ui->input_new_entrance_year->toPlainText() != "" && ui->input_new_class->toPlainText() != "")
    {
        sqlHelper();
        this->close();
        prompt = new Prompt_Box();
        prompt->show();
    }
}
