#ifndef CHOOSING_INSERT_H
#define CHOOSING_INSERT_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Choosing_Insert;
}

class Prompt_Box;

class Choosing_Insert : public QDialog
{
    Q_OBJECT

public:
    explicit Choosing_Insert(QWidget *parent = 0);
    ~Choosing_Insert();

private slots:
    void on_home_clicked();

    void on_ok_clicked();

private:
    Ui::Choosing_Insert *ui;
    MainWindow *main = new MainWindow();
    Prompt_Box *prompt;

    void sqlHelper();
};

#endif // CHOOSING_INSERT_H
