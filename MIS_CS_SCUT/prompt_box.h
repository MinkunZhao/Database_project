#ifndef PROMPT_BOX_H
#define PROMPT_BOX_H

#include <QDialog>
#include "mainwindow.h"
#include "modify1_administrator.h"
#include "modify_teacher.h"

namespace Ui {
class Prompt_Box;
}

class Prompt_Box : public QDialog
{
    Q_OBJECT

public:
    explicit Prompt_Box(QWidget *parent = 0);
    ~Prompt_Box();

private slots:
    void on_home_clicked();

private:
    Ui::Prompt_Box *ui;
    MainWindow *main = new MainWindow();

    void promptHelper();

    int flag1;
    /* 0: student modify success
     * 1: student modify fail
     * 2: student insert success
     * 3: student insert fail
     * 4: student delete success
     * 5: student delete fail
     * 6: course modify success
     * 7: course modify fail
     * 8: course insert success
     * 9: course insert fail
     * 10: course delete success
     * 11: course delete fail
     * 12: choosing modify success
     * 13: choosing modify insert
     * 14: choosing insert success
     * 15: choosing insert fail
     * 16: choosing delete success
     * 17: choosing delete fail*/
    int flag2;
    // 0: set score success; 1: set score fail
};

#endif // PROMPT_BOX_H
