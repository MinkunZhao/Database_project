#ifndef CHOOSING_DELETE_H
#define CHOOSING_DELETE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Choosing_Delete;
}

class Prompt_Box;

class Choosing_Delete : public QDialog
{
    Q_OBJECT

public:
    explicit Choosing_Delete(QWidget *parent = 0);
    ~Choosing_Delete();

private slots:
    void on_home_clicked();

    void on_ok_clicked();

private:
    Ui::Choosing_Delete *ui;
    MainWindow *main = new MainWindow();
    Prompt_Box *prompt;

    void sqlHelper();
};

#endif // CHOOSING_DELETE_H
