#ifndef COURSE_INSERT_H
#define COURSE_INSERT_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Course_Insert;
}

class Prompt_Box;

class Course_Insert : public QDialog
{
    Q_OBJECT

public:
    explicit Course_Insert(QWidget *parent = 0);
    ~Course_Insert();

private slots:
    void on_home_clicked();

    void on_ok_clicked();

private:
    Ui::Course_Insert *ui;
    MainWindow *main = new MainWindow();
    Prompt_Box *prompt;

    void sqlHelper();
};

#endif // COURSE_INSERT_H
