#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <fstream>
#include <iomanip>
#include <ios>

using namespace std;

int main() {
    string forward = "0123456789";
    string backwards = "9876543210";
    for(int i=14; i<24; i=i+2) {
        cout << setw(i); cout << forward; cout << setw(i+6); cout << backwards << endl;
    }
}