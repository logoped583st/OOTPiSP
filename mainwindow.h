#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public: enum functionEnum {sin, cos, tg};

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setTable();

    void calculate(int func);

    QTableWidgetItem* calculateItem(int func,double position);

private slots:
    void on_cos_clicked();

    void on_sin_clicked();

    void on_tg_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
