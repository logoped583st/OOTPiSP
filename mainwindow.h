#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(const QString &fileName=QString(), QWidget *parent = 0);
    ~MainWindow();

private:
    QSettings settings;
    QString m_fileName;

private slots:
    void on_actionNew_triggered();

    void on_actionClose_triggered();

    void on_actionExit_triggered();

    void documentModified();

    void on_actionSelectFont_triggered();

    void on_actionAbout_triggered();

    void on_actionAboutQt_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionOpen_triggered();

    bool saveFile();

    bool saveFileAs();

protected slots:
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    void loadFile(const QString &fileName);
    void setFileName(const QString &);
};

#endif // MAINWINDOW_H
