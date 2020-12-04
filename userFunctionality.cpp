/* C++ MODULES */
#include <iostream>
#include "accounts/Account.h"
#include "dataStructures/UserBST.h"
#include "users/BankUser.h"
using namespace std;

/* FUNCTION PROTOTYPES */
void bankUserLogin(BiTree*);
void bankUserFunctionality(BankUser*);
void accountDetails(Account*);

/* MAIN */
int main() {
    // Creates the User Binary Search Tree
    BiTree userTree;
    // Creates a dummy User 1
    BankUser user1("Riley", "Grotenhuis", "8163928687", "1714 South Drumm Avenue", "rg1050", "123");
    // Creates test accounts for the User
    Account a1("123", "123", 100, "123");
    Account a2("456", "123", 200, "456");
    Account a3("789", "123", 300, "789");
    // Adds those test accounts to the User's accounts list
    user1.addAccount(a1);
    user1.addAccount(a2);
    user1.addAccount(a3);

    // Insert the dummy user into the UserBST
    userTree.insertNode2(user1);

    // Test the BankUser functionality
    bankUserLogin(&userTree);
    
    return 0;
}

/* BANK USER LOGIN */
void bankUserLogin(BiTree *userTree) {
    for (;;) {
        // Get the User's username
        string username;
        cout << "Username: ";
        getline(cin, username);
        // If the username is exit, break out of the loop
        if (username == "exit") {
            break;
        }
        string password;
        cout << "Password: ";
        getline(cin, password);
        // If the password is exit, break out of the loop
        if (password == "exit") {
            break;
        }

        // Checks whether or not the username and password exist in the UserBST
        bool status1 = userTree->searchNode2(username);
        bool status2 = userTree->searchNode3(password);

        // If the username and password exist, get that username and password's BankUser and run the next function
        if (status1 == 1 && status2 == 1) {
            cout << "success" << endl;
            BankUser *temp = userTree->getUserNode(username);
            bankUserFunctionality(temp);
        // Otherwise, have the User try again
        } else {
            cout << "Username and/or password does not exist, try again!" << endl;
        }
    }
}

/* BANK USER FUNCTIONALITY */
void bankUserFunctionality(BankUser *user) {
    // Output the User's last login, and update the last login as well
    cout << "Last login: " << user->getLastLogin() << endl;
    user->setLastLogin(timeAndDate());

    for (;;) {
        // Display the menu
        cout << "[1] Change your username" << endl;
        cout << "[2] Change your password" << endl;
        cout << "[3] View an account's details" << endl;
        cout << "[4] Exit" << endl;

        // Get the menu choice from the User
        string menuChoice;
        getline(cin, menuChoice);

        if (menuChoice == "1") {
            // Get the new username from the User
            string newUsername;
            cout << "Enter your new username: ";
            getline(cin, newUsername);
            // If the newUsername is exit, continue
            if (newUsername == "exit") {
                continue;
            // Otherwise, set the User's username to the newUsername
            } else {
                user->setUsername(newUsername);
                cout << user->getUsername() << endl;
            }
        } else if (menuChoice == "2") {
            // Get the new password from the User
            string newPassword;
            cout << "Enter your new password: ";
            getline(cin, newPassword);
            // If the newPassword is exit, continue
            if (newPassword == "exit") {
                continue;
            // Otherwise, set the User's password to the newPassword
            } else {
                user->setPassword(newPassword);
                cout << user->getPassword() << endl;
            }
        } else if (menuChoice == "3") {
            // Get the accountNumber from the User
            string accountNumber;
            cout << "Enter your account number: ";
            getline(cin, accountNumber);
            // If the accountNumber exists in the User's account list, run the accountDetails function
            if (user->searchAccount(accountNumber) == 1) {
                Account *temp = user->getAccount(accountNumber);
                accountDetails(temp);
            // Otherwise, output an error message to the User
            } else {
                cout << "Account number does not exist" << endl;
            }
        } else if (menuChoice == "4") {
            break;
        } else {
            cout << "Invalid menu choice, try again!" << endl;
        }
    }
}

/* ACCOUNT DETAILS */
void accountDetails(Account *account) {
    for (;;) {
        // Display the menu to the User
        cout << "[1] View account information" << endl;
        cout << "[2] View account balance" << endl;
        cout << "[3] View transaction history" << endl;
        cout << "[4] Exit" << endl;

        // Get the menu choice from the User
        string menuChoice;
        getline(cin, menuChoice);

        if (menuChoice == "1") {
            account->getAccInfo();
        } else if (menuChoice == "2") {
            cout << "Balance: " << account->getBalance() << endl;
        } else if (menuChoice == "3") {
            vector<string> history = account->getTransactionHistory();
            for (int i = 0; i < history.size(); i++) {
                cout << history[i] << endl;
            }
        } else if (menuChoice == "4") {
            break;
        } else {
            cout << "Invalid menu choice, try again!" << endl;
        }
    }
}