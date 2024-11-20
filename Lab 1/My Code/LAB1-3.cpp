#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <fstream>

using namespace std;

int main() {
    fstream myFile;
    string tmpWord;
    int i;
    myFile.open("Gettysburg.txt");
    if(myFile.is_open()) {
        while(myFile >> tmpWord) {
            for(i=0; i<tmpWord.length(); i++) {
                if(isalnum(tmpWord[i]) == 0) {
                    tmpWord.erase(i, 1);
                    i--;
                    continue;
                } 
                tmpWord[i] = toupper(tmpWord[i]);
            }
            if(tmpWord.length() >= 10) {
                cout << tmpWord << endl;
            }
        }
    }
    return 0;
}