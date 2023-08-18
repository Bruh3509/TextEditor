#include "fileoperations.h"

FileOperations::FileOperations() : path()
{}

FileOperations::FileOperations(const std::string &path) : path(path)
{
    file.open(path, std::ios::in);
}

FileOperations::~FileOperations()
{
    file.flush();
    file.close();
}

std::string FileOperations::getData()
{
    if (!file.is_open())
        throw std::invalid_argument("File didn't open");

    std::string res;
    std::string buf;
    while(std::getline(file, buf))
        res += buf;

    file.close();
    return res;
}

void FileOperations::writeFile(const std::string &res)
{
    if (path != "") {
        file.open(path, std::ios::out);
        file << res;
    }
    else {
        std::unique_ptr<CreateNewFile> diag = std::make_unique<CreateNewFile>();

        if (diag->exec() == QDialog::Accepted) {
            file.open(diag->getFileName(), std::ios::out);
            file << res;
        }
    }
}
