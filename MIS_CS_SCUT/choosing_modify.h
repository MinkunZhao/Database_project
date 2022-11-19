#ifndef CHOOSING_MODIFY_H
#define CHOOSING_MODIFY_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Choosing_Modify;
}

class Prompt_Box;

class Choosing_Modify : public QDialog
{
    Q_OBJECT

public:
    explicit Choosing_Modify(QWidget *parent = 0);
    ~Choosing_Modify();

private slots:
    void on_home_clicked();

    void on_ok_clicked();

private:
    Ui::Choosing_Modify *ui;
    MainWindow *main = new MainWindow();
    Prompt_Box *prompt;

    void sqlHelper();
};

#endif // CHOOSING_MODIFY_H
