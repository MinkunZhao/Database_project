#ifndef STUDENT_INSERT_H
#define STUDENT_INSERT_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Student_Insert;
}

class Prompt_Box;

class Student_Insert : public QDialog
{
    Q_OBJECT

public:
    explicit Student_Insert(QWidget *parent = 0);
    ~Student_Insert();

private slots:
    void on_home_clicked();

    void on_ok_clicked();

private:
    Ui::Student_Insert *ui;
    MainWindow *main = new MainWindow();
    Prompt_Box *prompt;

    void sqlHelper();
};

#endif // STUDENT_INSERT_H
