#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>


class MainWindow : public QWidget
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QTextEdit *text_edit;
    QPushButton *open_button;
    void createInterface();
    void connectWidgets();
private slots:
    void openFile();
};

#endif // MAINWINDOW_H
