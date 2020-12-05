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
        float pPercent = 0;
        float accumInt = 0;
        float mFee = 0;
        float pFee = 0;
        bool closeFlag = false;
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
            interestRate = 0;
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
            closeFlag = false;
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
        Account(string uid, string pWord, float initBal, float intRate, float penaltyPercent, string accID, string cDate) {
            uniqueID = uid;
            password = pWord;
            balance = initBal;
            closeFlag = false;
            pPercent = penaltyPercent;
            interestRate = intRate;
            accountID = "CD" + accID;
            lastAccess = getTime();
            openDate = getTime();
            closeDate = cDate;
        }

        //Constructor for Exiting CD Account
        Account(string uid, string pWord, float initBal, float intRate, float aInt, float penaltyPercent, string accID, string cDate, string oDate, string lastAcc, bool cFlag) {
            accumInt = aInt;
            uniqueID = uid;
            password = pWord;
            balance = initBal;
            interestRate = intRate;
            pPercent = penaltyPercent;
            closeFlag = cFlag;
            accountID = "CD" + accID;
            string newAccess = getTime();
            accumInt += calcInt(lastAcc, newAccess);
            lastAccess = getTime();
            openDate = oDate;
            closeDate = cDate;
            if (checkEx()) {
                removeExInt();
                closeFlag = true;
            }
        }

        /*  ----------------------------------------------------------
                        Custom Account Constructors
            ---------------------------------------------------------- */

        //Constructor for New BBC Account
        Account(string uid, string pWord, float initBal, float intRate, float monthlyFee, float penaltyFee, string accID) {
            uniqueID = uid;
            password = pWord;
            balance = initBal;
            interestRate = intRate;
            closeFlag = false;
            accountID = "BBC" + accID;
            mFee = monthlyFee;
            pFee = penaltyFee;
            lastAccess = getTime();
            openDate = getTime();
        }

        //Constructor for Existing BBC Account
        Account(string uid, string pWord, float initBal, float intRate, float aInt, float monthlyFee, float penaltyFee, string accID, string oDate, string lastAcc, bool cFlag) {
            accumInt = aInt;
            uniqueID = uid;
            password = pWord;
            balance = initBal;
            interestRate = intRate;
            closeFlag = cFlag;
            mFee = monthlyFee;
            pFee = penaltyFee;
            accountID = "BBC" + accID;
            string newAccess = getTime();
            accumInt += calcInt(lastAcc, newAccess);
            calcMonthFee(lastAcc, newAccess);
            lastAccess = getTime();
            openDate = oDate;
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

        void setPassword(string x) {
            password = x;
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

                string currentTime = timeAndDate();
                string roundNearist = to_string(depositAmnt).substr(0,to_string(depositAmnt).find(".")+3);
                string transactionData = "Deposit of: $" + roundNearist + "\nOn: " + currentTime;
                addTransactionHistory(transactionData);
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

            if(getBalance() < 0){
                cout << "- - - - - - - - - - - - - - - - - - - -\n"
                << "Cannot withdraw if bank account is less than zero\n"
                << "Canceling Transaction...\n"
                << "- - - - - - - - - - - - - - - - - - - -\n";
            }

            else{
                //Enters deposit mode and asks for user password
                cout << "- - - - - - - - - - - - - - - - - - - -\n"
                << "ENTERING WITHDRAW MODE\n"
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
                    if (pFee > 0){
                        cout << "Notice!!! $" << pFee << " Service fee to account due to withdraw.\n\n";
                        balance -= pFee;
                    }
                    cout << "Password Success!\n"
                    << "Withdrawing: $" << withdrawAmnt << "\n"
                    << "Total Balance is now $" << balance << "\n"
                    << "- - - - - - - - - - - - - - - - - - - -\n\n";

                    string currentTime = timeAndDate();
                    string roundNearist = to_string(withdrawAmnt).substr(0, to_string(withdrawAmnt).find(".")+3);
                    string transactionData = "Withdraw of: $" + roundNearist + "\nOn: " + currentTime;
                    addTransactionHistory(transactionData);
                }

                //If password is incorrect after 3 consecutive tries
                else if(passAttempts == 0){
                    cout << "ATTENTION! Password attempts has reached\n"
                    << "minimum value. Exiting Withdraw Mode...\n"
                    << "- - - - - - - - - - - - - - - - - - - -\n\n";
                }
            }
        }

        /*  ----------------------------------------------------------
                Calculate Interest or Monthly Fee Over Given Time
            ---------------------------------------------------------- */

        //This function takes both last access and current access and determines the amount of interest gained over said time.
        float calcInt(string prevAcc, string newAcc){
            vector <string> prevDate = parseDate(prevAcc);
            vector <string> newDate = stringToVector(newAcc);

            int difDays = daysPast(prevDate, newDate);
            if (!closeFlag){
                return (balance * (interestRate * difDays));
            }
            return 0;
        }

        void calcMonthFee(string prevAcc, string newAcc){
            vector <string> prevDate = parseDate(prevAcc);
            vector <string> nowDate = stringToVector(newAcc);
            vector <string> difDate;

            int prevMonth = monthsPast(prevDate);
            int difDays = daysPast(prevDate, nowDate);
            int totalMonths = difDays + stoi(prevDate[0]);
            difDate.push_back(to_string(totalMonths));
            difDate.push_back(prevDate[1]);
            int difMonths = monthsPast(difDate);
            int totalDif = difMonths - prevMonth;
            for (int i = 0; i < totalDif; i++){
                balance -= mFee;
            }
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

        void forceClose(){
            accumInt = 0;
            string nowTime = getTime();
            vector <string> nowDate = stringToVector(nowTime);
            vector <string> cDate = parseDate(closeDate);

            int daysLeft = daysPast(nowDate, cDate);
            balance -= (balance * (pPercent * daysLeft));
        }

        /*  ----------------------------------------------------------
                    Functions used for Transaction History
            ---------------------------------------------------------- */

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
