#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int main(){
    string input;
    int i;
    int alpha = 0;
    int nonAlpha = 0;
    cout << "Type input: ";
    getline(cin,input);
    for (i=0; i<input.size();i++) {
        if (isalnum(input[i])) {
            alpha++;
        } else if (!isalnum(input[i]) && input[i] != ' ') {
            nonAlpha++;
        }
    }
    cout << "Alphanumerics: " << alpha; 
    cout << "\nNon-alphanumerics: " << nonAlpha; 
    cout << "\n";
}
