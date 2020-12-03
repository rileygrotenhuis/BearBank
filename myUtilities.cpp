// global vars
// global admin
const string ADMIN_USER_NAME = "daelonKingore69";
const string ADMIN_PASSWORD = "kingoreRocks420";
// secret shut down code
const string SHUT_IT_DOWN = "SHUTITDOWN";


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
    cout << "At any time type 'exit' to cancel and quit.\n\n"
    << "- - - - - - - - - - - - - - - - - - - -\n";

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
        cout << "\nEnter phone number in form of (555)555-5555: ";
        cin >> phoneNumber;
        cin.ignore(100, '\n');
        
        if (checkIfExit(phoneNumber))
            return;

        else if (stringTest(phoneNumber, false, true) == false) {
            cout << "No letters or special characters allowed, please try again.\n";
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
        cout << "\nEnter address: ";
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
        cout << "\nWhat is the username for this account?: ";
        cin >> username;
        cin.ignore(100, '\n');
        cout << "\nWhat is the password for this account?: ";
        cin >> password;
        cin.ignore(100, '\n');

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
            cout << "You have successfully created a login at Bear Bank!\n"
            << "We are exited to work with you!\n\n";
            break;
        }
        else {
            cout << "\n- - - - - - - - - - - - - - - - - - - -\n\n"
            << "Restarting login creation...\n\n";
            addNewUserLogin();
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
        while (true) {
            if (yesOrNo == "Y" || yesOrNo == "y" || yesOrNo == "N" || yesOrNo == "n") 
                break;
            else
                cout << "\nPlease enter only 'y' or 'n' for yes or no.\n\n";
        }

        if (yesOrNo == "Y" || yesOrNo == "y") {
            cout << "\nClosing Login...\n\n";
            break;
            // Close user account; ADD LATER
        }
        else {
            cout << "\nCancelling...\n\n";
            break;
        }
    }
}

