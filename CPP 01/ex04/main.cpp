#include <iostream>
#include <string>
#include <fstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

class File {
    private:
        std::string content;
    public:
        File() {}
        void setContent(std::string c) {
            content = c;
        }
        std::string getContent() {
            return (content);
        }
};

void    exportNewFile() {
    std::cout << "test" << std::endl;
}

void    replaceString(File &obj, const std::string &s1, const std::string &s2) {
    std::string extracter;
    std::string result;
    size_t finder;
    std::string c;
    std::string line;
    std::string result;
    size_t start;
    int i = 0;

    c = obj.getContent();
    finder = c.find(s1);
    while (true) {
        if (c[i]) {
            extracter = c.substr(finder, s1.length());
            result = result + c.substr(start, finder);
        }
        else
            break ;
        i++;
    }
}

bool openFilename(File &obj, const std::string &filename, const std::string &s1, const std::string &s2) {
    std::ifstream input(filename);
    std::string allContent;
    std::string line;
    
    if (!input.is_open())
        return(false);
    else {
        while(std::getline(input, line)) {
            allContent = allContent + line + "\n";
            obj.setContent(allContent);
        }
    }
    return (true);
}

int main(int argc, char **argv) {
    File obj;

    if (argc != 4) {
        std::cerr << RED << "Error: arguments must be [exec] [filename] [s1] [s2]." << RESET << std::endl;
        return (1);
    }
    if (!openFilename(obj, argv[1], argv[2], argv[3])) {
        std::cerr << RED << "Error: must be an existing file." << RESET << std::endl;
        return (1);
    }
    replaceString(obj, argv[2], argv[3]);
    exportNewFile();
    return (0);
}