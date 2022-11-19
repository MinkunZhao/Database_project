#include "result_course.h"
#include "ui_result_course.h"

Result_Course::Result_Course(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result_Course)
{
    ID = Input_Course::id;
    NAME = Input_Course::name;
    ui->setupUi(this);
    sqlHelper();
}


Result_Course::~Result_Course()
{
    delete ui;
}


void Result_Course::sqlHelper()
{
    QString course_id;
    QString course_name;
    QString teacher_id;
    QString teacher_name;
    QString credit;
    QString grade;
    QString canceled_year;
    QString student_id;
    QString student_name;
    QString chosen_year;
    QSqlQuery query;
    QString display = "";
    if (ID == "" && NAME == "")
        query.exec("select cou.Course_ID, cou.Name, cou.Teacher_ID, tea.Name, cou.Credit, cou.Grade, cou.Canceled_Year, cho.Student_ID, stu.Name, cho.Chosen_Year from Course cou, Teacher tea, Choosing cho, Student stu where cou.Course_ID = cho.Course_ID and cou.Teacher_ID = tea.Teacher_ID and cho.Student_ID = stu.Student_ID");
    else if (ID != "" && NAME == "")
        query.exec("select cou.Course_ID, cou.Name, cou.Teacher_ID, tea.Name, cou.Credit, cou.Grade, cou.Canceled_Year, cho.Student_ID, stu.Name, cho.Chosen_Year from Course cou, Teacher tea, Choosing cho, Student stu where cou.Course_ID = cho.Course_ID and cou.Teacher_ID = tea.Teacher_ID and cho.Student_ID = stu.Student_ID and cou.Course_ID = " + QString::fromStdString(ID));
    else if (ID == "" && NAME != "")
        query.exec("select cou.Course_ID, cou.Name, cou.Teacher_ID, tea.Name, cou.Credit, cou.Grade, cou.Canceled_Year, cho.Student_ID, stu.Name, cho.Chosen_Year from Course cou, Teacher tea, Choosing cho, Student stu where cou.Course_ID = cho.Course_ID and cou.Teacher_ID = tea.Teacher_ID and cho.Student_ID = stu.Student_ID and cou.Name = '" + QString::fromStdString(NAME) + "'");
    else
        query.exec("select cou.Course_ID, cou.Name, cou.Teacher_ID, tea.Name, cou.Credit, cou.Grade, cou.Canceled_Year, cho.Student_ID, stu.Name, cho.Chosen_Year from Course cou, Teacher tea, Choosing cho, Student stu where cou.Course_ID = cho.Course_ID and cou.Teacher_ID = tea.Teacher_ID and cho.Student_ID = stu.Student_ID and cou.Course_ID = " + QString::fromStdString(ID) + " and cou.Name = '" + QString::fromStdString(NAME) + "'");

    display += "Course_ID  Name  Teacher_ID  Credit  Grade  Canceled_Year  Student_ID  Chosen_Year\n";
    while(query.next())
    {
        course_id = query.value(0).toString();
        course_name = query.value(1).toString();
        teacher_id = query.value(2).toString();
        teacher_name = query.value(3).toString();
        credit = query.value(4).toString();
        grade = query.value(5).toString();
        canceled_year = query.value(6).toString();
        student_id = query.value(7).toString();
        student_name = query.value(8).toString();
        chosen_year = query.value(9).toString();
        display += course_id+"  "+course_name+"  "+teacher_id+"  "+teacher_name+"  "+credit+"  "+grade+"  "+canceled_year+"  "+student_id+"  "+student_name+"  "+chosen_year+"\n";
    }
    ui->textBrowser->setText(display);
}


void Result_Course::on_home_clicked()
{
    this->close();
    main->show();
}
