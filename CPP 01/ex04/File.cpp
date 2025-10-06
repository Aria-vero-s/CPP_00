#include "File.hpp"

File::File(std::string filename, std::string s1, std::string s2) {
    setFileName(filename);
    setS1(s1);
    setS2(s2);
}
void File::setFileName(std::string newFileName) {
    fileName = newFileName;
}
void File::setS1(std::string newS1) {
    s1 = newS1;
}
void File::setS2(std::string newS2) {
    s2 = newS2;
}
void File::setFileContent(std::string newFileContent) {
    fileContent = newFileContent;
}
std::string File::getFileName() {
    return (fileName);
}
std::string File::getS1() {
    return (s1);
}
std::string File::getS2() {
    return (s2);
}
std::string File::getFileContent() {
    return (fileContent);
}
