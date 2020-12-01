#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <time.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iterator>
#include <chrono>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "users/BankOfficial.h"
#include "users/BankUser.h"
#include "dataStructures/Stack.h"
#include "dataStructures/Queue.h"
#include "dataStructures/LinkedList.h"
#include "utilities/ceaserCypher.h"
#include "utilities/stringToVector.h"
#include "utilities/time.h"

using namespace std;

// global vars
// global admin
const string ADMIN_USER_NAME = "daelonKingore69";
const string ADMIN_PASSWORD = "kingoreRocks420";
// secret shut down code
const string SHUT_IT_DOWN = "SHUTITDOWN";

// Individual client structure
struct client{
    // Account accounts; // to be used later
    BankUser user;

    client() {
    }
};

int newAccNum(){
    /* Generates a random number. Will be used after Account class is finished
    to get account nums */
    int accNum;
    srand (time(NULL));
    accNum = rand() % 5000 + 1000;
    return accNum;
}

bool checkIfExit(string line) {
    /* Checks if line is exit or not, and returns true or false accordingly */
    transform(line.begin(), line.end(), line.begin(), ::tolower);
    if (line == "exit")
        return true;
    return false;
}

vector <char> lineToVector(string line) {
    // turns a single word into vector of chars; don't use if more than one word

    vector<char> lineV(line.begin(), line.end());
    return lineV;
}

int threeCaseMenu(string menuItem1, string menuItem2, string menuItem3, string pick1, string pick2, string pick3) {
    /* Takes the arguments passed into the function and displays them to the user in a menu.
    First 4 arguments are the menuItems, and the next 4 is what is displayed if the 
    corresponding menu item is chose.
    Takes user input, tests it, and returns the input as an int to execute the chosen choice.
    Only works if the menu is 3 choices long, since it is the most common type of menu. More
    functions such as fiveCaseMenu() may be created if needed. */
    string userInput;
    int intUserInput;
    bool test;

    do { // displays the menuItems and tests the user input
        for (;;) {
            cout << menuItem1 << "\n"
            << menuItem2 << "\n"
            << menuItem3 << "\n";

            try { // for error handling
                cin >> userInput;
                cin.ignore(100, '\n');
                if (userInput == SHUT_IT_DOWN)
                    exit(0);
                else {
                    intUserInput = stoi(userInput);
                }
                break;
            }

            catch (...) {
                cout << "\n***************************************"
                << "\n* Error. Please Enter '1' '2' or '3'. *\n"
                << "***************************************\n\n";
            }
        }

    // displays corresponding message upon enter a number, returns the number
    switch(intUserInput) {
        case 1:
            {
                cout << "\n" << pick1 << "\n\n"
                << "- - - - - - - - - - - - - - - - - - - -\n\n";
                return 1;
            }
        case 2:
            {
                cout << "\n" << pick2 << "\n\n"
                << "- - - - - - - - - - - - - - - - - - - -\n\n";
                return 2;
            }
        case 3:
            {
                cout << "\n" << pick3 << "\n\n";
                return 3;
            }
        default:
            {
                cout << "\n***************************************"
                << "\n* Error. Please Enter '1' '2' or '3'. *\n"
                << "***************************************\n\n";
            }
        }
    } while (intUserInput > 3 || intUserInput <= 0);
    return intUserInput;
}

