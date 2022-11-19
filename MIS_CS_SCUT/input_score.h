#ifndef INPUT_SCORE_H
#define INPUT_SCORE_H

#include <QDialog>

#include "mainwindow.h"
#include <string>

using namespace std;

namespace Ui {
class Input_Score;
}

class Result_Score;

class Input_Score : public QDialog
{
    Q_OBJECT

public:
    explicit Input_Score(QWidget *parent = 0);
    ~Input_Score();

    static string student_id;
    static string student_name;
    static string course_id;
    static string course_name;

private slots:
    void on_home_clicked();

    void on_ok_clicked();

private:
    Ui::Input_Score *ui;
    MainWindow *main = new MainWindow();
    Result_Score *res_sco;
};

#endif // INPUT_SCORE_H
