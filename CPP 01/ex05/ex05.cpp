#include <iostream>
#include <string>
#include <algorithm>

class Harl {
    private:
        void debug(void) {
            std::cout << "DEBUG message\n";
        }
        void info(void) {
            std::cout << "INFO message\n";
        }
        void warning(void) {
            std::cout << "WARNING message\n";
        }
        void error(void) {
            std::cout << "ERROR message\n";
        }

    public:
        void complain(const std::string &level) {
            int  i = 0;
            std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

            void    (Harl::*functions[4])() = {
                &Harl::debug,
                &Harl::info,
                &Harl::warning,
                &Harl::error
            };
            while(i < 4) {
                if (levels[i] == level)
                    break;
                i++;
            }
            
            if (i < 4)
                (this->*functions[i])();
            else
                std::cout << "Invalid level" << std::endl;
        }
};

int main() {
    Harl harl;
    harl.complain("DEBUG");
    harl.complain("ERROR");
    harl.complain("BOUH");
}