int fourCaseMenu(string menuItem1, string menuItem2, string menuItem3, string menuItem4,
    string pick1, string pick2, string pick3, string pick4) {
    /* Takes the arguments passed into the function and displays them to the user in a menu.
    First 4 arguments are the menuItems, and the next 4 is what is displayed if the 
    corresponding menu item is chose.
    Takes user input, tests it, and returns the input as an int to execute the chosen choice.
    Only works if the menu is 4 choices long, since it is the most common type of menu. More
    functions such as fiveCaseMenu() may be created if needed. */
    string userInput;
    int intUserInput;

    do { // displays the menuItems and tests the user input
        for (;;) {
            cout << menuItem1 << "\n"
            << menuItem2 << "\n"
            << menuItem3 << "\n"
            << menuItem4 << "\n";

            try { // for error handling
                cin >> userInput;
                cin.ignore(100, '\n');
                if (userInput == SHUT_IT_DOWN)
                    exit(0);
                else {
                    intUserInput = stoi(userInput);
                }
                break;
            }

            catch (...) {
                cout << "\n*******************************************"
                << "\n* Error. Please Enter '1' '2' '3' or '4'. *\n"
                << "*******************************************\n\n";
            }
        }

    // displays corresponding message upon enter a number, returns the number
    switch(intUserInput) {
        case 1:
            {
                cout << "\n" << pick1 << "\n\n"
                << "- - - - - - - - - - - - - - - - - - - -\n\n";
                return 1;
            }
        case 2:
            {
                cout << "\n" << pick2 << "\n\n"
                << "- - - - - - - - - - - - - - - - - - - -\n\n";
                return 2;
            }
        case 3:
            {
                cout << "\n" << pick3 << "\n\n"
                << "- - - - - - - - - - - - - - - - - - - -\n\n";
                return 3;
            }
        case 4:
            {
                cout << "\n" << pick4 << "\n\n";
                return 4;
            }
        default:
            {
                cout << "\n***************************************"
                << "\n* Error. Please Enter '1' '2' or '3'. *\n"
                << "***************************************\n\n";
            }
        }
    } while (intUserInput > 4 || intUserInput <= 0);
    return intUserInput;
}

