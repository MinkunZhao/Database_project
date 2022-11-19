#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "input_student.h"
#include "input_score.h"
#include "input_course.h"
#include "input_teacher.h"
#include "input_average.h"
#include "modify1_administrator.h"
#include "modify_teacher.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    openDatabase();
    identity = Login::identity;
    if (identity == 0)  // teacher
        ui->administrator->hide();
    else if (identity == 2) // administrator
        ui->teacher->hide();
    else    // student
    {
        ui->administrator->hide();
        ui->teacher->hide();
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::openDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
    qDebug()<<"ODBC driver?"<<db.isValid();
    QString dsn = QString::fromLocal8Bit("hw2_db");//数据源名称，就是刚才的名称
    db.setHostName("localhost");                        //选择本地主机，127.0.1.1
    db.setDatabaseName(dsn);                            //设置数据源名称
    db.setUserName("LAPTOP-HSSUC05V\ZMK2002");                               //登录用户
    db.setPassword("");                              //密码
    if(!db.open())                                      //打开数据库
    {
       qDebug()<<db.lastError().text();
       return false;
    }
    else
    {
        qDebug()<<"database open success!";
        return true;
    }
}


void MainWindow::on_q_student_clicked()
{
    this->close();
    input_stu = new Input_Student();
    input_stu->show();
}

void MainWindow::on_q_score_clicked()
{
    this->close();
    input_sco = new Input_Score();
    input_sco->show();
}


void MainWindow::on_q_course_clicked()
{
    this->close();
    input_cou = new Input_Course();
    input_cou->show();
}


void MainWindow::on_q_teacher_clicked()
{
    this->close();
    input_tea = new Input_Teacher();
    input_tea->show();
}


void MainWindow::on_q_average_clicked()
{
    this->close();
    input_ave = new Input_Average();
    input_ave->show();
}


void MainWindow::on_administrator_clicked()
{
    this->close();
    modify1_adm = new Modify1_Administrator();
    modify1_adm->show();
}


void MainWindow::on_teacher_clicked()
{
    this->close();
    modify_tea = new Modify_Teacher();
    modify_tea->show();
}
