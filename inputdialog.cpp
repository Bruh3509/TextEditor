#include "inputdialog.h"

InputDialog::InputDialog(QWidget *parent) : QDialog(parent)
{
    // Widgets.
    data = new QLineEdit();

    QLabel *pathL = new QLabel("&Enter file path: ");
    pathL->setBuddy(data);

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
    vBox->addWidget(data);
    vBox->addLayout(hBox);

    vBox->setSpacing(3);
    setLayout(vBox);
}

InputDialog::InputDialog(const std::string &label, QWidget *parent) : QDialog(parent)
{
    // Widgets.
    data = new QLineEdit();

    QLabel *dataL = new QLabel("&" + QString::fromStdString(label));
    dataL->setBuddy(data);

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

    vBox->addWidget(dataL);
    vBox->addWidget(data);
    vBox->addLayout(hBox);

    vBox->setSpacing(3);
    setLayout(vBox);
}

std::string InputDialog::getData() const
{
    return data->text().toStdString();
}