bool stringTest(string line, bool letterCheck, bool numberCheck) {
    /* Built primarily for error handling for a users input of firstName, lastName, phoneNumber,
    and address. Takes line and splits it into a vector of chars, then tests it against one of
    the three arrays of chars. If something exists in the vector form of line and not in the
    comparitive array, it returns false. Enter letterCheck as true to test just the letters
    (correctCharsInNames), numberCheck as bools to test nums (correctCharsInPhone), and enter
    both as true to test both (correctCharsInAddress). */
    vector <char> lineV = lineToVector(line);

    char correctCharsInNames[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
    'z' };

    char correctCharsInPhone[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '(', ')' };

    char correctCharsInAddress[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
    'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ' ' };

    int lettersSize = sizeof(correctCharsInNames) / sizeof(correctCharsInNames[0]); 
    int numsSize = sizeof(correctCharsInPhone) / sizeof(correctCharsInPhone[0]);
    int addressSize = sizeof(correctCharsInAddress) / sizeof(correctCharsInAddress[0]);

    int i = 0, j = 0;
    if (letterCheck) {
        for (i = 0; i < lineV.size(); i++) {
            for (j = 0; j < lettersSize; j++) {
                if (lineV[i] == correctCharsInNames[j])
                    break;
            }
            if (j == lettersSize)
                return false;
        }
        return true;
    }

    if (numberCheck) {
        for (int i = 0; i < lineV.size(); i++) {
            for (int j = 0; j < numsSize; j++) {
                if (lineV[i] == correctCharsInPhone[j])
                    break;
            }
            if (j == numsSize)
                return false;
        }
        return true;
    }

    if (numberCheck && letterCheck) {
        for (int i = 0; i < lineV.size(); i++) {
            for (int j = 0; j < addressSize; j++) {
                if (lineV[i] == correctCharsInAddress[j])
                    break;
            }
            if (j == addressSize)
                return false;
        }
        return true;
    }
    return true;
}

void userCheckingAccount(BankUser dummyUser) {
    /* VERY UNFINISHED. Contains the code to access a users checking account via
    the users info. Will eventuall show: Account Info, Balance, and Transaction Records. */
    string userAccNum;
    bool success = false;

    // get account num
    cout << "Please enter your checking account number "
    << "(Enter 'exit' to return to account page): ";
    cin >> userAccNum;
    cin.ignore(100, '\n');

    // check if checking number matches via BST (add later)
    Account *temp = dummyUser.getAccount(userAccNum);
    if (userAccNum == temp->getAID()) {
        cout << "Successful Account info\n";
        success = true;
    }

    else {
        cout << "unsuccessful" << endl;
    }

    for (;;) {
        if (success) {
            string userInput;
            int intUserInput;

            try {
                cin >> userInput;
                cin.ignore(100, '\n');
                intUserInput = stoi(userInput);
            }
            catch (...) {
                cout << "\n*******************************************"
                << "\n* Error. Please Enter '1' '2' '3' or '4'. *\n"
                << "*******************************************\n\n";
                break;
            }
        }
    }
}

/***********************************************************

Login functions for types of logins (Users/Officials/Admins) 

************************************************************/

void userLogin(BankUser dummyUser) {
    /* Basically finished I think, needs implementation of the corresponding functions
    in the switch statement. Contains the code that asks for username and password from 
    user, and displays the menu if successful. */
    string userName, password, userAccountNum;
    
    // get username and password and test them
    cout << "Please enter your account information, or type 'exit' to quit:\n"
    << "Username - ";
    cin >> userName;
    cin.ignore(100, '\n');
    
    if (checkIfExit(userName))
        return;

    cout << "Password - ";
    cin >> password;
    cin.ignore(100, '\n');

    if (checkIfExit(password))
        return;

    // check if userName and password is correct by looping through the BST of users (add later)
    if (dummyUser.getUsername() == userName && dummyUser.getPassword() == password) {
        cout << "\nSuccessful Login!\n\n";
    }

    else {
        cout << "\nError! No User Login under specified information, please try again.\n\n";
        userLogin(dummyUser);
    }

    /* 5 case menu (may be replaced with a functionif more than one 5 case menus is needed 
    in the future) */
    while (true) {
        cout << "Please enter an account number: ";
        cin >> userAccountNum;
        /* if (test if userAccountNum exists here)
            break;
           else {
               error message and keep looping
           }
        */
    }
}

void addNewUserLogin() {
    /* Function to create a new User Login with inputed names, phoneNumber, address, username
    and password. */
    string firstName, lastName, phoneNumber, address, username, password;
    cout << "At any time type 'exit' to cancel and quit.\n";

    // get and check first name, loop until exit is inputed or no special character exist
    while (true) {
        cout << "\nEnter first name: ";
        cin >> firstName;
        cin.ignore(100, '\n');

        if (checkIfExit(firstName))
            return;

        else if (stringTest(firstName, true, false)) {
            break;
        }
        else {
            cout << "No special characters or numbers allowed, please try again.\n";
        }
    }

    // get and check last name, loop until exit is inputed or no special character exist
    while (true) {
        cout << "\nEnter last name: ";
        cin >> lastName;
        cin.ignore(100, '\n');
        
        if (checkIfExit(lastName))
            return;

        else if (stringTest(lastName, true, false)) {
            break;
        }
        else {
            cout << "No special characters or numbers allowed, please try again.\n";
        }
    }

    // get and check phone number, loop until exit is inputed or no letters exist
    while (true) {
        cout << "\nEnter phone number: ";
        cin >> phoneNumber;
        cin.ignore(100, '\n');
        
        if (checkIfExit(phoneNumber))
            return;

        else if (stringTest(phoneNumber, false, true)) {
            break;
        }
        else {
            cout << "No letters or special characters allowed, please try again.\n";
        }
    }

    // get and check first name, loop until exit is inputed or no special characters exist
    while (true) {
        cout << "\nEnter address: ";
        cin >> address;
        cin.ignore(100, '\n');
        if (checkIfExit(address))
            return;

        else if (stringTest(address, true, true)) {
            break;
        }
        else {
            cout << "No special characters allowed, please try again.\n";
        }
    }

    // get username and password, can be anything as long as there's no spaces
    while (true) {
        try {
            cout << "\nWhat is the username for this account?: ";
            cin >> username;
            cin.ignore(100, '\n');
            cout << "\nWhat is the password for this account?: ";
            cin >> password;
            cin.ignore(100, '\n');
            cout << "\n";
            break;
        }

        catch (...) {
            cout << "\n***************************************"
                << "\n* Username or password cannot contain a space. *\n"
                << "***************************************\n\n";
        }
    }

    // ADD USER INFO! add functionality later
}

void closeUserLogin(BankOfficial dummyOfficial, BankUser dummyUser) {
    /* Function to close out a user Login, and all of its accounts. Requires the user
    to login as well as the official. */
    string yesOrNo, username, password;

    while (true) {
        cout << "Please have the Client enter his/her username and password.\n";
        cout << "Username: ";
        cin >> username;
        cin.ignore(100, '\n');
        if (checkIfExit(username))
            return;
        cout << "Password: ";
        cin >> password;
        cin.ignore(100, '\n');
        if (checkIfExit(password))
            return;

        // Check to see if username and password exists in the BST; ADD LATER
        if (username != dummyUser.getUsername() || password != dummyUser.getPassword()) {
            cout << "Username or Password Incorrect. Try again or type 'exit' to quit.\n\n";
        }
        else
            break;
    }

    while (true) {
        cout << "\n- - - - - - - - - - - - - - - - - - - -\n\n"
        << "Closing this User Login will cause all accounts to close,\nwithdrawing"
        << " all money (any applicable fees will be applied).\n\n"
        << "- - - - - - - - - - - - - - - - - - - -\n\n"
        <<"Continue? Enter y/n: ";
        cin >> yesOrNo;
        cin.ignore(100, '\n');
        if (stringTest(yesOrNo, true, false)) {
            break;
        }
        else if (yesOrNo != "Y" || yesOrNo != "y" || yesOrNo != "N" || yesOrNo != "n")
            cout << "\nPlease enter only 'y' or 'n' for yes or no.\n\n";
        else
            cout << "\nPlease enter only 'y' or 'n' for yes or no.\n\n";
    }

    if (yesOrNo == "Y" || yesOrNo == "y") {
        cout << "\nClosing Login...\n\n";
        return;
        // Close user account; ADD LATER
    }
    else {
        cout << "\nCancelling...\n\n";
        return;
    }
}

void accessingUserAccounts(BankOfficial dummyOfficial, BankUser dummyUser) {
    int choice;

    cout << "Accessing User Accounts\n\n"
    << "- - - - - - - - - - - - - - - - - - - -\n\n";
    choice = fourCaseMenu("1) Access a Specific Account", "2) Close a Specific Account", 
    "3) Create a Specific Account", "4) Exit", "Accessing a Specific Account", 
    "Closing a Specific Account", "Creating a Specific Account", "Exiting");


}

void officialLogin(BankOfficial dummyOfficial, BankUser dummyUser) {
    /* Less finished than User, but very close. Needs implementation of the switch statement
    to corresponding functions. Contains the code to get username and password of official. Then
    displays the menu options. */
    string userName, password;
    int choice = 0;
    
    // Recieve inputs for username and password and test them
    cout << "Please enter your account information, or type 'exit' to quit:\n"
    << "Username - ";
    cin >> userName;
    cin.ignore(100, '\n');
    
    if (checkIfExit(userName))
        return;

    cout << "Password - ";
    cin >> password;
    cin.ignore(100, '\n');

    if (checkIfExit(password))
        return;

    // Check if userName and password is correct by looping through the BST of officials (add later)
    if (dummyOfficial.getUsername() == userName && dummyOfficial.getPassword() == password) {
        cout << "\nSuccessful Login!\n\n";
    }

    else {
        cout << "\nError! No Official Login under specified information, please try again.\n\n";
        officialLogin(dummyOfficial, dummyUser);
    }

    while (choice != 3) {
        choice = threeCaseMenu("1) Open/Close Login", "2) Access Login", "3) Exit", 
        "Opening or Closing a Login", "Accessing a Login", "Exiting");

        // Open/Close login
        if (choice == 1) {
            cout << "What would you like to do?\n";
            choice = threeCaseMenu("1) Open (Create) User Login", "2) Close a User Login", "3) Exit", 
            "Opening (Creating) a User Login", "Closing a User Login", "Exiting");

            if (choice == 1) {
                addNewUserLogin();
            }
            else if (choice == 2) {
                closeUserLogin(dummyOfficial, dummyUser);
            }
        }

        // Accessing login
        if (choice == 2) {
            while (true) {
                // Retrive username and password and test them
                cout << "Please enter your username and password.\n"
                << "Username: ";
                cin >> userName;
                cin.ignore(100, '\n');
        
                if (checkIfExit(userName))
                    return;

                cout << "Password: ";
                cin >> password;
                cin.ignore(100, '\n');

                if (checkIfExit(password))
                    return;

                if (dummyUser.getUsername() == userName && dummyUser.getPassword() == password) {
                    cout << "\nSuccessful Login!\n\n";
                    break;
                }

                else {
                    cout << "\nError! No User Login under specified information, please try again.\n\n";
                    officialLogin(dummyOfficial, dummyUser);
                }
            }
            // If successful, access the user
            accessingUserAccounts(dummyOfficial, dummyUser);
        }
    }
}

void adminLogin() {
    /* UNFINISHED. Currently only tests if username and password checks are successful. Will
    eventually also display the admin menu options. */
    string userName, password;

    cout << "Please enter your account information, or type 'exit' to quit:\n"
    << "Username - ";
    cin >> userName;
    cin.ignore(100, '\n');
    
    if (checkIfExit(userName))
        return;

    cout << "Password - ";
    cin >> password;
    cin.ignore(100, '\n');

    if (checkIfExit(password))
        return;

    if (userName == ADMIN_USER_NAME && password == ADMIN_PASSWORD) {
        cout << "\nSuccessful Login!\n\n";
    }

    else {
        cout << "\nError! No Admin Login under specified information, please try again.\n\n";
        adminLogin();
    }
}

/*********************************************************** 

Displays opening page to the user 

************************************************************/

void welcomeScreen(BankUser dummyUser, BankOfficial dummyOfficial){
    /* Contains the starting menu options, and calls switch statment's corresponding functions */
    int choice;

    while (true) {
        cout << "- - - - - - - - - - - - - - - - - - - -\n\n" 
        << "Welcome to the Bear Bank!\n\n"
        "- - - - - - - - - - - - - - - - - - - -\n\n"
        << "Please Enter a Number to Login:\n";
        choice = threeCaseMenu("1) User Account", "2) Bear Bank Official", "3) Bear Bank Admin",
        "Entering User Login", "Entering Official Login", "Entering Admin Login");

        if (choice == 1) {
            userLogin(dummyUser);
        }
        else if (choice == 2) {
            officialLogin(dummyOfficial, dummyUser);
        }
        else {
            adminLogin();
        }
    }
}

int main() {
    /* controls the program */
    BankUser dummyUser;
    BankOfficial dummyOfficial;

    // create a dummy user
    dummyUser.setFirstName("Daelon");
    dummyUser.setLastName("Kingore");
    dummyUser.setPhoneNumber("417-408-1486");
    dummyUser.setAddress("1234 S Oak St");
    dummyUser.setUsername("dk");
    dummyUser.setPassword("dk12");

    // create a dummy official
    dummyOfficial.setUsername("official");
    dummyOfficial.setPassword("oPassword");

    // display the welcome screen
    welcomeScreen(dummyUser, dummyOfficial);
    return 0;
}