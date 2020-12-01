#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include "../utilities/stringToVector.h"
#include "../utilities/time.h"
#include "../dataStructures/Queue.h"
using namespace std;

class Account {

    private:
        string accountID;
        string uniqueID;
        string password;
        string openDate;
        string lastAccess;
        string closeDate;
        float balance;
        float interestRate;
        float accumInt;
        bool closeFlag;
        Queue<string> transactionHistory;

    public:

        /* This is a deafult constructor. This is practically usless and is only helpful in the LinkedList.h file */
        Account() {
            
        };

        /*  ----------------------------------------------------------
                        Checking Account Constructors
            ---------------------------------------------------------- */

        //Constructor for New Checking Account
        Account(string uid, string pWord, float initBal, string accID) {
            uniqueID = uid;
            password = pWord;
            balance = initBal;
            accountID = "C" + accID;
            lastAccess = getTime();
            openDate = getTime();
        }

        //Constructor for Existing Checking Account
        Account(string uid, string pWord, float initBal, string accID, string oDate, string lastAcc, bool cFlag) {
            uniqueID = uid;
            password = pWord;
            balance = initBal;
            closeFlag = cFlag;
            accountID = "C" + accID;
            interestRate = 0;
            lastAccess = getTime();
            openDate = oDate;
        }

        /*  ----------------------------------------------------------
                        Savings Account Constructors
            ---------------------------------------------------------- */

        //Constructor for New Savings Account
        Account(string uid, string pWord, float initBal, float intRate, string accID) {
            uniqueID = uid;
            password = pWord;
            balance = initBal;
            interestRate = intRate;
            accountID = "S" + accID;
            lastAccess = getTime();
            openDate = getTime();
        }

        //Constructor for Existing Savings Account
        Account(string uid, string pWord, float initBal, float intRate, float aInt, string accID, string oDate, string lastAcc, bool cFlag) {
            accumInt = aInt;
            uniqueID = uid;
            password = pWord;
            balance = initBal;
            interestRate = intRate;
            closeFlag = cFlag;
            accountID = "S" + accID;
            string newAccess = getTime();
            accumInt += calcInt(lastAcc, newAccess);
            lastAccess = getTime();
            openDate = oDate;
        }

            /*  ----------------------------------------------------------
                        CD Account Constructors
            ---------------------------------------------------------- */

        //Constructor for New CD Account
        Account(string uid, string pWord, float initBal, float intRate, string accID, string cDate) {
            uniqueID = uid;
            password = pWord;
            balance = initBal;
            interestRate = intRate;
            accountID = "CD" + accID;
            lastAccess = getTime();
            openDate = getTime();
        }

        //Constructor for Exiting CD Account
        Account(string uid, string pWord, float initBal, float intRate, float aInt, string accID, string cDate, string oDate, string lastAcc, bool cFlag) {
            accumInt = aInt;
            uniqueID = uid;
            password = pWord;
            balance = initBal;
            interestRate = intRate;
            closeFlag = cFlag;
            accountID = "CD" + accID;
            string newAccess = getTime();
            accumInt += calcInt(lastAcc, newAccess);
            lastAccess = getTime();
            openDate = oDate;
            closeDate = cDate;
        }

        /*  ----------------------------------------------------------
                        Custom Account Constructors
            ---------------------------------------------------------- */

        //Constructor for New BBC Account
        Account(string uid, string pWord, float initBal, float intRate, string accID, string cDate, bool customFlag) {
            uniqueID = uid;
            password = pWord;
            balance = initBal;
            interestRate = intRate;
            accountID = "BBC" + accID;
            lastAccess = getTime();
            openDate = getTime();
        }

        //Constructor for Existing BBC Account
        Account(string uid, string pWord, float initBal, float intRate, float aInt, string accID, string cDate, bool customFlag, string oDate, string lastAcc, bool cFlag) {
            accumInt = aInt;
            uniqueID = uid;
            password = pWord;
            balance = initBal;
            interestRate = intRate;
            closeFlag = cFlag;
            accountID = "BBC" + accID;
            string newAccess = getTime();
            accumInt += calcInt(lastAcc, newAccess);
            lastAccess = getTime();
            openDate = oDate;
            closeDate = cDate;
        }

        /*  ----------------------------------------------------------
                        Simple Get Functions
            ---------------------------------------------------------- */

        string getAID(){
            return accountID;
        }

        float getInterest(){
            return interestRate;
        }

        float getBalance(){
            return balance + accumInt;
        }

        string getOD(){
            return openDate;
        }

        string getCD(){
            return closeDate;
        }

        bool getCFlag(){
            return closeFlag;
        }

