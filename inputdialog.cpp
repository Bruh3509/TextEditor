#include "inputdialog.h"

InputDialog::InputDialog(QWidget *parent) : QDialog(parent)
{
    // Widgets.
    pathName = new QLineEdit();

    QLabel *pathL = new QLabel("&Enter file path: ");
    pathL->setBuddy(pathName);

    QPushButton *okBtn = new QPushButton("&Ok");
    QPushButton *cnlBtn = new QPushButton("&Cancel");

    QObject::connect(okBtn, SIGNAL(clicked()), this, SLOT(accept()));
    QObject::connect(cnlBtn, SIGNAL(clicked()), this, SLOT(reject()));

    // Layout.
    QVBoxLayout *vBox = new QVBoxLayout;
    QHBoxLayout *hBox = new QHBoxLayout;

    hBox->addWidget(okBtn);
    hBox->addWidget(cnlBtn);
    hBox->setSpacing(3);

    vBox->addWidget(pathL);
    vBox->addWidget(pathName);
    vBox->addLayout(hBox);

    vBox->setSpacing(3);
    setLayout(vBox);
}

std::string InputDialog::getPath() const
{
    return pathName->text().toStdString();
}
