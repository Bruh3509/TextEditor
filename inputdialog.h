#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QLayout>

class InputDialog : public QDialog
{
public:
    InputDialog(QWidget *parent = 0);
    std::string getPath() const;
private:
    QLineEdit *pathName;
};

#endif // INPUTDIALOG_H
