#include "prompt_box.h"
#include "ui_prompt_box.h"

Prompt_Box::Prompt_Box(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Prompt_Box)
{
    ui->setupUi(this);
    promptHelper();
}


void Prompt_Box::promptHelper()
{
    flag1 = Modify1_Administrator::flag;
    flag2 = Modify_Teacher::flag;
    if (flag2 == -1)
    {
        if (flag1 == 0)
            ui->label->setText("Successfully modify\nthe student's information!");
        else if (flag1 == 1)
            ui->label->setText("Fail in modifying\nthe student's information!");
        else if (flag1 == 2)
            ui->label->setText("Successfully insert\nthe student's information!");
        else if (flag1 == 3)
            ui->label->setText("Fail in inserting\nthe student's information!");
        else if (flag1 == 4)
            ui->label->setText("Successfully delete\nthe student's information!");
        else if (flag1 == 5)
            ui->label->setText("Fail in deleting\nthe student's information!");
        else if (flag1 == 6)
            ui->label->setText("Successfully modify\nthe course's information!");
        else if (flag1 == 7)
            ui->label->setText("Fail in modifying\nthe course's information!");
        else if (flag1 == 8)
            ui->label->setText("Successfully insert\nthe course's information!");
        else if (flag1 == 9)
            ui->label->setText("Fail in inserting\nthe course's information!");
        else if (flag1 == 10)
            ui->label->setText("Successfully delete\nthe course's information!");
        else if (flag1 == 11)
            ui->label->setText("Fail in deleting\nthe course's information!");
        else if (flag1 == 12)
            ui->label->setText("Successfully modify the\ncourse choosing's information!");
        else if (flag1 == 13)
            ui->label->setText("Fail in modifying the\ncourse choosing's information!");
        else if (flag1 == 14)
            ui->label->setText("Successfully insert the\ncourse choosing's information!");
        else if (flag1 == 15)
            ui->label->setText("Fail in inserting the\ncourse choosing's information!");
        else if (flag1 == 16)
            ui->label->setText("Successfully delete the\ncourse choosing information!");
        else if (flag1 == 17)
            ui->label->setText("Fail in deleting the\ncourse choosing information!");
    }
    else    //flag1 == -1
    {
        if (flag2)  // 1: set score fail
            ui->label->setText("Fail in setting the score!\nThe Student or Course\nyou input does not exist.");
        else
            ui->label->setText("Successfully set the score!");
    }
}


Prompt_Box::~Prompt_Box()
{
    delete ui;
}


void Prompt_Box::on_home_clicked()
{
    this->close();
    main->show();
}
