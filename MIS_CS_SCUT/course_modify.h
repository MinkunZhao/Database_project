#ifndef COURSE_MODIFY_H
#define COURSE_MODIFY_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Course_Modify;
}

class Prompt_Box;

class Course_Modify : public QDialog
{
    Q_OBJECT

public:
    explicit Course_Modify(QWidget *parent = 0);
    ~Course_Modify();

private slots:
    void on_home_clicked();

    void on_ok_clicked();

private:
    Ui::Course_Modify *ui;
    MainWindow *main = new MainWindow();
    Prompt_Box *prompt;

    void sqlHelper();
};

#endif // COURSE_MODIFY_H
