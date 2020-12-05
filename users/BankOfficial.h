/* C++ MODULES */
#ifndef BANKOFFICIAL_H
#define BANKOFFICIAL_H
#include <iostream>
using namespace std;

/* BANK OFFICIAL DEFINITION */
class BankOfficial {
    private:
        // Personal and Login Information
        string username;
        string password;
        bool active = false;
    public:
        // Constructor
        BankOfficial();
        BankOfficial(string, string);
        // Setters
        void setUsername(string);
        void setPassword(string);
        void setActive(bool);
        // Getters
        string getUsername();
        string getPassword();
        bool getActive();
};

/* CONSTRUCTORS */
BankOfficial::BankOfficial() {
    username = "";
    password = "";
}

BankOfficial::BankOfficial(string username, string password) {
    username = username;
    password = password;
}

/* SETTERS */
void BankOfficial::setUsername(string x) {
    username = x;
}

void BankOfficial::setPassword(string x) {
    password = x;
}

void BankOfficial::setActive(bool x) {
    active = x;
}

/* GETTERS */
string BankOfficial::getUsername() {
    return username;
}

string BankOfficial::getPassword() {
    return password;
}

bool BankOfficial::getActive() {
    return active;
}
#endif