#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCloseEvent>
#include <QCoreApplication>
#include <QDir>
#include <QFileDialog>
#include <QFontDialog>
#include <QMessageBox>
#include <QtDebug>
#include <QTextStream>


using namespace std;

MainWindow::MainWindow(const QString &fileName, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionRedo->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    QAction::connect(ui->textEdit, SIGNAL(redoAvailable(bool)), ui->actionRedo, SLOT(setEnabled(bool)));
    QAction::connect(ui->textEdit, SIGNAL(undoAvailable(bool)), ui->actionUndo, SLOT(setEnabled(bool)));
    QAction::connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCopy, SLOT(setEnabled(bool)));
    QAction::connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCut, SLOT(setEnabled(bool)));

    QAction::connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    QAction::connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(saveFileAs()));

    //ui->textEdit->setStyleSheet("QTextEdit { background: rgb(0, 0, 0); selection-background-color: rgb(255, 255, 255); }");
    ui->textEdit->setFont(this->settings.value("viewFont").toString());
    this->setWindowIcon(QIcon(":/icons/new"));
    this->setWindowTitle("TextEditor" + tr("[*]"));
    QObject::connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(documentModified()));
    loadFile(fileName);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    MainWindow * te = new MainWindow();
    te->show();
}

void MainWindow::on_actionClose_triggered()
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->close();
}

void MainWindow::on_actionExit_triggered()
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    qApp->closeAllWindows();
}

void MainWindow::documentModified()
{
    this->setWindowModified(true);
}


void MainWindow::closeEvent(QCloseEvent *event) {
    if (this->isWindowModified() == true) {
        QMessageBox mb;
        mb.setText("The document has been modified, do you want to save it? You will lose all unsaved changes");
        mb.setStandardButtons(QMessageBox::Ok | QMessageBox::No | QMessageBox::Cancel);
        mb.setDefaultButton(QMessageBox::Cancel);
        int ret = mb.exec();
        switch (ret) {
          case QMessageBox::Cancel:
             event->ignore();
             break;
          case QMessageBox::No:
             this->setWindowModified(false);
             event->accept();
             break;
          case QMessageBox::Ok:
            saveFile();
            event->accept();
            break;
          default:
             this->setWindowModified(false);
             event->ignore();
             break;
        }
    } else {
        event->accept();
    }
}

void MainWindow::on_actionSelectFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok);
    QSettings settings(QCoreApplication::applicationDirPath() + QDir::separator()+"settings.ini",QSettings::IniFormat);
    if(ok){
        settings.setValue("viewFont",font);
        qDebug() << font.family();
      //  this->settings.setValue("viewFont", QFontDialog::getFont(0, QApplication::font()));
        ui->textEdit->setFont(font);
    }

}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox mb;
    mb.setText("Разработал Станислав Бушук");
    mb.exec();
}

void MainWindow::on_actionAboutQt_triggered()
{
    qApp->aboutQt();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::loadFile(const QString &fileName)
{
    if (fileName.isEmpty()) {
        setFileName(QString());
        return;
    }

    QFile file(fileName);
    file.open(QIODevice::ReadWrite | QIODevice::Text);

    if (!file.isOpen()) {
        QMessageBox mb;
        mb.setText("File can't be opened");
        mb.exec();

        setFileName(QString());
        return;
    }

    QTextStream ts(&file);
    QString text = ts.readAll();
    ui->textEdit->setText(text);
    file.close();
    setFileName(fileName);
    this->setWindowModified(false);
}

void MainWindow::setFileName(const QString &a) {
    this->m_fileName = a;
    this->setWindowTitle(QString("%1[*] - %2")
                         .arg(m_fileName.isNull() ? "untitled": QFileInfo(m_fileName).fileName())
                         .arg(QApplication::applicationName()));
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName();

    if (fileName.isNull()) {
        return;
    }

    if (!this->isWindowModified() && this->m_fileName.isNull()) {
        loadFile(fileName);
    } else {
        MainWindow * mw = new MainWindow(fileName);
        mw->show();
    }
}

bool MainWindow::saveFileAs() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save document",
       m_fileName.isNull()?QDir::currentPath():m_fileName, "Text documents (*.txt)");

    if (fileName.isNull()) {
        return false;
    }

    setFileName(fileName);
    return saveFile();
}

bool MainWindow::saveFile() {
    if (this->m_fileName.isNull()) {
        return saveFileAs();
    }

    QFile file(this->m_fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    if (!file.isOpen()) {
        QMessageBox mb;
        mb.setText("File can't be opened");
        mb.exec();

        setFileName(QString());
        return false;
    }

    QTextStream ts(&file);
    ts << ui->textEdit->toPlainText();
    file.close();
    this->setWindowModified(false);

    return true;
}

