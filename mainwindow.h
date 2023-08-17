#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QDebug>
#include <memory>
#include <inputdialog.h>
#include <fileoperations.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::string curPathName;
    std::unique_ptr<FileOperations> curFile;
    std::string loadFile();

private slots:
    void setupFile();
    void writeFile();
};
#endif // MAINWINDOW_H
