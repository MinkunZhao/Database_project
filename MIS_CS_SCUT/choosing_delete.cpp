#include "choosing_delete.h"
#include "ui_choosing_delete.h"
#include "prompt_box.h"

Choosing_Delete::Choosing_Delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Choosing_Delete)
{
    ui->setupUi(this);
}


void Choosing_Delete::sqlHelper()
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
    if (ui->input_old_cou_id->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(" and ");
        else
            first = false;
        tempStr += QString("Course_ID = '") + ui->input_old_cou_id->toPlainText() + QString("'");
    }
    if (ui->input_old_tea_id->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(" and ");
        else
            first = false;
        tempStr += QString("Teacher_ID = '") + ui->input_old_tea_id->toPlainText() + QString("'");
    }
    if (ui->input_old_chosen_year->toPlainText() != "")
    {
        if (!first)
            tempStr += QString(" and ");
        else
            first = false;
        tempStr += QString("Chosen_Year = '") + ui->input_old_chosen_year->toPlainText() + QString("'");
    }

    query.exec("select 1 from Choosing where " + tempStr + " limit 1");
    if (query.isNull(0))
    {
        Modify1_Administrator::flag = 17;
        return;
    }

    Modify1_Administrator::flag = 16;
    query.exec("delete from Choosing where " + tempStr);
}


Choosing_Delete::~Choosing_Delete()
{
    delete ui;
}


void Choosing_Delete::on_home_clicked()
{
    this->close();
    main->show();
}


void Choosing_Delete::on_ok_clicked()
{
    if (ui->input_old_stu_id->toPlainText() != "" || ui->input_old_cou_id->toPlainText() != ""
         || ui->input_old_tea_id->toPlainText() != "" || ui->input_old_chosen_year->toPlainText() != "")
    {
        sqlHelper();
        this->close();
        prompt = new Prompt_Box();
        prompt->show();
    }
}
