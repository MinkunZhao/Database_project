#ifndef INPUT_STUDENT_H
#define INPUT_STUDENT_H

#include <QDialog>
#include <string>
#include "mainwindow.h"

using namespace std;

namespace Ui {
class Input_Student;
}

class Result_Student;

class Input_Student : public QDialog
{
    Q_OBJECT

public:
    explicit Input_Student(QWidget *parent = 0);
    ~Input_Student();

    static string id;
    static string name;

private slots:
    void on_home_clicked();

    void on_ok_clicked();

private:
    Ui::Input_Student *ui;
    Result_Student *res_stu;
    MainWindow *main = new MainWindow();
};

#endif // INPUT_STUDENT_H
