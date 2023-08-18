#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include <QObject>
#include <QMessageBox>
#include <memory>
#include <fstream>
#include <string>
#include <exception>
#include <createnewfile.h>

class FileOperations : public QObject
{
    Q_OBJECT
public:
    FileOperations();
    FileOperations(const std::string&);
    ~FileOperations();

    std::string getData();
    void writeFile(const std::string&);

private:
    std::fstream file;
    std::string path;
};

#endif // FILEOPERATIONS_H
