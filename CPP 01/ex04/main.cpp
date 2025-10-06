#include "File.hpp"

// #include <string>
// #include <fstream>
// #include <iostream>

// #define RESET   "\033[0m"
// #define RED     "\033[31m"
// #define MAGENTA "\033[35m"
// #define CYAN    "\033[36m"
// #define BOLD    "\033[1m"

// class File {
//     private:
//         std::string fileName;
//         std::string s1;
//         std::string s2;
//         std::string fileContent;
//     public:
//         File(std::string filename, std::string s1, std::string s2) {
//             setFileName(filename);
//             setS1(s1);
//             setS2(s2);
//         }
//         void setFileName(std::string newFileName) {
//             fileName = newFileName;
//         }
//         void setS1(std::string newS1) {
//             s1 = newS1;
//         }
//         void setS2(std::string newS2) {
//             s2 = newS2;
//         }
//         void setFileContent(std::string newFileContent) {
//             fileContent = newFileContent;
//         }
//         std::string getFileName() {
//             return (fileName);
//         }
//         std::string getS1() {
//             return (s1);
//         }
//         std::string getS2() {
//             return (s2);
//         }
//         std::string getFileContent() {
//             return (fileContent);
//         }
// };

void replaceS1WithS2(File &obj) {
    std::string fileContent = obj.getFileContent();
    std::string s1 = obj.getS1();
    std::string s2 = obj.getS2();
    std::string newContent;
    std::string extracted;
    size_t extractionLength;
    size_t pos;
    size_t start;
    
    pos = 0;
    start = 0;
    while((pos = fileContent.find(s1, start)) != std::string::npos) {
        extractionLength = pos - start;
        extracted = fileContent.substr(start, extractionLength);
        newContent = newContent + extracted + s2;
        start = pos + s1.length();
    }
    extracted = fileContent.substr(start, fileContent.length());
    newContent = newContent + extracted;
    obj.setFileContent(newContent);
    return ;
}

void    setNewFileName(File &obj) {
    int i = 0;
    std::string line;
    std::string FileNameWithoutExt;
    while (obj.getFileName()[i] != '.') {
        FileNameWithoutExt = FileNameWithoutExt + obj.getFileName()[i];
        i++;
    }
    obj.setFileName(FileNameWithoutExt + ".replace");
    return ;
}

bool    createNewFile(File &obj) {
    if((obj.getFileContent().find(obj.getS1(), 0)) == std::string::npos) {
        std::cout << RED << "Error: non-existing [s1] in designated file." << RESET << std::endl;
        return false;
    }
    std::ofstream newFile(obj.getFileName().c_str());
    replaceS1WithS2(obj);
    if (!newFile.is_open())
        return(false);
    else {
        newFile << obj.getFileContent();
        newFile.close();
    }
    return (true);
}

bool openFilename(File &obj) {
    std::ifstream file(obj.getFileName().c_str());
    std::string allContent;
    std::string line;
    
    if (!file.is_open())
        return(false);
    else {
        while(std::getline(file, line))
            allContent = allContent + line + "\n";
        obj.setFileContent(allContent);
    }
    return (true);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << RED << "Error: arguments must be [exec] [filename] [s1] [s2]." << RESET << std::endl;
        return (1);
    }
    File obj(argv[1], argv[2], argv[3]);
    if (!openFilename(obj)) {
        std::cerr << RED << "Error: must be an existing file." << RESET << std::endl;
        return (1);
    }
    setNewFileName(obj);
    createNewFile(obj);
    return (0);
}