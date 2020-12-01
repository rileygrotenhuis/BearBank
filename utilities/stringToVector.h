#ifndef STRINGTOVECTOR_H
#define STRINGTOVECTOR_H
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector <string> stringToVector(string line){
    vector <string> lineList;
    string buffer;
    stringstream ss(line);

    while (getline(ss, buffer, ' ')){
        lineList.push_back(buffer);
    }
    return lineList;
}
#endif