bool isNumber(string nums) {
    vector <char> numsV = lineToVector(nums);
    char numbers[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int i = 0, j = 0;

    for (i = 0; i < numsV.size(); i++) {
        for (j = 0; j < 10; j++) {
            if (numsV[i] == numbers[j])
                break;
        }
        if (j == 10)
            return false;
    }
    return true;
}

void accessingSpecificAccount(BankOfficial dummyOfficial, BankUser dummyUser) {
    string accntNumInput;

    while (true) { // while statement to be utilized later
        cout << "Enter your account number or 'exit' to go back: ";
        cin >> accntNumInput;
        cin.ignore(100, '\n');
        if (checkIfExit(accntNumInput))
            return;
        break;
    }

    /*for (loop through accounts) {
        if (accntNumInput != an account) {
            cout << "Incorrect Account Number retry or type 'exit' to go back."
            accessingSpecificAccount(dummyOfficial, dummyUser);
        }
        else
            break;
    }*/

    int choice = 0;
    while (choice != 3) {
        choice = threeCaseMenu("1) Deposit", "2) Withdraw", "3) Go Back", 
        "Entering Deposit", "Entering Withdraw", "Exiting");

        string password, depositAmmnt, withdrawAmmnt;
        
        if (choice == 1) {
            while (true) {
                cout << "User must re-enter password: ";
                cin >> password;
                cin.ignore(100, '\n');
                if (checkIfExit(password)) {
                    cout << "Cancelling...\n\n";
                    break;
                }
                else if (password == dummyUser.getPassword()) {
                    break;
                }
                else {
                    cout << "Error in password. Retry or type 'exit to go back.\n\n";
                    continue;
                }
            }

            while (true) {
                cout << "\nEnter the amount to be deposited or 'exit' to cancel: ";
                cin >> depositAmmnt;
                cin.ignore(100, '\n');
                if (checkIfExit(depositAmmnt)) {
                    cout << "Cancelling...\n\n";
                    break;
                }
                else if (isNumber(depositAmmnt)) {
                    depositAmmnt = stoi(depositAmmnt);
                    cout << "\nNew Balance: " << "INSERT FUNCTIONALITY LATER\n\n"
                    << "- - - - - - - - - - - - - - - - - - - -\n\n";
                    break;
                }
                else 
                    cout << "Please enter only a number\n\n";
            }
        }

        if (choice == 2) {
            while (true) {
                cout << "User must re-enter password: ";
                cin >> password;
                cin.ignore(100, '\n');
                if (checkIfExit(password)) {
                    cout << "Cancelling...\n\n";
                    break;
                }
                else if (password == dummyUser.getPassword()) {
                    break;
                }
                else {
                    cout << "Error in password. Retry or type 'exit to go back.\n\n";
                    continue;
                }
            }

            while (true) {
                cout << "\nEnter the amount to be withdrawn or 'exit' to cancel: ";
                cin >> withdrawAmmnt;
                cin.ignore(100, '\n');
                if (checkIfExit(withdrawAmmnt)) {
                    cout << "Cancelling...\n\n";
                    break;
                }
                else if (isNumber(withdrawAmmnt)) {
                    withdrawAmmnt = stoi(withdrawAmmnt);
                    cout << "\nNew Balance: " << "INSERT FUNCTIONALITY LATER\n\n"
                    << "- - - - - - - - - - - - - - - - - - - -\n\n";
                    break;
                }
                else 
                    cout << "\nPlease enter only a number\n\n";
            }
        }
    }
}

void createAccnt(BankOfficial dummyOfficial, BankUser dummyUser) {
    string password;
    
    while (true) { // while statement to be utilized later
        cout << "Enter User password or type 'exit' to go back: ";
        cin >> password;
        cin.ignore(100, '\n');
        if (checkIfExit(password))
            return;
        else if (password == dummyUser.getPassword())
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
        switch(intUserInput) {
            case 1:
                {
                    cout << "\nCreating Checking Account\n\n"
                    << "- - - - - - - - - - - - - - - - - - - -\n\n";
                    break;
                }
            case 2:
                {
                    cout << "\nCreating Savings Account\n\n"
                    << "- - - - - - - - - - - - - - - - - - - -\n\n";
                    break;
                }
            case 3:
                {
                    cout << "\nCreating CD\n\n"
                    << "- - - - - - - - - - - - - - - - - - - -\n\n";
                    break;
                }
            case 4:
                {
                    cout << "\nCreating Bear Bank Custom\n\n"
                    << "- - - - - - - - - - - - - - - - - - - -\n\n";
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

void closeAccnt(BankOfficial dummyOfficial, BankUser dummyUser) {
    string accntNum;

    while (true) { // while statement to be utilized later
        cout << "Enter Your Account Number or type 'exit' to go back: ";
        cin >> accntNum;
        cin.ignore(100, '\n');
        if (checkIfExit(accntNum))
            return;
        /*else if (accntNum == accoutNumber in linked list)
            break;
        else {
            cout << "\nIncorrect accntNum. Retry or type 'exit' to go back.\n\n"
            << "- - - - - - - - - - - - - - - - - - - -\n\n";
        }*/
        break;
    }

    string yesOrNo;
    while (true) {
        cout << "\n\nYou can choose where to send the money.\n"
        << "Are you sure you want to close this account?[y/n]: ";

        cin >> yesOrNo;
        cin.ignore(100, '\n');
        while (true) {
            if (yesOrNo == "Y" || yesOrNo == "y" || yesOrNo == "N" || yesOrNo == "n") 
                break;
            else
                cout << "\nPlease enter only 'y' or 'n' for yes or no.\n\n";
        }

        if (yesOrNo == "Y" || yesOrNo == "y") {
            cout << "Closing Account. Were would you like the money?\n";
            int choice = 0;
            choice = fourCaseMenu("1) Cash", "2) Checkings Account", 
                "3) Savings Account", "4) Bear Bank Custom", "Withdrawing...", 
                "Depositing into Checkings", "Depositing into Savings", "Depositing into Custom");
            
            break;
        }
        else {
            cout << "\n- - - - - - - - - - - - - - - - - - - -\n\n"
            << "Cancelling...\n\n";
            break;
        }
    }
}

void accessingUserAccounts(BankOfficial dummyOfficial, BankUser dummyUser) {
    int choice = 0;

    while (choice != 4) {
        cout << "Accessing User Accounts\n\n"
        << "- - - - - - - - - - - - - - - - - - - -\n\n";
        choice = fourCaseMenu("1) Access a Specific Account", "2) Create a Specific Account", 
        "3) Close a Specific Account", "4) Exit", "Accessing a Specific Account", 
        "Creating a Specific Account", "Closing a Specific Account", "Exiting");

        if (choice == 1) {
            accessingSpecificAccount(dummyOfficial, dummyUser);
        }

        if (choice == 2) {
            createAccnt(dummyOfficial, dummyUser);
        }

        if (choice == 3) {
            closeAccnt(dummyOfficial, dummyUser);
        }
    }
}

void officialLogin(BankOfficial dummyOfficial, BankUser dummyUser) {
    /* Less finished than User, but very close. Needs implementation of the switch statement
    to corresponding functions. Contains the code to get username and password of official. Then
    displays the menu options. */
    string userName, password;
    int choice = 0;
    
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

        // Check if userName and password is correct by looping through the BST of officials (add later)
        if (dummyOfficial.getUsername() == userName && dummyOfficial.getPassword() == password) {
            cout << "\nSuccessful Login!\n\n";
            break;
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
                addNewUserLogin();
            }
            else if (choice == 2) {
                closeUserLogin(dummyOfficial, dummyUser);
            }
        }

        // Accessing login
        else if (choice == 2) {
            while (true) {
                // Retrive username and password and test them
                cout << "User please enter your username and password.\n"
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
                }
            }
            // If successful, access the user
            accessingUserAccounts(dummyOfficial, dummyUser);
        }

        // Search accounts via account number, customer name, or phone num
        else if (choice == 3) {
            string input;
            while (true) {
                // Retrive username and password and test them
                cout << "Enter an account number, customer name, phone number, or 'exit' to go back: ";
                cin >> input;
                cin.ignore(100, '\n');
        
                if (checkIfExit(input))
                    return;

                // change later when i can loop through stuff
                else if (input == dummyUser.getFirstName() || input == dummyUser.getLastName()
                    || input == dummyUser.getPhoneNumber()) { // DON'T forget account num later
                    // serach for account num(s) linked and show (maybe add depositing/withdraw later)
                    }

                else {
                    cout << "\nError! Nothing found using that information, please try again.\n\n";
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