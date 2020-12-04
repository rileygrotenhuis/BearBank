// global vars
// Global User BST
// BiTree users;
OfficialTree officials;
// global admin
const string ADMIN_USER_NAME = "daelonKingore69";
const string ADMIN_PASSWORD = "kingoreRocks420";
// secret shut down code
const string SHUT_IT_DOWN = "SHUTITDOWN";

//CD Variables for Admin
int termLength;
float interestCD;
float penaltyPercentage;
//Custom Variables for Admin
float customInterest;
float monthlyFee;
float serviceCharge;

/* FUNCTION PROTOTYPES */
void bankUserLogin(BiTree*);
void bankUserFunctionality(BankUser*);
void accountDetails(Account*);

int newAccNum(){
    /* Generates a random number */
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
    if (letterCheck == true && numberCheck == false) {
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

    i = 0, j = 0;
    if (numberCheck == true && letterCheck == false) {
        for (i = 0; i < lineV.size(); i++) {
            for (j = 0; j < numsSize; j++) {
                if (lineV[i] == correctCharsInPhone[j])
                    break;
            }
            if (j == numsSize)
                return false;
        }
        return true;
    }

    i = 0, j = 0;
    if (numberCheck && letterCheck) {
        for (i = 0; i < lineV.size(); i++) {
            for (j = 0; j < addressSize; j++) {
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

void userCheckingAccount() {
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
    /*if (userAccNum == dummyUser.getCheckingsAccount(userAccNum)) {
        cout << "Successful Account info\n";
        success = true;
    }

    else {
        cout << "unsuccessful" << endl;
    }*/

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

/* BANK USER LOGIN */
void bankUserLogin(BiTree *users) {
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
        bool status1 = users->searchNode2(username);
        bool status2 = users->searchNode3(password);
        // If the username and password exist, get that username and password's BankUser and run the next function
        if (status1 == 1 && status2 == 1) {
            cout << "success" << endl;
            BankUser *temp = users->getUserNode(username);
            cout << "success 2" << endl;
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

void addNewUserLogin(BiTree *users) {
    /* Function to create a new User Login with inputed names, phoneNumber, address, username
    and password. */
    string firstName, lastName, phoneNumber, address, username, password;
    cout << "At any time type 'exit' to cancel and quit.\n\n"
    << "- - - - - - - - - - - - - - - - - - - -\n";

    // get and check first name, loop until exit is inputed or no special character exist
    while (true) {
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
            cout << "Enter last name: ";
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

        if (users->searchNode5(firstName) && users->searchNode6(lastName)) {
            cout << "This name already exists in this bank. Please enter a different name.\n";
        }
        break;
    }

    // get and check phone number, loop until exit is inputed or no letters exist
    while (true) {
        cout << "Enter phone number in form of (555)555-5555: ";
        cin >> phoneNumber;
        cin.ignore(100, '\n');
        
        if (checkIfExit(phoneNumber))
            return;

        else if (stringTest(phoneNumber, false, true) == false) {
            cout << "No letters or special characters allowed, please try again.\n";
            continue;
        }

        if (users->searchNode4(phoneNumber)) {
            cout << "Error. This phone number already exists for a user, \nif it is your"
            << "phone number then you already have an account. \nPlease try again or type 'exit'"
            << "to cancel.\n";
            continue;
        }

        if (phoneNumber.length() != 13)
            cout << "Please input your phone number in the correct form.\n";
        else if (phoneNumber[0] != '(' || phoneNumber[4] != ')' || phoneNumber[8] != '-')
            cout << "Please input your phone number in the correct form.\n";
        
        else {
            break;
        }
    }

    // get and check first name, loop until exit is inputed or no special characters exist
    while (true) {
        cout << "Enter address: ";
        getline(cin, address);
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
    string yesOrNo;
    while (true) {
        cout << "What is the username for this account?: ";
        cin >> username;
        cin.ignore(100, '\n');

        if (checkIfExit(address)) {
            cout << "Cancelling...\n\n";
            return;
        }

        if (users->searchNode2(username)) {
            cout << "That username already exists, please use a different one.\n";
        }
        else
            break;
    }

    while (true) {
        cout << "What is the password for this account?: ";
        cin >> password;
        cin.ignore(100, '\n');
        if (checkIfExit(address)) {
            cout << "Cancelling...\n\n";
            return;
        }

        cout << "\n- - - - - - - - - - - - - - - - - - - -"
        << "\nUsername: " << username << "\nPassword: " << password
        << "\n\nName: " << firstName << " " << lastName << "\nPhone number: "
        << phoneNumber << "\nAddress: " << address
        << "\n- - - - - - - - - - - - - - - - - - - -"
        "\n\nIs this correct? [y/n]: ";

        cin >> yesOrNo;
        cin.ignore(100, '\n');
        while (true) {
            if (yesOrNo == "Y" || yesOrNo == "y" || yesOrNo == "N" || yesOrNo == "n") 
                break;
            else
                cout << "\nPlease enter only 'y' or 'n' for yes or no.\n\n";
        }

        if (yesOrNo == "Y" || yesOrNo == "y") {
            BankUser newUser(firstName, lastName, phoneNumber, address, username, password);
            users->insertNode2(newUser);

            cout << "You have successfully created a login at Bear Bank!\n"
            << "We are exited to work with you!\n\n";
            break;
        }
        else {
            cout << "\n- - - - - - - - - - - - - - - - - - - -\n\n"
            << "Restarting login creation...\n\n";
            addNewUserLogin(users);
        }
    }
}

void closeUserLogin(BiTree *users) {
    /* Function to close out a user Login, and all of its accounts. Requires the user
    to login as well as the official. */
    string yesOrNo, username, password;
    BankUser * temp;

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

        temp = users->getUserNode(username);

        // Check to see if username and password exists in the BST; ADD LATER
        if (username != temp->getUsername() || password != temp->getPassword()) {
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
        while (true) {
            if (yesOrNo == "Y" || yesOrNo == "y" || yesOrNo == "N" || yesOrNo == "n")
                break;
            else
                cout << "\nPlease enter only 'y' or 'n' for yes or no.\n\n";
        }

        if (yesOrNo == "Y" || yesOrNo == "y") {
            cout << "\nClosing Login...\n\n";
            BankUser * closeUser;
            closeUser = users->getUserNode(username);
            closeUser->setFlag(false);
            break;
        }
        else {
            cout << "\nCancelling...\n\n";
            break;
        }
    }
}

bool isNumber(string nums) {
    vector <char> numsV = lineToVector(nums);
    char numbers[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.' };
    int i = 0, j = 0;

    for (i = 0; i < numsV.size(); i++) {
        for (j = 0; j < 11; j++) {
            if (numsV[i] == numbers[j])
                break;
        }
        if (j == 11)
            return false;
    }
    return true;
}

void accessingSpecificAccount(BiTree *users, string username) {
    string accntNumInput;
    BankUser * temp = users->getUserNode(username);

    while (true) {
        cout << "Enter your account number or 'exit' to go back: ";
        cin >> accntNumInput;
        cin.ignore(100, '\n');
        if (checkIfExit(accntNumInput))
            return;

        if (accntNumInput[0] == 'C' && accntNumInput[1] == 'D') {
            cout << "Cannot access a CD, if you wish to withdraw, close the account.\n\n";
        }

        else if (temp->getAccount(accntNumInput)->getCFlag()) {
            cout << "Cannot access a closed account.\n\n";
        }

        else if (users->searchNode(temp->getUsername(), true, false, false, false, false)) {
            if (temp->searchAccount(accntNumInput))
                break;
            else
                cout << "Incorrect Account Number retry or type 'exit' to go back.\n\n";
        }
    }

    int choice = 0;
    while (choice != 3) {
        choice = threeCaseMenu("1) Deposit", "2) Withdraw", "3) Go Back", 
        "Entering Deposit", "Entering Withdraw", "Exiting");

        string depositAmmnt, withdrawAmmnt;
        double deposit, withdraw;
        
        if (choice == 1) {
            while (true) {
                cout << "\nEnter the amount to be deposited or 'exit' to cancel: ";
                cin >> depositAmmnt;
                cin.ignore(100, '\n');
                if (checkIfExit(depositAmmnt)) {
                    cout << "Cancelling...\n\n";
                    break;
                }
                else if (isNumber(depositAmmnt)) {
                    deposit = stod(depositAmmnt);
                    if (deposit > 0) {
                        BankUser * tempB;
                        Account * tempA;
                        tempB = users->getUserNode(temp->getUsername());
                        tempA = tempB->getAccount(accntNumInput);
                        tempA->deposit(deposit);
                        break;
                    }
                    cout << "Please enter only a number greater than 0\n\n";
                }
                else 
                    cout << "Please enter only a number greater than 0\n\n";
            }
        }

        if (choice == 2) {
            while (true) {
                cout << "\nEnter the amount to be withdrawn or 'exit' to cancel: ";
                cin >> withdrawAmmnt;
                cin.ignore(100, '\n');
                if (checkIfExit(withdrawAmmnt)) {
                    cout << "Cancelling...\n\n";
                    break;
                }
                else if (isNumber(withdrawAmmnt)) {
                    withdraw = stod(withdrawAmmnt);
                    if (withdraw > 0) {
                        BankUser * tempBU;
                        Account * tempAW;
                        tempBU = users->getUserNode(temp->getUsername());
                        tempAW = tempBU->getAccount(accntNumInput);
                        tempAW->withdraw(withdraw);
                        break;
                    }
                    cout << "Please enter only a number greater than 0\n\n";
                }
                else 
                    cout << "\nPlease enter only a number\n\n";
            }
        }
    }
}

void createAccnt(BiTree *users, string username) {
    string password;

    BankUser * temp = users->getUserNode(username);
    while (true) { // while statement to be utilized later
        cout << "Enter User password or type 'exit' to go back: ";
        cin >> password;
        cin.ignore(100, '\n');
        if (checkIfExit(password))
            return;
        else if (temp->getPassword() == password)
            break;
        else {
            cout << "\nIncorrect password. Retry or type 'exit' to go back.\n\n"
            << "- - - - - - - - - - - - - - - - - - - -\n\n";
        }
    }

    cout << "\nWhat kind of account will be made?\n";

    /* 5 case menu (may be replaced with a functionif more than one 5 case menus is needed 
    in the future) */
    string userInput;
    int intUserInput;
    do {
        while (true) {
            // menu
            cout << "1) Checkings Account\n"
            << "2) Savings Account\n"
            << "3) CD Account\n"
            << "4) Bear Bank Custom Account\n"
            << "5) Exit\n";

            try { // try to turn the string into an int (error handling)
                cin >> userInput;
                cin.ignore(100, '\n');
                intUserInput = stoi(userInput);
                break;
            }

            catch (...) {
                cout << "\n***********************************************"
                << "\n* ERROR. Please Enter '1' '2' '3' '4' or '5'. *\n"
                << "***********************************************\n\n";
            }
        }

        // execute menu options
        string initialBalanceS, accountNum;
        float initialBalance;

        switch(intUserInput) {
            case 1:
                {
                    cout << "\nCreating Checking Account\n\n"
                    << "- - - - - - - - - - - - - - - - - - - -\n\n";
                    while (true) {
                        cout << "What is you're initial balance?: ";
                        cin >> initialBalanceS;
                        cin.ignore(100, '\n');
                        if (checkIfExit(initialBalanceS)) {
                            cout << "Cancelling...\n\n";
                            break;
                        }
                        else if (isNumber(initialBalanceS)) {
                            initialBalance = stof(initialBalanceS);
                            if (initialBalance > 0) {
                                accountNum = to_string(newAccNum());
                                Account tempA(temp->getUsername(), password, 
                                    initialBalance, accountNum);
                                temp->addAccount(tempA);
                                cout << "\nAccont has been created!"
                                << "You're new account number is: C" << accountNum << endl;
                                break;
                            }
                        }
                            cout << "Please enter only a number greater than 0\n\n";
                    }
                    break;
                }
            case 2:
                {
                    cout << "\nCreating Savings Account\n\n"
                    << "- - - - - - - - - - - - - - - - - - - -\n\n";
                    while (true) {
                        cout << "What is you're initial balance?: ";
                        cin >> initialBalanceS;
                        cin.ignore(100, '\n');
                        if (checkIfExit(initialBalanceS)) {
                            cout << "Cancelling...\n\n";
                            break;
                        }
                        else if (isNumber(initialBalanceS)) {
                            initialBalance = stof(initialBalanceS);
                            if (initialBalance > 0) {
                                accountNum = to_string(newAccNum());
                                Account tempA(temp->getUsername(), temp->getPassword(), 
                                    initialBalance, .05, accountNum);
                                temp->addAccount(tempA);
                                cout << "\nAccont has been created!"
                                << "You're new account number is: C" << accountNum << endl;
                                break;
                            }
                        }
                            cout << "Please enter only a number greater than 0\n\n";
                    }
                    break;
                }
            case 3:
                {
                    cout << "\nCreating CD Account\n\n"
                    << "- - - - - - - - - - - - - - - - - - - -\n\n";
                    while (true) {
                        cout << "What is you're initial balance?: ";
                        cin >> initialBalanceS;
                        cin.ignore(100, '\n');
                        if (checkIfExit(initialBalanceS)) {
                            cout << "Cancelling...\n\n";
                            break;
                        }
                        else if (isNumber(initialBalanceS)) {
                            initialBalance = stof(initialBalanceS);
                            if (initialBalance > 0) {
                                accountNum = to_string(newAccNum());
                                Account tempA(temp->getUsername(), temp->getPassword(), 
                                    initialBalance, .05, .05, accountNum, "1232021");
                                temp->addAccount(tempA);
                                cout << "\nAccont has been created!"
                                << "You're new account number is: C" << accountNum << endl;
                                break;
                            }
                        }
                            cout << "Please enter only a number greater than 0\n\n";
                    }
                    break;
                }
            case 4:
                {
                    cout << "\nCreating Bear Bank Custom Account\n\n"
                    << "- - - - - - - - - - - - - - - - - - - -\n\n";
                    while (true) {
                        cout << "What is you're initial balance?: ";
                        cin >> initialBalanceS;
                        cin.ignore(100, '\n');
                        if (checkIfExit(initialBalanceS)) {
                            cout << "Cancelling...\n\n";
                            break;
                        }
                        else if (isNumber(initialBalanceS)) {
                            initialBalance = stof(initialBalanceS);
                            if (initialBalance > 0) {
                                accountNum = to_string(newAccNum());
                                Account tempA(temp->getUsername(), temp->getPassword(), 
                                    initialBalance, .05, 5, 10, accountNum);
                                temp->addAccount(tempA);
                                cout << "\nAccont has been created!"
                                << "You're new account number is: C" << accountNum << endl;
                                break;
                            }
                        }
                            cout << "Please enter only a number greater than 0\n\n";
                    }
                    break;
                }
            case 5:
                {
                    cout << "Exiting\n\n";
                    return;
                }
            default:
                {
                    cout << "\n***********************************************"
                    << "\n* Error. Please Enter '1' '2' '3' '4' or '5'. *\n"
                    << "***********************************************\n\n";
                }
        }
    } while(intUserInput > 5 || intUserInput <= 0); // loops if out-of-range num entered
}

void closeAccnt(BiTree *users, string username) {
    string accntNum;

    while (true) {
        cout << "Enter Your Account Number or type 'exit' to go back: ";
        cin >> accntNum;
        cin.ignore(100, '\n');
        if (checkIfExit(accntNum))
            return;
        
        BankUser * temp = users->getUserNode(username);
        if (accntNum == temp->getAccount(accntNum)->getAID()) {
            delete temp;
            break;
        }
        else {
            cout << "\nIncorrect accntNum. Retry or type 'exit' to go back.\n\n"
            << "- - - - - - - - - - - - - - - - - - - -\n\n";
        }
    }

    string yesOrNo;
    while (true) {
        cout << "\n\nYou can choose where to send the money.\n"
        << "Are you sure you want to close this account?[y/n]: ";

        while (true) {
        cin >> yesOrNo;
        cin.ignore(100, '\n');
            if (yesOrNo == "Y" || yesOrNo == "y" || yesOrNo == "N" || yesOrNo == "n") 
                break;
            else
                cout << "\nPlease enter only 'y' or 'n' for yes or no.\n\n";
        }
    }

    while (true) {
        BankUser * temp = users->getUserNode(username);
        Account * tempAccount = temp->getAccount(accntNum);
        if (yesOrNo == "Y" || yesOrNo == "y") {
            string userChoice;
            float oldBalance = tempAccount->getBalance();
            tempAccount->setCFlag(true);

            cout << "Closing Account. Enter the account number to deposit, or type 'cash'"
            << " to get a cash withdraw.\n";

            cin >> userChoice;
            cin.ignore(100, '\n');

            if (checkIfExit(accntNum) == true || userChoice == "cash" || userChoice == "Cash") {
                cout << "\nWithdrawing as cash...\n\n";
                break;
            }

            else if (temp->searchAccount(userChoice)) {
                Account * tempAccount2 = temp->getAccount(userChoice);
                tempAccount2->deposit(oldBalance);
                break;
            }

            else {
                cout << "Invalid input, retry or type 'cash' or 'exit' to withdraw via cash.\n\n";
            }
        }
        else {
            cout << "\n- - - - - - - - - - - - - - - - - - - -\n\n"
            << "Cancelling...\n\n";
            break;
        }
    }
}

void accessingUserAccounts(BiTree *users, string username) {
    int choice = 0;

    while (choice != 4) {
        cout << "Accessing User Accounts\n\n"
        << "- - - - - - - - - - - - - - - - - - - -\n\n";
        choice = fourCaseMenu("1) Access a Specific Account", "2) Create a Specific Account", 
        "3) Close a Specific Account", "4) Exit", "Accessing a Specific Account", 
        "Creating a Specific Account", "Closing a Specific Account", "Exiting");

        if (choice == 1) {
            accessingSpecificAccount(users, username);
        }

        if (choice == 2) {
            createAccnt(users, username);
        }

        if (choice == 3) {
            closeAccnt(users, username);
        }
    }
}

void officialLogin(BiTree *users) {
    /* Less finished than User, but very close. Needs implementation of the switch statement
    to corresponding functions. Contains the code to get username and password of official. Then
    displays the menu options. */
    string userName, password, inputUsername;
    int choice = 0;
    BankUser * temp;
    BankOfficial * tempOfficial;
    Account * tempAccount;
    
    while (true) {
        // Recieve inputs for username and password and test them
        cout << "Please enter your login information, or type 'exit' to quit:\n"
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

        tempOfficial = officials.getOfficialNode(userName);
        if (officials.searchNode(userName)) {
            if (tempOfficial->getPassword() == password) {
                cout << "\nSuccessful Login!\n\n";
                break;
            }
        }

        else {
            cout << "\nError! No Official Login under specified information, please try again.\n\n";
        }
    }

    while (choice != 4) {
        choice = fourCaseMenu("1) Open/Close Login", "2) Access Login", "3) Search for Accounts", "4) Exit",
        "Opening or Closing a Login", "Accessing a Login", "Searching for accounts", "Exiting");

        // Open/Close login
        if (choice == 1) {
            cout << "What would you like to do?\n";
            choice = threeCaseMenu("1) Open (Create) User Login", "2) Close a User Login", "3) Exit", 
            "Opening (Creating) a User Login", "Closing a User Login", "Exiting");

            if (choice == 1) {
                addNewUserLogin(users);
            }
            else if (choice == 2) {
                closeUserLogin(users);
            }
        }

        // Accessing login
        else if (choice == 2) {
            while (true) {
                // Retrive username and password and test them
                cout << "User please enter your username and password.\n"
                << "Username: ";
                cin >> inputUsername;
                cin.ignore(100, '\n');
        
                if (checkIfExit(inputUsername))
                    return;

                cout << "Password: ";
                cin >> password;
                cin.ignore(100, '\n');

                if (checkIfExit(password))
                    return;

                if (users->searchNode2(inputUsername)) {
                    temp = users->getUserNode(inputUsername);
                    if (temp->getPassword() == password) {
                        cout << "\nSuccessful Login!\n\n";
                        break;
                    }
                    else {
                       cout << "\nError! No User Login under specified information, please try again.\n\n"; 
                    }
                }

                else {
                    cout << "\nError! No User Login under specified information, please try again.\n\n";
                }
            }
            cout << inputUsername;
            // If successful, access the user
            accessingUserAccounts(users, inputUsername);
        }

        // Search accounts via account number, customer name, or phone num
        else if (choice == 3) {
            string input;
            while (true) {
                cout << "Enter an account number, customer Last name, phone number, or 'exit' to go back: ";
                cin >> input;
                cin.ignore(100, '\n');
        
                if (checkIfExit(input))
                    return;

                if (users->searchNode7(input)) { // if account number
                    cout << "\n";
                    temp = users->getUserNodeWithAccnt(input);
                    tempAccount = temp->getAccount(input);
                    tempAccount->getAccInfo();
                    break;
                }

                else if (users->searchNode4(input)) { // if phone number
                    temp = users->searchNodePhone(input);
                    temp->showAccounts();
                    cout << "\n";
                    break;
                }

                else if (users->searchNode6(input)) { // if last name
                    temp = users->searchNodeLast(input);
                    temp->showAccounts();
                    cout << "\n";
                    break;
                }

                else {
                    cout << "\nError! Nothing found using that information, please try again.\n\n";
                }
            }
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
        int choice = 0;
        while(choice != 4){
            choice = fourCaseMenu("1) Access Official Login", "2) Modify Account Types", "3) Change User Password", "4) Exit",
            "Accessing Officials", "Retrieving Bank Data", "Accessing Users", "Exiting...");

            //Access Officials
            if (choice == 1){

            }

            //Modify Account Data
            if (choice == 2){
                int choice2 = 0;
                cout << "Which value would you like to modify" << endl;
                while (choice2 != 3){
                    choice2 = threeCaseMenu("1) CD Accounts", "2) Custom Accounts", "3) Exit",
                    "Accessing Bank CD Account Data", "Accessing Bank Custom Account Data", "Exiting...");

                    //CD Account Variables
                    if (choice2 == 1){
                        int choice3 = 0;
                        while (choice3 != 4){
                            choice3 = fourCaseMenu("1) Fixed Term", "2) Interest Rate for CD", "3) Penalty Percentage", "4) Exit",
                            "Retrieving Data of Fixed Term", "Retrieving Data of CD Interest", "Retrieving Data of Penalty Percentage" , "Exiting...");

                            if(choice3 == 1){ //Term Length (Years)
                                while (true){
                                    cout << "Current Term Length: " << termLength << " years.\n"
                                    << "What would like the new length to be?" << endl;
                                    string newLength;
                                    cin >> newLength;
                                    cin.ignore(100, '\n');
                                    if (isNumber(newLength)){
                                        termLength = stoi(newLength);
                                        break;
                                    }
                                    cout << "Please enter a valid positive interger" << endl;
                                }
                            }
                            else if (choice3 == 2){ //CD Interest
                                while (true){
                                    cout << "Current CD Interest: " << interestCD << ".\n"
                                    << "What would like the new interest to be?\n"
                                    << "ex) .5 = 50% and 5 = 500%" << endl;;
                                    string newInt;
                                    cin >> newInt;
                                    cin.ignore(100, '\n');
                                    if (isNumber(newInt)){
                                        interestCD = stof(newInt);
                                        break;
                                    }
                                    cout << "Please enter a valid positive rational number" << endl;
                                }
                            }

                            else if (choice3 == 3){ //Penalty Percentage
                                while (true){
                                    cout << "Current Penalty Percentage: " << penaltyPercentage << ".\n"
                                    << "What would like the new percentage to be?\n"
                                    << "ex) .5 = 50% and 5 = 500%" << endl;;
                                    string newPen;
                                    cin >> newPen;
                                    cin.ignore(100, '\n');
                                    if (isNumber(newPen)){
                                        penaltyPercentage = stof(newPen);
                                        break;
                                    }
                                    cout << "Please enter a valid positive rational number" << endl;
                                }
                            }
                        }
                    }

                    //Custom Account Variables
                    else if (choice2 == 2){
                        int choice3 = 0;
                        while (choice3 != 4){
                            choice3 = fourCaseMenu("1) Interest Rate for Custom", "2) Monthly Fee", "3) Service Charge", "4) Exit",
                            "Retrieving Data of Custom Interest", "Retrieving Monthly Fee Data", "Retrieving Service Charge Data" , "Exiting...");

                            if(choice3 == 1){ //Custom Interest
                                while (true){
                                    cout << "Current Custom Interest: " << customInterest << ".\n"
                                    << "What would like the new interest to be?" << endl;
                                    string newInt;
                                    cin >> newInt;
                                    cin.ignore(100, '\n');
                                    if (isNumber(newInt)){
                                        customInterest = stof(newInt);
                                        break;
                                    }
                                    cout << "Please enter a valid positive rational number" << endl;
                                }
                            }

                            else if (choice3 == 2){ //Monthly Fee
                                while (true){
                                    cout << "Current Monthly Fee: " << monthlyFee << ".\n"
                                    << "What would like the new interest to be?" << endl;
                                    string newMF;
                                    cin >> newMF;
                                    cin.ignore(100, '\n');
                                    if (isNumber(newMF)){
                                        monthlyFee = stof(newMF);
                                        break;
                                    }
                                    cout << "Please enter a valid positive rational number" << endl;
                                }
                            }

                            else if (choice3 == 3){ //Service Charge
                                while (true){
                                    cout << "Current Service Charge: " << serviceCharge << ".\n"
                                    << "What would like the new interest to be?" << endl;
                                    string newSC;
                                    cin >> newSC;
                                    cin.ignore(100, '\n');
                                    if (isNumber(newSC)){
                                        serviceCharge = stof(newSC);
                                        break;
                                    }
                                    cout << "Please enter a valid positive rational number" << endl;
                                }
                            }
                        }
                    }
                }
            }

            //Change User Passwords
            else if (choice == 3){

            }
        }
    }

    else {
        cout << "\nError! No Admin Login under specified information, please try again.\n\n";
        adminLogin();
    }
}

/*********************************************************** 

Displays opening page to the user 

************************************************************/

void welcomeScreen(){
    BiTree users;
    /* Contains the starting menu options, and calls switch statment's corresponding functions */
    int choice;
    BankUser user1("Riley", "Grotenhuis", "8163928687", "1714 South Drumm Avenue", "rg1050", "123");

    Account a1("123", "123", 100, "123");
    Account a2("456", "123", 200, "456");
    Account a3("789", "123", 300, "789");

    user1.addAccount(a1);
    user1.addAccount(a2);
    user1.addAccount(a3);

    users.insertNode2(user1);

    officials.insertNode("official oPassword");
    
    while (true) {
        cout << "- - - - - - - - - - - - - - - - - - - -\n\n" 
        << "Welcome to the Bear Bank!\n\n"
        "- - - - - - - - - - - - - - - - - - - -\n\n"
        << "Please Enter a Number to Login:\n";
        choice = threeCaseMenu("1) User Account", "2) Bear Bank Official", "3) Bear Bank Admin",
        "Entering User Login", "Entering Official Login", "Entering Admin Login");

        if (choice == 1) {
            bankUserLogin(&users);
        }
        else if (choice == 2) {
            officialLogin(&users);
        }
        else {
            adminLogin();
        }
    }
}