#include <iostream>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <iomanip>

#include "poly.h"

using namespace coen79_lab4;
using namespace std;

void printTest() {
    polynomial p1, p2;
    cout << "Testing Printing Function" << endl;
    cout << p1 << endl;
    p1.assign_coef(5, 2); 
    cout << p1 << endl;
    p1.assign_coef(3, 0);
    p1.assign_coef(-4, 1);
    cout << p1 << endl;
    p1.add_to_coef(8,1);
    cout << p1 << endl;
    p1.assign_coef(-2.5, 3);
    cout << p1 << endl;
    p2.assign_coef(-7.2, 0);
    cout << p2 << endl;
    p2.assign_coef(-3,5);
    cout << p2 << endl;
}



int main() {
    printTest();
    polynomial p1, p2(5.2, 0), p3(3.7, 29), p4(4.6, 13);
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << p4 << endl;
    p1.clear();
    p2.clear();
    p1.assign_coef(5,29);
    p1.assign_coef(6,28);
    p1.assign_coef(7,17);
    p1.assign_coef(8,1);
    p1.assign_coef(9,0);
    cout << p1 << endl;
    cout << "Degree: " << p1.degree() << endl;
    p2.assign_coef(-2,29);
    p2.assign_coef(-2.5,28);
    p2.assign_coef(-3,17);
    p2.assign_coef(-3.5,1);
    p2.assign_coef(-4,0);
    cout << p2 << endl;
    cout << "Add To Tests" << endl;
    p1.add_to_coef(-12,0);
    p2.add_to_coef(4,29);
    cout << p1 << endl;
    cout << p2 << endl;
    cout << "Next Term Tests" << endl;
    cout << "Next term after 29 is " << p1.next_term(29) << endl;
    cout << "Next term after 20 is " << p1.next_term(20) << endl;
    cout << "Term before 20 is " << p1.previous_term(20) << endl;
    cout << "Next term after 5 is " << p1.next_term(5) << endl;
    cout << "Term before 5 is " << p1.previous_term(5) << endl;
    cout << "Term before 0 is " << p1.previous_term(0) << endl;
    cout << "Is Zero Test" << endl;
    cout << p1 << " " << ((p1.is_zero()) ? "is zero." : "is not zero.") << endl;
    p1.clear();
    cout << p1 << " " << ((p1.is_zero()) ? "is zero." : "is not zero.") << endl;
    cout << "Math Tests" << endl;
    p1.clear();
    p1.assign_coef(3,0);
    p1.assign_coef(4,1);
    p1.assign_coef(5,2);
    cout << p1 << endl;
    cout << "If x=4, f(x)=" << p1.eval(4) << endl;
    cout << "If x=2.5, f(x)=" << p1(2.5) << endl;
    cout << "If x=-3.7, f(x)=" << p1(-3.7) << endl;
    cout << "Derivate: " << p1.derivative() << endl;
    cout << "Antiderivative: " << p1.antiderivative() << endl;
    cout << "DefInt(f) from 0 to 5.7: " << p1.definite_integral(0, 5.7) << endl;
    cout << "Math Operator Tests" << endl;
    p2.clear();
    p2.assign_coef(7.2,2);
    p2.assign_coef(-11.3,1);
    cout << "(" << p1 << ") + (" << p2 << ") = " << (p1 + p2) << endl;
    cout << "(" << p1 << ") - (" << p2 << ") = " << (p1 - p2) << endl;
    cout << "(" << p1 << ") * (" << p2 << ") = " << (p1 * p2) << endl;

    return 0;
}