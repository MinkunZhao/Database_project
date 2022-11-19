#ifndef STUDENT_MODIFY_H
#define STUDENT_MODIFY_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Student_Modify;
}

class Prompt_Box;

class Student_Modify : public QDialog
{
    Q_OBJECT

public:
    explicit Student_Modify(QWidget *parent = 0);
    ~Student_Modify();

private slots:
    void on_home_clicked();

    void on_ok_clicked();

private:
    Ui::Student_Modify *ui;
    MainWindow *main = new MainWindow();
    Prompt_Box *prompt;

    void sqlHelper();
};

#endif // STUDENT_MODIFY_H
