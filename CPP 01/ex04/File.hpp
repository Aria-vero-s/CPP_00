#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
#include <fstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"

class File {
    private:
        std::string fileName;
        std::string s1;
        std::string s2;
        std::string fileContent;
    public:
        File(std::string filename, std::string s1, std::string s2);
        void setFileName(std::string newFileName);
        void setS1(std::string newS1);
        void setS2(std::string newS2);
        void setFileContent(std::string newFileContent);
        std::string getFileName();
        std::string getS1();
        std::string getS2();
        std::string getFileContent();
};

void replaceS1WithS2(File &obj);
void    setNewFileName(File &obj);
bool    createNewFile(File &obj);
bool openFilename(File &obj);

#endif