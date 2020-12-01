#ifndef CEASERCYPHER_H
#define CEASERCYPHER_H
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

string cCypher(string info, int key){
        for (int c = 0; c < info.size(); c++){
            int newChar = int(info[c]);
            if( newChar + key > 126){
                newChar = ((newChar + key) - 126) + 31;
            }
            else{
                newChar += key;
            }
            info[c] = (char)newChar;
        }
    return info;
}

string Decrypter(string info, int key){
    for (int c = 0; c < info.size(); c++){
            int newChar = int(info[c]);
            if( newChar - key < 32){
                newChar = ((newChar - key) - 32 + 3 * 95) % 95 + 32;
            }
            else{
                newChar -= key;
            }
            info[c] = (char)newChar;
        }
    return info;
}
#endif