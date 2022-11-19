#ifndef MODIFY_TEACHER_H
#define MODIFY_TEACHER_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Modify_Teacher;
}

class Prompt_Box;

class Modify_Teacher : public QDialog
{
    Q_OBJECT

public:
    explicit Modify_Teacher(QWidget *parent = 0);
    ~Modify_Teacher();

    static int flag;

private slots:
    void on_home_clicked();

    void on_ok_clicked();

private:
    Ui::Modify_Teacher *ui;
    MainWindow *main = new MainWindow();
    Prompt_Box *prompt;

    void sqlHelper();
};

#endif // MODIFY_TEACHER_H
