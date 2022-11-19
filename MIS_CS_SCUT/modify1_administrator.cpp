#include "modify1_administrator.h"
#include "ui_modify1_administrator.h"
#include "student_modify.h"
#include "student_insert.h"
#include "student_delete.h"
#include "course_modify.h"
#include "course_insert.h"
#include "course_delete.h"
#include "choosing_modify.h"
#include "choosing_insert.h"
#include "choosing_delete.h"

int Modify1_Administrator::flag = -1;

Modify1_Administrator::Modify1_Administrator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modify1_Administrator)
{
    ui->setupUi(this);
}


Modify1_Administrator::~Modify1_Administrator()
{
    delete ui;
}


void Modify1_Administrator::on_home_clicked()
{
    this->close();
    main->show();
}


void Modify1_Administrator::on_ok_clicked()
{
    if (ui->comboBox1->currentIndex() == 0 || ui->comboBox2->currentIndex() == 0)
        return;
    if (ui->comboBox1->currentIndex() == 1)
    {
        if (ui->comboBox2->currentIndex() == 1)
        {
            stu_mod = new Student_Modify();
            stu_mod->show();
        }
        else if (ui->comboBox2->currentIndex() == 2)
        {
            stu_ins = new Student_Insert();
            stu_ins->show();
        }
        else if (ui->comboBox2->currentIndex() == 3)
        {
            stu_del = new Student_Delete();
            stu_del->show();
        }
    }
    else if (ui->comboBox1->currentIndex() == 2)
    {
        if (ui->comboBox2->currentIndex() == 1)
        {
            cou_mod = new Course_Modify();
            cou_mod->show();
        }
        else if (ui->comboBox2->currentIndex() == 2)
        {
            cou_ins = new Course_Insert();
            cou_ins->show();
        }
        else if (ui->comboBox2->currentIndex() == 3)
        {
            cou_del = new Course_Delete();
            cou_del->show();
        }
    }
    else if (ui->comboBox1->currentIndex() == 3)
    {
        if (ui->comboBox2->currentIndex() == 1)
        {
            cho_mod = new Choosing_Modify();
            cho_mod->show();
        }
        else if (ui->comboBox2->currentIndex() == 2)
        {
            cho_ins = new Choosing_Insert();
            cho_ins->show();
        }
        else if (ui->comboBox2->currentIndex() == 3)
        {
            cho_del = new Choosing_Delete();
            cho_del->show();
        }
    }
    this->close();
}
