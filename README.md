# Bear Bank - Data Structures (CSC 232) Final Project

Bear Bank is a terminal based banking management software system that could be utilized in a modern day bank.
<br>
This software allows you to login as a Bank User where you can:

-   View your account details (balance, statements, etc.)
-   Make deposits/withdraws
-   Change any of your account details

This software also allows you to login as a Bank Official where you can:

-   Approve transactions that Bank Users are wanting to make
-   Change details of any one person's account

You can also access the System Administrator portal where you can alter important information such as interest rates.

## Requirements

---

To run this project you will need the latest version of C++ installed onto your computer. <br>
Most Computers come with C++ already installed; however, if yours for some reason does not, you can use this [link](https://docs.microsoft.com/en-us/cpp/build/vscpp-step-0-installation?view=msvc-160) to learn how to use C++ on your computer.

## Setup

---

You can utilize this repository by one of two ways:

1. Downloading the source code directly from this [link](https://github.com/rileygrotenhuis/BearBank/archive/refs/heads/master.zip)

2. Cloning the repository using your preferred Command Line Interface and running the following command:
    ```bash
    git clone https://github.com/rileygrotenhuis/BearBank.git
    ```

> Note: Whether you chose to download, or clone, this repository, it is preffered that you do so inside of your `documents/` directory.

> Note: If you download the source code directly from GitHub into a `.zip` file, you will need to rename the folder from `BearBank-master` to just `BearBank`.

## Usage

---

1. Open your preferred Command Line Interface (Terminal, Command Prompt, iTask2, PowerShell, etc.) and change your directory until you are in the project folder

    ```bash
    cd documents
    cd BearBank
    ```

2. Once you are in the project's folder, you will need to run the following commands to build the project and then eventually run it.

    ### Windows

    ```bash
    g++ ProjectMainFunctions.cpp -o ProjectMainFunctions
    ./ProjectMainFunctions
    ```

    ### MacOS/Linux

    ```bash
    clang++ ProjectMainFunctions.cpp -o ProjectMainFunctions
    ./ProjectMainFunctions
    ```

> At this point, the project will be running in your Command Line Interface and you can follow the instructions on the screen to utilize this program.

## Files & Directories

---

-   _accounts/_
    -   `Account.h`
-   _dataStructures/_
    -   `LinkedList.h`
    -   `OfficialBST.h`
    -   `Queue.h`
    -   `Stack.h`
    -   `UserBST.h`
-   _users/_
    -   `BankOfficial.h`
    -   `BankUser.h`
-   _utilities/_
    -   `ceaserCypher.h`
    -   `stringToVector.h`
    -   `time.h`
-   `Documentation.docx`
-   `myUtilities.cpp`
-   `ProjectMainFunctions.cpp`
-   `README.md`

## Notes

---

> This project recieved a 100% score upon submission by our group.

## Contributors

---

-   ### Ashton Barnwell (Barnwell247@live.missouristate.edu)

-   ### Riley Grotenhuis (rg1050@live.missouristate.edu)

-   ### Daelon Kingore (Daelon022@live.missouristate.edu)
