#ifndef RESULT_STUDENT_H
#define RESULT_STUDENT_H

#include <QDialog>
#include <mainwindow.h>
#include <input_student.h>

namespace Ui {
class Result_Student;
}

class Result_Student : public QDialog
{
    Q_OBJECT

public:
    explicit Result_Student(QWidget *parent = 0);
    ~Result_Student();

private slots:
    void on_home_clicked();

private:
    Ui::Result_Student *ui;
    MainWindow *main = new MainWindow();

    void sqlHelper();
    string ID;
    string NAME;
};

#endif // RESULT_STUDENT_H
