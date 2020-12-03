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
#include "dataStructures/OfficialBST.h"
#include "dataStructures/UserBST.h"
#include "utilities/ceaserCypher.h"
#include "utilities/stringToVector.h"
#include "utilities/time.h"
#include "myUtilities.cpp"

using namespace std;

// Individual client structure
struct client{
    // Account accounts; // to be used later
    BankUser user;

    client() {
    }
};

int main() {
    /* controls the program */
    BankUser dummyUser;
    BankOfficial dummyOfficial;
    LinkedList officialList;
    LinkedList userList;

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