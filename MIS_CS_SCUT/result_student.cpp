#include "result_student.h"
#include "ui_result_student.h"

Result_Student::Result_Student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result_Student)
{
    ID = Input_Student::id;
    NAME = Input_Student::name;
    ui->setupUi(this);
    sqlHelper();
}


Result_Student::~Result_Student()
{
    delete ui;
}


void Result_Student::sqlHelper()
{
    QString id;
    QString name;
    QString sex;
    QString entrance_age;
    QString entrance_year;
    QString class_;
    QSqlQuery query;
    QString display = "";
    //qDebug()<<QString::fromStdString(ID);
    if (ID == "" && NAME == "")
        query.exec("select * from Student");
    else if (ID != "" && NAME == "")
        query.exec("select * from Student where Student_ID = " + QString::fromStdString(ID));
    else if (ID == "" && NAME != "")
        query.exec("select * from Student where Name = '" + QString::fromStdString(NAME) + "'");
    else
        query.exec("select * from Student where Student_ID = " + QString::fromStdString(ID) + " and Name = '" + QString::fromStdString(NAME) + "'");

    display += "Student_ID  Name  Sex  Entrance_Age  Entrance_Year  Class\n";
    while(query.next())
    {
        id = query.value(0).toString();
        name = query.value(1).toString();
        sex = query.value(2).toString();
        entrance_age = query.value(3).toString();
        entrance_year = query.value(4).toString();
        class_ = query.value(5).toString();
        display += id+"  "+name+"  "+sex+"  "+entrance_age+"  "+entrance_year+"  "+class_+"\n";
    }
    ui->textBrowser->setText(display);
}


void Result_Student::on_home_clicked()
{
    this->close();
    main->show();
}
