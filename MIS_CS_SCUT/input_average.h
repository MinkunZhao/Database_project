#ifndef INPUT_AVERAGE_H
#define INPUT_AVERAGE_H

#include <QDialog>
#include "mainwindow.h"
#include <string>

using namespace std;

namespace Ui {
class Input_Average;
}

class Result_Average;

class Input_Average : public QDialog
{
    Q_OBJECT

public:
    explicit Input_Average(QWidget *parent = 0);
    ~Input_Average();

    static string student_id;
    static string student_name;
    static string course_id;
    static string course_name;
    static string class_;

private slots:
    void on_home_clicked();

    void on_ok_clicked();

private:
    Ui::Input_Average *ui;
    MainWindow *main = new MainWindow();
    Result_Average *res_ave;
};

#endif // INPUT_AVERAGE_H
