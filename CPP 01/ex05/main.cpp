#include <iostream>
#include <string>

class Harl {
    private:
        void    debug(void) {
            std::cout << "DEBUG1" << std::endl;
        }
        void    info(void) {
            std::cout << "INFO1" << std::endl;
        }

    public:
        void    complain(std::string level) {
            std::string arr[2] = {"DEBUG", "INFO"};
            
        }
};

int main() {
    Harl harl;
    harl.complain("DEBUG");
    harl.complain("INFO");
}
