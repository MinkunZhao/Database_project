#ifndef INPUT_TEACHER_H
#define INPUT_TEACHER_H

#include <QDialog>
#include "mainwindow.h"
#include <string>

using namespace std;

namespace Ui {
class Input_Teacher;
}

class Result_Teacher;

class Input_Teacher : public QDialog
{
    Q_OBJECT

public:
    explicit Input_Teacher(QWidget *parent = 0);
    ~Input_Teacher();

    static string id;
    static string name;

private slots:
    void on_home_clicked();

    void on_ok_clicked();

private:
    Ui::Input_Teacher *ui;
    MainWindow *main = new MainWindow();
    Result_Teacher *res_tea;
};

#endif // INPUT_TEACHER_H
