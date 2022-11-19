#ifndef INPUT_COURSE_H
#define INPUT_COURSE_H

#include <QDialog>
#include "mainwindow.h"
#include <string>

using namespace std;

namespace Ui {
class Input_Course;
}

class Result_Course;

class Input_Course : public QDialog
{
    Q_OBJECT

public:
    explicit Input_Course(QWidget *parent = 0);
    ~Input_Course();

    static string id;
    static string name;

private slots:
    void on_home_clicked();

    void on_ok_clicked();

private:
    Ui::Input_Course *ui;
    MainWindow *main = new MainWindow();
    Result_Course *res_cou;
};

#endif // INPUT_COURSE_H
