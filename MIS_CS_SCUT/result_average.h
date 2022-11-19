#ifndef RESULT_AVERAGE_H
#define RESULT_AVERAGE_H

#include <QDialog>
#include "input_average.h"
#include "mainwindow.h"

namespace Ui {
class Result_Average;
}

class Result_Average : public QDialog
{
    Q_OBJECT

public:
    explicit Result_Average(QWidget *parent = 0);
    ~Result_Average();

private slots:
    void on_home_clicked();

private:
    Ui::Result_Average *ui;
    MainWindow *main = new MainWindow();

    void sqlHelper();
    string STUDENT_ID;
    string STUDENT_NAME;
    string COURSE_ID;
    string COURSE_NAME;
    string CLASS;
};

#endif // RESULT_AVERAGE_H
