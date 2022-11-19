#ifndef MODIFY1_ADMINISTRATOR_H
#define MODIFY1_ADMINISTRATOR_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Modify1_Administrator;
}

class Student_Modify;
class Student_Insert;
class Student_Delete;
class Course_Modify;
class Course_Insert;
class Course_Delete;
class Choosing_Modify;
class Choosing_Insert;
class Choosing_Delete;

class Modify1_Administrator : public QDialog
{
    Q_OBJECT

public:
    explicit Modify1_Administrator(QWidget *parent = 0);
    ~Modify1_Administrator();

    static int flag;

private slots:
    void on_home_clicked();

    void on_ok_clicked();

private:
    Ui::Modify1_Administrator *ui;
    MainWindow *main = new MainWindow();
    Student_Modify *stu_mod;
    Student_Insert *stu_ins;
    Student_Delete *stu_del;
    Course_Modify *cou_mod;
    Course_Insert *cou_ins;
    Course_Delete *cou_del;
    Choosing_Modify *cho_mod;
    Choosing_Insert *cho_ins;
    Choosing_Delete *cho_del;
};

#endif // MODIFY1_ADMINISTRATOR_H
