#ifndef PHONEBOOK_H
#define PHONEBOOK_H

    #include <iostream>
    #include <string>
    #include <iomanip>
    #include <cstdlib>

    #define RESET   "\033[0m"
    #define RED     "\033[31m"
    #define MAGENTA "\033[35m"
    #define CYAN    "\033[36m"
    #define BOLD    "\033[1m"

    #define MAX 8

    class Contact {
        private:
            std::string fname;
            std::string lname;
            std::string nickname;
            std::string number;
            std::string secret;
        public:
            Contact();
            void setFname(const std::string &value);
            void setLname(const std::string &value);
            void setNickname(const std::string &value);
            void setNumber(const std::string &value);
            void setSecret(const std::string &value);
            const std::string& getFname() const;
            const std::string& getLname() const;
            const std::string& getNickname() const;
            const std::string& getNumber() const;
            const std::string& getSecret() const;
    };

    class Phonebook {
        private:
            int quantity;
            int oldest;
            Contact arr[MAX];
        public:
            Phonebook();
            int getQuantity() const;
            const Contact& getContact(int i) const;
            void addContact(const Contact &contact);
    };
    bool checkNumber(std::string &input);
    bool promptLine(std::string &input);
    bool promptNumber(std::string &input);
    int addNewContact(Phonebook &phonebook);
    std::string formatField(const std::string& input);
    int SecondPrompt(Phonebook &phonebook);
    void PrintSearchResults(Phonebook &phonebook);
    int ExitPhonebook();

#endif