#include "createnewfile.h"

CreateNewFile::CreateNewFile(QWidget *parent) : QDialog(parent)
{
    fileName = new QLineEdit();

    QLabel *label = new QLabel("Enter filename: ");

    QPushButton *btn = new QPushButton("&Ok");

    QObject::connect(btn, SIGNAL(clicked()), this, SLOT(accept()));

    QVBoxLayout *vBox = new QVBoxLayout;
    vBox->addWidget(label);
    vBox->addWidget(fileName);
    vBox->addWidget(btn);
    setLayout(vBox);
}

std::string CreateNewFile::getFileName() const
{
    return fileName->text().toStdString();
}
