#include <iostream>
#include <fstream>

int main() {
    // create a small text file with non-numeric content
    std::ofstream("text.txt") << "hello\n";

    std::ifstream f("text.txt");
    std::cout << "After open: is_open() = " << f.is_open()
              << ", bool(f) = " << static_cast<bool>(f)
              << ", fail() = " << f.fail()
              << ", eof() = " << f.eof() << '\n';

    // try to extract an integer from text "hello" -> extraction will fail
    int x = 0;
    f >> x;

    std::cout << "After extraction attempt: is_open() = " << f.is_open()
              << ", bool(f) = " << static_cast<bool>(f)
              << ", fail() = " << f.fail()
              << ", eof() = " << f.eof() << '\n';
}
