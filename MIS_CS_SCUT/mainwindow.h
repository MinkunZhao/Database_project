#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "login.h"
//#include "input_student.h"
//#include "input_score.h"
//#include "input_course.h"
//#include "input_teacher.h"
//#include "input_average.h"
//#include "modify1_administrator.h"
//#include "modify_teacher.h"

class Input_Student;
class Input_Score;
class Input_Course;
class Input_Teacher;
class Input_Average;
class Modify1_Administrator;
class Modify_Teacher;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool openDatabase();

private slots:
    void on_q_student_clicked();

    void on_q_score_clicked();

    void on_q_course_clicked();

    void on_q_teacher_clicked();

    void on_q_average_clicked();

    void on_administrator_clicked();

    void on_teacher_clicked();

private:
    Ui::MainWindow *ui;
    Input_Student *input_stu;
    Input_Score *input_sco;
    Input_Course *input_cou;
    Input_Teacher *input_tea;
    Input_Average *input_ave;
    Modify1_Administrator *modify1_adm;
    Modify_Teacher *modify_tea;

    int identity;
};

#endif // MAINWINDOW_H
