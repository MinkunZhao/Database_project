#ifndef COURSE_DELETE_H
#define COURSE_DELETE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Course_Delete;
}

class Prompt_Box;

class Course_Delete : public QDialog
{
    Q_OBJECT

public:
    explicit Course_Delete(QWidget *parent = 0);
    ~Course_Delete();

private slots:
    void on_home_clicked();

    void on_ok_clicked();

private:
    Ui::Course_Delete *ui;
    MainWindow *main = new MainWindow();
    Prompt_Box *prompt;

    void sqlHelper();
};

#endif // COURSE_DELETE_H
