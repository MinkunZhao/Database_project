#ifndef STUDENT_DELETE_H
#define STUDENT_DELETE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Student_Delete;
}

class Prompt_Box;

class Student_Delete : public QDialog
{
    Q_OBJECT

public:
    explicit Student_Delete(QWidget *parent = 0);
    ~Student_Delete();

private slots:
    void on_home_clicked();

    void on_ok_clicked();

private:
    Ui::Student_Delete *ui;
    MainWindow *main = new MainWindow();
    Prompt_Box *prompt;

    void sqlHelper();
};

#endif // STUDENT_DELETE_H