        void setCFlag(bool value){
            closeFlag = value;
        }

        void setBal(float value){
            balance = value;
        }

        void setAccInt(float value){
            accumInt = value;
        }



        void getAccInfo(){
            //test.append("Open Date: " + getOD() + "\n");
            //test.append("Close Date: " + getCD() + "\n");*/

            cout << "- - - - - - - - - - - - - - - - - - - -\n"
            << "Account Info - \n"
            << "Account ID: " << accountID << "\n"
            << "Interest Rate: " << interestRate << "\n"
            << "Balance: $" << getBalance() << "\n"
            << "- - - - - - - - - - - - - - - - - - - -\n" << endl;
        }

        /*  ----------------------------------------------------------
                        Deposit & Withdraw Functions
            ---------------------------------------------------------- */

        // A virtual function that accepts an argument for the amount of the deposit.
        virtual void deposit(double depositAmnt) {
            int passAttempts = 2;
            string input;

            //Enters deposit mode and asks for user password
            cout << "- - - - - - - - - - - - - - - - - - - -\n"
            << "ENTERING DEPOSIT MODE\n"
            << "*** Please enter user password ***\n"
            << "(You have " << passAttempts+1 << " attempts remaining)\n\n"
            << "Password: ";

            cin >> input;

            cout << "- - - - - - - - - - - - - - - - - - - -\n";

            //Give the user 3 chances to input their password correctly
            while(input != password && passAttempts != 0){
                passAttempts--;
                cout <<  "Invalid password try again!\n"
                << "(You have " << passAttempts+1 << " attempts remaining)\n\n"
                << "Password: ";

                cin.ignore();
                cin >> input;

                cout << "- - - - - - - - - - - - - - - - - - - -\n";
            }

            //If the password is correct
            if (input == password){
                balance += depositAmnt;
                cout << "Password Success!\n"
                << "Depositing: $" << depositAmnt << "\n"
                << "Total Balance is now $" << balance << "\n"
                << "- - - - - - - - - - - - - - - - - - - -\n\n";
            }

            //If password is incorrect after 3 consecutive tries
            else if(passAttempts == 0){
                cout << "ATTENTION! Password attempts has reached\n"
                << "minimum value. Exiting Deposit Mode...\n"
                << "- - - - - - - - - - - - - - - - - - - -\n\n";
            }
        }

        // A virtual function that accepts an argument for the amount of the withdrawal.
        virtual void withdraw(double withdrawAmnt) {
            int passAttempts = 2;
            string input;

            //Enters deposit mode and asks for user password
            cout << "- - - - - - - - - - - - - - - - - - - -\n"
            << "ENTERING WITHDRAWL MODE\n"
            << "*** Please enter user password ***\n"
            << "(You have " << passAttempts+1 << " attempts remaining)\n\n"
            << "Password: ";

            cin >> input;

            cout << "- - - - - - - - - - - - - - - - - - - -\n";

            //Give the user 3 chances to input their password correctly
            while(input != password && passAttempts != 0){
                passAttempts--;
                cout <<  "Invalid password try again!\n"
                << "(You have " << passAttempts+1 << " attempts remaining)\n\n"
                << "Password: ";

                cin.ignore();
                cin >> input;

                cout << "- - - - - - - - - - - - - - - - - - - -\n";
            }

            //If the password is correct
            if (input == password){
                balance -= withdrawAmnt;
                cout << "Password Success!\n"
                << "Depositing: $" << withdrawAmnt << "\n"
                << "Total Balance is now $" << balance << "\n"
                << "- - - - - - - - - - - - - - - - - - - -\n\n";
            }

            //If password is incorrect after 3 consecutive tries
            else if(passAttempts == 0){
                cout << "ATTENTION! Password attempts has reached\n"
                << "minimum value. Exiting Deposit Mode...\n"
                << "- - - - - - - - - - - - - - - - - - - -\n\n";
            }
        }

        /*  ----------------------------------------------------------
                    Calculate Interest Over Given Time
            ---------------------------------------------------------- */

