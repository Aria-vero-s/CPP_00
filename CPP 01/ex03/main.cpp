#include <iostream>

class Weapon {
    private:
        std::string type;
    public:
        Weapon(std::string type) {
            setType(type);
        }
        std::string getType() const {
            return (type);
        }
        void setType(const std::string d) {
            type = d;
        }
};

class HumanA {
    private:
        Weapon type;
        std::string name;
    public:
        HumanA(std::string name, Weapon weapon) {
            setName(name);
        }
        void attack() {
            std::cout << name << " attacks with their " << getType().getDetails() << std::endl;
        }
        Weapon getType() {
            return (type);
        }
        void setType(std::string t) {
            type = t;
        }
        std::string getName() {
            return (name);
        }
        void setName(std::string n) {
            name = n;
        }
};

class HumanB {
    private:
        Weapon type;
        std::string name;
    public:
        HumanB(std::string name, Weapon weapon) {
            setName(name);
        }
        void attack() {
            std::cout << name << " attacks with their " << getType().getDetails() << std::endl;
        }
        Weapon getType() {
            return (type);
        }
        void setType(std::string t) {
            type = t;
        }
        std::string getName() {
            return (name);
        }
        void setName(std::string n) {
            name = n;
        }
};

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}