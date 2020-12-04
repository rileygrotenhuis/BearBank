#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>
#include "stringToVector.h"
using namespace std;

string timeAndDate() {
    string timeAndDate;
    auto time = chrono::system_clock::now();
    time_t end_time = chrono::system_clock::to_time_t(time);
    timeAndDate = ctime(&end_time);
    return timeAndDate;
}

string removeWhiteSpace(string x) {
    char lastChar;
    for (int i = 0; i < x.length(); i++) {
        if (x[i] == lastChar && x[i] == ' ') {
            x = x.erase(i, 1);
        }
        lastChar = x[i];
    }
    return x;
}

string getTime() {
    /* Gets the time and date from the computer and put it into a vector, erases
    useless parts, turns the date into numbers and put into date vector.
    Returns the date vector.

    Contains: use of ctime and chrono, if and if else statements, vectors */

    string timeAndDate, strMonth, date;
    int month, day, year;

    // gets the date and time information from computer
    auto time = chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(time);
    timeAndDate = std::ctime(&end_time);

    timeAndDate = removeWhiteSpace(timeAndDate);

    // puts that info into a vector using stringToVector
    vector <string> vectorTime = stringToVector(timeAndDate);

    // get rid of the useless parts
    vectorTime.erase(vectorTime.begin());
    vectorTime.erase(vectorTime.begin() + 2);

    // turns numbers into ints (except for strMonth)
    strMonth = vectorTime[0];
    day = stoi(vectorTime[1].substr(0, 2));
    year = stoi(vectorTime[2].substr(0, 4));

    // if statements determining the number value correlating to the month name
    string months[] =  { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
        "Aug", "Sep", "Oct", "Nov", "Dec" };

    for (int i = 0; i <= 12; i++) {
        if (strMonth == months[i]) {
            month = i + 1;
        }
    }

    int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysPerMonthLeap[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (year % 4 == 0 && year % 100 != 0) {
        while (month-- > 1) {
            day = day + daysPerMonthLeap[month - 1];
        }
    }

    else if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0) {
        while (month-- > 1) {
            day = day + daysPerMonthLeap[month - 1];
        }
    }

    else {
        while (month-- > 1) {
            day = day + daysPerMonth[month - 1];
        }
    }

    // puts the final info into date string
    date = to_string(day) + " " + to_string(year);

    return date;
}

vector <string> parseDate(string date){
    vector <string> vecDate;

    if (date.length() == 7){
        vecDate.push_back(date.substr(0, 3));
        vecDate.push_back(date.substr(3));
    }

    else if (date.length() == 6){
        vecDate.push_back(date.substr(0, 2));
        vecDate.push_back(date.substr(2));
    }

    else{
        vecDate.push_back(date.substr(0, 1));
        vecDate.push_back(date.substr(1));
    }
    return vecDate;
}

bool isLeapYear(int year){
    if (year % 4 == 0 && year % 100 != 0) {
       return true;
    }

    else if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0) {
        return true;
    }

    else {
        return false;
    }
}

int monthsPast(vector <string> prevDate){
            int year = stoi(prevDate[1]);
            int day = stoi(prevDate[0]);
            bool leapYear = isLeapYear(year);
            int yPast = 0;
            while(true){

                //Jan
                if((day - 31) <= 0){
                    return yPast;
                }
                else{
                    yPast++;
                    day -= 31;
                }

                //Feb
                if(leapYear){
                    if((day - 29) <= 0){
                        return yPast;
                    }
                    else{
                        yPast++;
                        day -= 29;
                    }
                }
                else{
                    if((day - 28) <= 0){
                        return yPast;
                    }
                    else{
                        yPast++;
                        day -= 28;
                    }
                }

                //Mar
                if((day - 31) <= 0){
                    return yPast;
                }
                else{
                    yPast++;
                    day -= 31;
                }

                //Apr
                if((day - 30) <= 0){
                    return yPast;
                }
                else{
                    yPast++;
                    day -= 30;
                }

                //May
                if((day - 31) <= 0){
                    return yPast;
                }
                else{
                    yPast++;
                    day -= 31;
                }

                //June
                if((day - 30) <= 0){
                    return yPast;
                }
                else{
                    yPast++;
                    day -= 30;
                }

                //July
                if((day - 31) <= 0){
                    return yPast;
                }
                else{
                    yPast++;
                    day -= 31;
                }

                //Aug
                if((day - 31) <= 0){
                    return yPast;
                }
                else{
                    yPast++;
                    day -= 31;
                }

                //Sep
                if((day - 30) <= 0){
                    return yPast;
                }
                else{
                    yPast++;
                    day -= 30;
                }

                //Oct
                if((day - 31) <= 0){
                    return yPast;
                }
                else{
                    yPast++;
                    day -= 31;
                }

                //Nov
                if((day - 30) <= 0){
                    return yPast;
                }
                else{
                    yPast++;
                    day -= 30;
                }

                //Dec
                if((day - 31) <= 0){
                    return yPast;
                }
                else{
                    yPast++;
                    day -= 31;
                }
            }

            leapYear = isLeapYear(year+1);

        }

int daysPast(vector <string> prevDate, vector <string> newDate){
        int difDays;

        //If account is closed no interest will be calculated
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
        return difDays;
    }

#endif
