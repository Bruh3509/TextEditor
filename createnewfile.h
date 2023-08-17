#ifndef CREATENEWFILE_H
#define CREATENEWFILE_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QLayout>

class CreateNewFile : public QDialog
{
public:
    CreateNewFile(QWidget *parent = nullptr);
    std::string getFileName() const;
private:
    QLineEdit *fileName;
};

#endif // CREATENEWFILE_H
