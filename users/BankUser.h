/* C++ MODULES */
#ifndef BANKUSER_H
#define BANKUSER_H
#include <iostream>
#include <vector>
#include "../dataStructures/Stack.h"
#include "../dataStructures/LinkedList.h"
#include "../accounts/Account.h"
using namespace std;

/* BANK USER DEFINITION */
class BankUser {
    private:
        // Personal and Login Information
        string firstName;
        string lastName;
        string phoneNumber;
        string address;
        string username;
        string password;
        // Login History
        string lastLogin;
        // Linked List of Accounts this BankUser owns
        LinkedList accounts;
    public:
        // Constructors
        BankUser();
        BankUser(string, string, string, string, string, string);
        BankUser(string, string, string, string, string, string, string);
        // Setters
        void setFirstName(string);
        void setLastName(string);
        void setPhoneNumber(string);
        void setAddress(string);
        void setUsername(string);
        void setPassword(string);
        void setLastLogin(string);
        // Getters
        string getFirstName();
        string getLastName();
        string getPhoneNumber();
        string getAddress();
        string getUsername();
        string getPassword();
        string getLastLogin();
        // Bank User Operations
        string getInformation();
        // Operations to add and get an Account from a User will go below this line!
        void addAccount(Account);
        Account* getAccount(string);
};

/* CONSTRUCTORS */
BankUser::BankUser() {
    firstName = "";
    lastName = "";
    phoneNumber = "";
    address = "";
    username = "";
    password = "";
}

BankUser::BankUser(string first, string last, string phone, string address, string username, string password) {
    firstName = first;
    lastName = last;
    phoneNumber = phone;
    address = address;
    username = username;
    password = password;
}

BankUser::BankUser(string first, string last, string phone, string address, string username, string password, string lastLogin) {
    firstName = first;
    lastName = last;
    phoneNumber = phone;
    address = address;
    username = username;
    password = password;
    lastLogin = lastLogin;
}

/* SETTERS */
void BankUser::setFirstName(string x) {
    firstName = x;
}

void BankUser::setLastName(string x) {
    lastName = x;
}

void BankUser::setPhoneNumber(string x) {
    phoneNumber = x;
}

void BankUser::setAddress(string x) {
    address = x;
}

void BankUser::setUsername(string x) {
    username = x;
}

void BankUser::setPassword(string x) {
    password = x;
}

void BankUser::setLastLogin(string x) {
    lastLogin = x;
}

/* GETTERS */
string BankUser::getFirstName() {
    return firstName;
}

string BankUser::getLastName() {
    return lastName;
}

string BankUser::getPhoneNumber() {
    return phoneNumber;
}

string BankUser::getAddress() {
    return address;
}

string BankUser::getUsername() {
    return username;
}

string BankUser::getPassword() {
    return password;
}

string BankUser::getLastLogin() {
    return lastLogin;
}

/* GET INFORMATION OPERATION */
string BankUser::getInformation() {
    return firstName + " " + lastName + ", " + phoneNumber + ", " + address;
}

/* ADD ACCOUNT OPERATION */
void BankUser::addAccount(Account x) {
    accounts.append(x);
}

/* GET ACCOUNT OPERATION */
Account* BankUser::getAccount(string x) {
    if (accounts.search(x) == 1) {
         return accounts.get(x);
    } else {
        exit(1);
    }
}
#endif