#include "fileoperations.h"

FileOperations::FileOperations()
{}

FileOperations::FileOperations(const std::string &path)
{
    file.open(path, std::ios::out | std::ios::in | std::ios::app);
}

FileOperations::~FileOperations()
{
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
    return res;
}

void FileOperations::writeFile(const std::string &res)
{
    if (file.is_open())
        file << res;
    else {
        std::unique_ptr<CreateNewFile> diag = std::make_unique<CreateNewFile>();

        if (diag->exec() == QDialog::Accepted) {
            file.open(diag->getFileName(), std::ios::out);
            file << res;
        }
    }
}
