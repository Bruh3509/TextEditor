#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menuFile->addAction("&Open", this, SLOT(setupFile()));
    ui->menuFile->addAction("&Save", this, SLOT(writeFile()));

    curFile = std::make_unique<FileOperations>();
}

void MainWindow::setupFile()
{
    std::unique_ptr<InputDialog> dialog = std::make_unique<InputDialog>();

    if (dialog->exec() == QDialog::Accepted) {
        curPathName = dialog->getPath();
        std::string res;

        try {
            res = loadFile();
        }

        catch (std::invalid_argument &ex) {
            QMessageBox::warning(0, "Error!",QString::fromLocal8Bit(ex.what()));
        }

        ui->textEdit->setText(QString::fromStdString(res));
    }
}

void MainWindow::writeFile()
{
    curFile->writeFile(ui->textEdit->toPlainText().toStdString());
}

std::string MainWindow::loadFile()
{
    curFile = std::make_unique<FileOperations>(curPathName);
    std::string res;

    try {
        res = curFile->getData();
    }
    catch(...) {
        std::rethrow_exception(std::current_exception());
    }

    return res;
}

MainWindow::~MainWindow()
{
    std::unique_ptr<QMessageBox> msgBox = std::make_unique<QMessageBox>(QMessageBox::Information, "Exit.", "Do you want to save closing file?", QMessageBox::Yes | QMessageBox::No);

    if (msgBox->exec() == QMessageBox::Yes)
        writeFile();
    delete ui;
}
