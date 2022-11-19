#ifndef RESULT_TEACHER_H
#define RESULT_TEACHER_H

#include <QDialog>
#include "mainwindow.h"
#include "input_teacher.h"

namespace Ui {
class Result_Teacher;
}

class Result_Teacher : public QDialog
{
    Q_OBJECT

public:
    explicit Result_Teacher(QWidget *parent = 0);
    ~Result_Teacher();

private slots:
    void on_home_clicked();

private:
    Ui::Result_Teacher *ui;
    MainWindow *main = new MainWindow();

    void sqlHelper();
    string ID;
    string NAME;
};

#endif // RESULT_TEACHER_H
