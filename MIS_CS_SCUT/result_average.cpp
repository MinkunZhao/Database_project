#include "result_average.h"
#include "ui_result_average.h"

Result_Average::Result_Average(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result_Average)
{
    STUDENT_ID = Input_Average::student_id;
    STUDENT_NAME = Input_Average::student_name;
    COURSE_ID = Input_Average::course_id;
    COURSE_NAME = Input_Average::course_name;
    CLASS = Input_Average::class_;
    ui->setupUi(this);
    sqlHelper();
}


Result_Average::~Result_Average()
{
    delete ui;
}


void Result_Average::sqlHelper()
{
    QSqlQuery query;
    QString average;
    QString student_id;
    QString student_name;
    QString course_id;
    QString course_name;
    QString class_;
    if (STUDENT_ID == "" && STUDENT_NAME == "" && COURSE_ID == "" && COURSE_NAME == "" && CLASS == "")
    {
        query.exec("select avg(Score) as AverageScore from Choosing");
        query.next();
        average = query.value(0).toString();
        ui->textBrowser->setText("all students' all courses' average score: " + average);
    }
    else if (STUDENT_ID != "")
    {
        query.exec("select cho.Student_ID, stu.Name, avg(cho.Score) as AverageScore from Choosing cho, Student stu where cho.Student_ID = stu.Student_ID and cho.Student_ID = " + QString::fromStdString(STUDENT_ID) + " group by cho.Student_ID, stu.Name");
        query.next();
        student_id = query.value(0).toString();
        student_name = query.value(1).toString();
        average = query.value(2).toString();
        ui->textBrowser->setText("Student_ID  Student_Name  Average_Score\n" + student_id + "  " + student_name + "  " + average);
    }
    else if (STUDENT_NAME != "")
    {
        query.exec("select cho.Student_ID, stu.Name, avg(cho.Score) as AverageScore from Choosing cho, Student stu where cho.Student_ID = stu.Student_ID and stu.Name = '" + QString::fromStdString(STUDENT_NAME) + "' group by cho.Student_ID, stu.Name");
        query.next();
        student_id = query.value(0).toString();
        student_name = query.value(1).toString();
        average = query.value(2).toString();
        ui->textBrowser->setText("Student_ID  Student_Name  Average_Score\n" + student_id + "  " + student_name + "  " + average);
    }
    else if (COURSE_ID != "")
    {
        query.exec("select cho.Course_ID, cou.Name, avg(cho.Score) as AverageScore from Choosing cho, Course cou where cho.Course_ID = cou.Course_ID and cho.Course_ID = " + QString::fromStdString(COURSE_ID) + " group by cho.Course_ID, cou.Name");
        query.next();
        course_id = query.value(0).toString();
        course_name = query.value(1).toString();
        average = query.value(2).toString();
        ui->textBrowser->setText("Course_ID  Course_Name  Average_Score\n" + course_id + "  " + course_name + "  " + average);
    }
    else if (COURSE_NAME != "")
    {
        query.exec("select cho.Course_ID, cou.Name, avg(cho.Score) as AverageScore from Choosing cho, Course cou where cho.Course_ID = cou.Course_ID and cou.Name = '" + QString::fromStdString(COURSE_NAME) + "' group by cho.Course_ID, cou.Name");
        query.next();
        course_id = query.value(0).toString();
        course_name = query.value(1).toString();
        average = query.value(2).toString();
        ui->textBrowser->setText("Course_ID  Course_Name  Average_Score\n" + course_id + "  " + course_name + "  " + average);
    }
    else if (CLASS != "")
    {
        query.exec("select stu.Class, avg(cho.Score) as AverageScore from Student stu, Choosing cho where stu.Student_ID = cho.Student_ID and stu.Class = '" + QString::fromStdString(CLASS) + "' group by stu.Class");
        query.next();
        class_ = query.value(0).toString();
        average = query.value(1).toString();
        ui->textBrowser->setText("Class  Average_Score\n" + class_ + "  " + average);
    }
}


void Result_Average::on_home_clicked()
{
    this->close();
    main->show();
}
