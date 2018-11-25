#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setApplicationName("Text Editor");
    a.setApplicationVersion("0.1");
    a.setOrganizationName("tdd soft");
    a.setOrganizationDomain("github.com/tresdosdos");

    MainWindow w;
    w.show();

    return a.exec();
}
