#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int n = 1;
    int sum = 0;

    while (n<=100) {
        sum += n;
        n++;
    }

    cout << "sum: " << sum << endl;
    return 0;
}