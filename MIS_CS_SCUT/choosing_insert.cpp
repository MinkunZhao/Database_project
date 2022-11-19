#include "choosing_insert.h"
#include "ui_choosing_insert.h"
#include "prompt_box.h"

Choosing_Insert::Choosing_Insert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Choosing_Insert)
{
    ui->setupUi(this);
}


void Choosing_Insert::sqlHelper()
{
    Modify1_Administrator::flag = 14;
    QSqlQuery query;
    QString tempStr = QString("insert into Choosing (");
    bool first = true;
    if (ui->input_new_stu_id->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("Student_ID");
    }
    if (ui->input_new_cou_id->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("Course_ID");
    }
    if (ui->input_new_tea_id->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("Teacher_ID");
    }
    if (ui->input_new_chosen_year->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("Chosen_Year");
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
    if (ui->input_new_cou_id->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("'") + ui->input_new_cou_id->toPlainText() + QString("'");
    }
    if (ui->input_new_tea_id->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("'") + ui->input_new_tea_id->toPlainText() + QString("'");
    }
    if (ui->input_new_chosen_year->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(", ");
        else
            first = false;
        tempStr += QString("'") + ui->input_new_chosen_year->toPlainText() + QString("'");
    }

    tempStr += QString(")");
    query.exec(tempStr);
}


Choosing_Insert::~Choosing_Insert()
{
    delete ui;
}


void Choosing_Insert::on_home_clicked()
{
    this->close();
    main->show();
}


void Choosing_Insert::on_ok_clicked()
{
    if (ui->input_new_stu_id->toPlainText() != "" && ui->input_new_cou_id->toPlainText() != ""
         && ui->input_new_tea_id->toPlainText() != "" && ui->input_new_chosen_year->toPlainText() != "")
    {
        sqlHelper();
        this->close();
        prompt = new Prompt_Box();
        prompt->show();
    }
}
