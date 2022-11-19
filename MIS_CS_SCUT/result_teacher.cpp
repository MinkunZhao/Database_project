#include "result_teacher.h"
#include "ui_result_teacher.h"

Result_Teacher::Result_Teacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result_Teacher)
{
    ID = Input_Teacher::id;
    NAME = Input_Teacher::name;
    ui->setupUi(this);
    sqlHelper();
}


Result_Teacher::~Result_Teacher()
{
    delete ui;
}


void Result_Teacher::sqlHelper()
{
    QString teacher_id;
    QString teacher_name;
    QString courses;
    QSqlQuery query;
    QString display = "";
    if (ID == "" && NAME == "")
        query.exec("select * from Teacher");
    else if (ID != "" && NAME == "")
        query.exec("select * from Teacher where Teacher_ID = " + QString::fromStdString(ID));
    else if (ID == "" && NAME != "")
        query.exec("select * from Teacher where Name = '" + QString::fromStdString(NAME) + "'");
    else
        query.exec("select * from Teacher where Teacher_ID = " + QString::fromStdString(ID) + " and Name = '" + QString::fromStdString(NAME) + "'");

    display += "Teacher_ID  Name  Courses\n";
    while(query.next())
    {
        teacher_id = query.value(0).toString();
        teacher_name = query.value(1).toString();
        courses = query.value(2).toString();
        display += teacher_id+"  "+teacher_name+"  "+courses+"\n";
    }
    ui->textBrowser->setText(display);
}


void Result_Teacher::on_home_clicked()
{
    this->close();
    main->show();
}
