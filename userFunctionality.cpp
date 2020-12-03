/* C++ MODULES */
#include <iostream>
#include "users/BankUser.h"
#include "accounts/Account.h"
#include "utilities/time.h"
using namespace std;

/* FUNCTION PROTOTYPES */
void userFunctionality(BankUser);
void accountDetails(BankUser, Account*);

/* MAIN */
int main() {
    // Create a dummy User
    BankUser user1("Riley", "Grotenhuis", "8163928687", "833 East Elm Street", "rg1050", "123");

    // Create test Accounts for the dummy User
    Account a1("123", "123", 100, "123");
    Account a2("456", "123", 200, "456");
    Account a3("789", "123", 300, "789");

    // Add those test Accounts to the dummy User's list of Accounts
    user1.addAccount(a1);
    user1.addAccount(a2);
    user1.addAccount(a3);

    userFunctionality(user1);

    return 0;
}

/* USER FUNCTIONALITY FUNCTION */
void userFunctionality(BankUser user) {
    // Output the user's last login
    cout << "Last login: " << user.getLastLogin() << endl;
    // Change the User's last login
    user.setLastLogin(timeAndDate());

    for (;;) {
        // Display the menu to the User
        cout << "[1] Change your username" << endl;
        cout << "[2] Change your password" << endl;
        cout << "[3] View account details" << endl;
        cout << "[4] Exit" << endl;
        
        // Get the menuChoice from the User
        string menuChoice;
        getline(cin, menuChoice);
        cin.clear();

        // If the menuChoice is 1, allow the User to change their current username
        if (menuChoice == "1") {
            string newUsername;
            cout << "Enter your new username: ";
            getline(cin, newUsername);
            user.setUsername(newUsername);
        // If the menuChoice is 2, allow the User to change their current password
        } else if (menuChoice == "2") {
            string newPassword;
            cout << "Enter your new password: ";
            getline(cin, newPassword);
            user.setPassword(newPassword);
        // If the menuChoice is 3, allow the User to view their Account details
        } else if (menuChoice == "3") {
            // Ask for the accountNumber of the Account the User would like to view
            string accountNumber;
            cout << "Enter account number: ";
            getline(cin, accountNumber);
            // Grab that Account using the accountNumber
            Account *tempAccount = user.getAccount(accountNumber);
            if (tempAccount->getAID() == "exit") {
                cout << "Account does not exist" << endl;
            } else {
                accountDetails(user, tempAccount);
            }
        // If the menuChoice is 4, exit that menu
        } else if (menuChoice == "4") {
            break;
        // Otherwise, have the User try again
        } else {
            cout << "Not a valid menu option, try again!" << endl;
        }
    }
}

/* ACCOUNT DETAILS FUNCTION */
void accountDetails(BankUser user, Account *account) {
    for (;;) {
        // Display the menu to the User
        cout << "[1] View account details" << endl;
        cout << "[1] View account balance" << endl;
        cout << "[3] View transaction history" << endl;

        // Get the menuChoice from the User
        string menuChoice;
        getline(cin, menuChoice);

        // If the menuChoice is 1, output the account details to the User
        if (menuChoice == "1") {
            cout << "Account ID: " << account->getAID() << endl;
        // If the menuChoice is 2, output the current balance for that Account
        } else if (menuChoice == "2") {
            cout << "Balance: " << account->getBalance() << endl;
        // If the menuChoice is 3, output the transaction history for that Account
        } else if (menuChoice == "3") {
            vector<string> history = account->getTransactionHistory();
            for (int i = 0; i < history.size(); i++) {
                cout << history[i] << endl;
            }
        // If the menuChoice is 4, exit that menu
        } else if (menuChoice == "exit") {
            break;
        // Otherwise, have the User try again
        } else {
            cout << "Not a valid menu option, try again!" << endl;
        }
    }
}