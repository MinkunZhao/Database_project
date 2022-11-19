#ifndef RESULT_COURSE_H
#define RESULT_COURSE_H

#include <QDialog>
#include "mainwindow.h"
#include "input_course.h"

namespace Ui {
class Result_Course;
}

class Result_Course : public QDialog
{
    Q_OBJECT

public:
    explicit Result_Course(QWidget *parent = 0);
    ~Result_Course();

private slots:
    void on_home_clicked();

private:
    Ui::Result_Course *ui;
    MainWindow *main = new MainWindow();

    void sqlHelper();
    string ID;
    string NAME;
};

#endif // RESULT_COURSE_H
