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
    InputDialog(QWidget *parent = nullptr);
    InputDialog(const std::string&, QWidget *parent = nullptr);
    std::string getData() const;
private:
    QLineEdit *data;
};

#endif // INPUTDIALOG_H
