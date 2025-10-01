#include "Phonebook.hpp"

Contact::Contact() {
    fname = "";
    lname = "";
    nickname = "";
    number = "";
    secret = "";
}

void    Contact::setFname(const std::string &value) {
    fname = value; }
void    Contact::setLname(const std::string &value) {
    lname = value; }
void    Contact::setNickname(const std::string &value) {
    nickname = value; }
void    Contact::setNumber(const std::string &value) {
    number = value; }
void    Contact::setSecret(const std::string &value) {
    secret = value; }
const std::string& Contact::getFname() const {
    return(fname); }
const std::string& Contact::getLname() const {
    return(lname); }
const std::string& Contact::getNickname() const {
    return(nickname); }
const std::string& Contact::getNumber() const {
    return(number); }
const std::string& Contact::getSecret() const {
    return(secret); }