        //This function takes both last access and current access and determines the amount of interest gained over said time.
        float calcInt(string prevAcc, string newAcc){
            vector <string> prevDate = parseDate(prevAcc);
            vector <string> newDate = stringToVector(newAcc);

            int difDays;

            //If account is closed no interest will be calculated
            if(!closeFlag){
                //Leap year
                if (stoi(prevDate[1]) % 4 == 0 && stoi(prevDate[1]) % 100 != 0) {
                    if(stoi(prevDate[0]) > stoi(newDate[0])){
                        difDays = (366 - stoi(prevDate[0])) + stoi(newDate[0]);

                        for (int i = stoi(prevDate[1]); i < (stoi(newDate[1])-1); i++){
                            if (i % 4 == 0 && i % 100 != 0) {
                                difDays += 366;
                            }

                            else if (i % 4 == 0 && i % 100 == 0 && i % 400 == 0) {
                                difDays += 366;
                            }

                            else {
                                difDays += 365;
                            }
                        }
                    }

                    else{
                        difDays = stoi(newDate[0]) - stoi(prevDate[0]);

                        for (int i = stoi(prevDate[1]); i < stoi(newDate[1]); i++){
                            if (i % 4 == 0 && i % 100 != 0) {
                                difDays += 366;
                            }

                            else if (i % 4 == 0 && i % 100 == 0 && i % 400 == 0) {
                                difDays += 366;
                            }

                            else {
                                difDays += 365;
                            }
                        }
                    }
                }

                //Leap year
                else if (stoi(prevDate[1]) % 4 == 0 && stoi(prevDate[1]) % 100 == 0 && stoi(prevDate[1]) % 400 == 0) {
                    if(stoi(prevDate[0]) > stoi(newDate[0])){
                        difDays = (366 - stoi(prevDate[0])) + stoi(newDate[0]);

                        for (int i = stoi(prevDate[1]); i < (stoi(newDate[1])-1); i++){
                            if (i % 4 == 0 && i % 100 != 0) {
                                difDays += 366;
                            }

                            else if (i % 4 == 0 && i % 100 == 0 && i % 400 == 0) {
                                difDays += 366;
                            }

                            else {
                                difDays += 365;
                            }
                        }
                    }

                    else{
                        difDays = stoi(newDate[0]) - stoi(prevDate[0]);

                        for (int i = stoi(prevDate[1]); i < stoi(newDate[1]); i++){
                            if (i % 4 == 0 && i % 100 != 0) {
                                difDays += 366;
                            }

                            else if (i % 4 == 0 && i % 100 == 0 && i % 400 == 0) {
                                difDays += 366;
                            }

                            else {
                                difDays += 365;
                            }
                        }
                    }
                }

                //Not a leap year
                else {
                    if(stoi(prevDate[0]) > stoi(newDate[0])){
                        difDays = (365 - stoi(prevDate[0])) + stoi(newDate[0]);

                        for (int i = stoi(prevDate[1]); i < (stoi(newDate[1])-1); i++){
                            if (i % 4 == 0 && i % 100 != 0) {
                                difDays += 366;
                            }

                            else if (i % 4 == 0 && i % 100 == 0 && i % 400 == 0) {
                                difDays += 366;
                            }

                            else {
                                difDays += 365;
                            }
                        }
                    }

                    else{
                        difDays = stoi(newDate[0]) - stoi(prevDate[0]);

                        for (int i = stoi(prevDate[1]); i < stoi(newDate[1]); i++){
                            if (i % 4 == 0 && i % 100 != 0) {
                                difDays += 366;
                            }

                            else if (i % 4 == 0 && i % 100 == 0 && i % 400 == 0) {
                                difDays += 366;
                            }

                            else {
                                difDays += 365;
                            }
                        }
                    }
                }

                return (balance * (interestRate * difDays));
            }
            return 0;
        }

        /*  ----------------------------------------------------------
                    Functions used for Closing a CD Account
            ---------------------------------------------------------- */

        //Checks for live date past expiration date.
        bool checkEx(){
            string newAccess = getTime();
            vector <string> liveTime = stringToVector(newAccess);
            vector <string> closeTime = parseDate(closeDate);

            //If live year is past expiration year by more than 1 than at least 365 days has past
            if(stoi(liveTime[1]) > stoi(closeTime[1]) + 1){
                return true;
            }

            //If live year is only one year more than more tests are required
            else if(stoi(liveTime[1]) >= stoi(closeTime[1])){

                //If the day of live time is greater or equal at least 365 days has past
                if(stoi(liveTime[0]) >= stoi(closeTime[0])){
                    return true;
                }

                return false;

            }

            return false;

        }

        //This function is used to remove excess interest gain on an account when it has passed it's expiration date
        void removeExInt(){
            float exInt = calcInt(closeDate, lastAccess);
            accumInt -= exInt;

            cout << "Account closed excess interest of amount: " << exInt << " has been removed from the account." << endl;
        }

    /* This function gets all of the transaction history and returns it all in a vector of strings */
    vector<string> getTransactionHistory() {
        return transactionHistory.getAll();
    }

    /* This function adds a new string, x, into the transaction history Queue by using the Queue operations */
    void addTransactionHistory(string x) {
        transactionHistory.enqueue(x);
    }

};
#endif