#ifndef RESULT_SCORE_H
#define RESULT_SCORE_H

#include <QDialog>
#include "input_score.h"
#include "mainwindow.h"

namespace Ui {
class Result_Score;
}

class Result_Score : public QDialog
{
    Q_OBJECT

public:
    explicit Result_Score(QWidget *parent = 0);
    ~Result_Score();

private slots:
    void on_home_clicked();

private:
    Ui::Result_Score *ui;
    MainWindow *main = new MainWindow();

    void sqlHelper();
    string STUDENT_ID;
    string STUDENT_NAME;
    string COURSE_ID;
    string COURSE_NAME;
};

#endif // RESULT_SCORE_H
