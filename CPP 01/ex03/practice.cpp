#include <iostream>
#include <string>

class Book {
    private:
        std::string title;

    public:
        Book(std::string t) {
            setTitle(t);
        }

        std::string    getTitle() {
            return(title);
        }

        void    setTitle(std::string t) {
            title = t;
        }
};

int main() {
    Book myBook("C++ for Beginners");

    std::cout << myBook.getTitle() << std::endl;

    myBook.setTitle("Advanced C++");

    std::cout << myBook.getTitle() << std::endl;

    return 0;
}
