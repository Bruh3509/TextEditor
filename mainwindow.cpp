#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menuFile->addAction("&Open", this, SLOT(setupFile()));
    ui->menuFile->addAction("&Save", this, SLOT(writeFile()));

    ui->menuTools->addAction("&Find", this, SLOT(findIn()));

    curFile = std::make_unique<FileOperations>();
}

void MainWindow::setupFile()
{
    std::unique_ptr<InputDialog> dialog = std::make_unique<InputDialog>();

    if (dialog->exec() == QDialog::Accepted) {
        curPathName = dialog->getData();
        std::string res;

        try {
            res = loadFile();
        }

        catch (std::invalid_argument &ex) {
            QMessageBox::warning(nullptr, "Error!", QString::fromLocal8Bit(ex.what()));
        }

        ui->textEdit->setText(QString::fromStdString(res));
    }
}

void MainWindow::writeFile()
{
    curFile->writeFile(ui->textEdit->toPlainText().toStdString());
}

void MainWindow::findIn()
{
    std::unique_ptr<InputDialog> diag =
        std::make_unique<InputDialog>("Enter the word to be found: ");

    if (diag->exec() == QDialog::Accepted) {
        std::string curData = ui->textEdit->toPlainText().toStdString();
        std::string fData = diag->getData();
        auto it = curData.find(fData);

        if (it != std::string::npos) {
            std::string res = curData.substr(it, it + 10);
            QMessageBox::information(nullptr, "Finding substring.",
                                     QString::fromStdString(res),
                                     QMessageBox::Ok);

        } else {
            QMessageBox::warning(nullptr, "Finding substring.",
                                     "Word didn't find",
                                     QMessageBox::Ok);
        }
    }
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
