#include "result_score.h"
#include "ui_result_score.h"

Result_Score::Result_Score(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result_Score)
{
    STUDENT_ID = Input_Score::student_id;
    STUDENT_NAME = Input_Score::student_name;
    COURSE_ID = Input_Score::course_id;
    COURSE_NAME = Input_Score::course_name;
    ui->setupUi(this);
    sqlHelper();
}


Result_Score::~Result_Score()
{
    delete ui;
}


void Result_Score::sqlHelper()
{
    QSqlQuery query;
    QString student_id;
    QString student_name;
    QString course_id;
    QString course_name;
    QString score;
    QString display;

    if (STUDENT_ID == "" && STUDENT_NAME == "" && COURSE_ID == "" && COURSE_NAME == "")
        query.exec("select Cho.Student_ID, Stu.Name, Cho.Course_ID, Cou.Name, Cho.Score from Student Stu, Course Cou, Choosing Cho where Stu.Student_ID = Cho.Student_ID and Cou.Course_ID = Cho.Course_ID");
    else if (STUDENT_ID != "" && STUDENT_NAME == "" && COURSE_ID == "" && COURSE_NAME == "")
        query.exec("select Cho.Student_ID, Stu.Name, Cho.Course_ID, Cou.Name, Cho.Score from Student Stu, Course Cou, Choosing Cho where Stu.Student_ID = Cho.Student_ID and Cou.Course_ID = Cho.Course_ID and Stu.Student_ID = " + QString::fromStdString(STUDENT_ID));
    else if (STUDENT_ID == "" && STUDENT_NAME != "" && COURSE_ID == "" && COURSE_NAME == "")
        query.exec("select Cho.Student_ID, Stu.Name, Cho.Course_ID, Cou.Name, Cho.Score from Student Stu, Course Cou, Choosing Cho where Stu.Student_ID = Cho.Student_ID and Cou.Course_ID = Cho.Course_ID and Stu.Name = '" + QString::fromStdString(STUDENT_NAME) + "'");
    else if (STUDENT_ID == "" && STUDENT_NAME == "" && COURSE_ID != "" && COURSE_NAME == "")
        query.exec("select Cho.Student_ID, Stu.Name, Cho.Course_ID, Cou.Name, Cho.Score from Student Stu, Course Cou, Choosing Cho where Stu.Student_ID = Cho.Student_ID and Cou.Course_ID = Cho.Course_ID and Cou.Course_ID = " + QString::fromStdString(COURSE_ID));
    else if (STUDENT_ID == "" && STUDENT_NAME == "" && COURSE_ID == "" && COURSE_NAME != "")
        query.exec("select Cho.Student_ID, Stu.Name, Cho.Course_ID, Cou.Name, Cho.Score from Student Stu, Course Cou, Choosing Cho where Stu.Student_ID = Cho.Student_ID and Cou.Course_ID = Cho.Course_ID and Cou.Name = '" + QString::fromStdString(COURSE_NAME) + "'");
    else if (STUDENT_ID != "" && STUDENT_NAME != "" && COURSE_ID == "" && COURSE_NAME == "")
        query.exec("select Cho.Student_ID, Stu.Name, Cho.Course_ID, Cou.Name, Cho.Score from Student Stu, Course Cou, Choosing Cho where Stu.Student_ID = Cho.Student_ID and Cou.Course_ID = Cho.Course_ID and Stu.Student_ID = " + QString::fromStdString(STUDENT_ID) + " and Stu.Name = '" + QString::fromStdString(STUDENT_NAME) + "'");
    else if (STUDENT_ID != "" && STUDENT_NAME == "" && COURSE_ID != "" && COURSE_NAME == "")
        query.exec("select Cho.Student_ID, Stu.Name, Cho.Course_ID, Cou.Name, Cho.Score from Student Stu, Course Cou, Choosing Cho where Stu.Student_ID = Cho.Student_ID and Cou.Course_ID = Cho.Course_ID and Stu.Student_ID = " + QString::fromStdString(STUDENT_ID) + " and Cou.Course_ID = " + QString::fromStdString(COURSE_ID));
    else if (STUDENT_ID != "" && STUDENT_NAME == "" && COURSE_ID == "" && COURSE_NAME != "")
        query.exec("select Cho.Student_ID, Stu.Name, Cho.Course_ID, Cou.Name, Cho.Score from Student Stu, Course Cou, Choosing Cho where Stu.Student_ID = Cho.Student_ID and Cou.Course_ID = Cho.Course_ID and Stu.Student_ID = " + QString::fromStdString(STUDENT_ID) + " and Cou.Name = '" + QString::fromStdString(COURSE_NAME) + "'");
    else if (STUDENT_ID == "" && STUDENT_NAME != "" && COURSE_ID != "" && COURSE_NAME == "")
        query.exec("select Cho.Student_ID, Stu.Name, Cho.Course_ID, Cou.Name, Cho.Score from Student Stu, Course Cou, Choosing Cho where Stu.Student_ID = Cho.Student_ID and Cou.Course_ID = Cho.Course_ID and Stu.Name = '" + QString::fromStdString(STUDENT_NAME) + "' and Cou.Course_ID = " + QString::fromStdString(COURSE_ID));
    else if (STUDENT_ID == "" && STUDENT_NAME != "" && COURSE_ID == "" && COURSE_NAME != "")
        query.exec("select Cho.Student_ID, Stu.Name, Cho.Course_ID, Cou.Name, Cho.Score from Student Stu, Course Cou, Choosing Cho where Stu.Student_ID = Cho.Student_ID and Cou.Course_ID = Cho.Course_ID and Stu.Name = '" + QString::fromStdString(STUDENT_NAME) + "' and Cou.Name = '" + QString::fromStdString(COURSE_NAME) + "'");
    else if (STUDENT_ID == "" && STUDENT_NAME == "" && COURSE_ID != "" && COURSE_NAME != "")
        query.exec("select Cho.Student_ID, Stu.Name, Cho.Course_ID, Cou.Name, Cho.Score from Student Stu, Course Cou, Choosing Cho where Stu.Student_ID = Cho.Student_ID and Cou.Course_ID = Cho.Course_ID and Cou.Course_ID = " + QString::fromStdString(COURSE_ID) + " and Cou.Name = '" + QString::fromStdString(COURSE_NAME) + "'");
    else if (STUDENT_ID != "" && STUDENT_NAME != "" && COURSE_ID != "" && COURSE_NAME == "")
        query.exec("select Cho.Student_ID, Stu.Name, Cho.Course_ID, Cou.Name, Cho.Score from Student Stu, Course Cou, Choosing Cho where Stu.Student_ID = Cho.Student_ID and Cou.Course_ID = Cho.Course_ID and Stu.Student_ID = " + QString::fromStdString(STUDENT_ID) + " and Stu.Name = '" + QString::fromStdString(STUDENT_NAME) + "' and Cou.Course_ID = " + QString::fromStdString(COURSE_ID));
    else if (STUDENT_ID != "" && STUDENT_NAME != "" && COURSE_ID == "" && COURSE_NAME != "")
        query.exec("select Cho.Student_ID, Stu.Name, Cho.Course_ID, Cou.Name, Cho.Score from Student Stu, Course Cou, Choosing Cho where Stu.Student_ID = Cho.Student_ID and Cou.Course_ID = Cho.Course_ID and Stu.Student_ID = " + QString::fromStdString(STUDENT_ID) + " and Stu.Name = '" + QString::fromStdString(STUDENT_NAME) + "' and Cou.Name = '" + QString::fromStdString(COURSE_NAME) + "'");
    else if (STUDENT_ID != "" && STUDENT_NAME == "" && COURSE_ID != "" && COURSE_NAME != "")
        query.exec("select Cho.Student_ID, Stu.Name, Cho.Course_ID, Cou.Name, Cho.Score from Student Stu, Course Cou, Choosing Cho where Stu.Student_ID = Cho.Student_ID and Cou.Course_ID = Cho.Course_ID and Stu.Student_ID = " + QString::fromStdString(STUDENT_ID) + " and Cou.Course_ID = " + QString::fromStdString(COURSE_ID) + " and Cou.Name = '" + QString::fromStdString(COURSE_NAME) + "'");
    else if (STUDENT_ID == "" && STUDENT_NAME != "" && COURSE_ID != "" && COURSE_NAME != "")
        query.exec("select Cho.Student_ID, Stu.Name, Cho.Course_ID, Cou.Name, Cho.Score from Student Stu, Course Cou, Choosing Cho where Stu.Student_ID = Cho.Student_ID and Cou.Course_ID = Cho.Course_ID and Stu.Name = '" + QString::fromStdString(STUDENT_NAME) + "' and Cou.Course_ID = " + QString::fromStdString(COURSE_ID) + " and Cou.Name = '" + QString::fromStdString(COURSE_NAME) + "'");
    else
        query.exec("select Cho.Student_ID, Stu.Name, Cho.Course_ID, Cou.Name, Cho.Score from Student Stu, Course Cou, Choosing Cho where Stu.Student_ID = Cho.Student_ID and Cou.Course_ID = Cho.Course_ID and Stu.Student_ID = " + QString::fromStdString(STUDENT_ID) + " and Stu.Name = '" + QString::fromStdString(STUDENT_NAME) + "' and Cou.Course_ID = " + QString::fromStdString(COURSE_ID) + " and Cou.Name = '" + QString::fromStdString(COURSE_NAME) + "'");

    display += "Student_ID  Student_Name  Course_ID  Course_Name  Score\n";
    while(query.next())
    {
        student_id = query.value(0).toString();
        student_name = query.value(1).toString();
        course_id = query.value(2).toString();
        course_name = query.value(3).toString();
        score = query.value(4).toString();
        display += student_id+"  "+student_name+"  "+course_id+"  "+course_name+"  "+score+"  "+"\n";
    }
    ui->textBrowser->setText(display);
}


void Result_Score::on_home_clicked()
{
    this->close();
    main->show();
}
