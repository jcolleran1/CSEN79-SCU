
//Joshua Colleran
//Random cpp
//Class to generate pseudorandom numbers
//COEN79

//Allows acess to random.h and CPP libraries
#include <cassert>
#include <iostream> 
#include "random.h"


using namespace std;
using namespace coen79_lab2;

//This function will initialize an object and be ready to generate psudorandom numbers
rand_gen::rand_gen(int currentSeed, int currentMult, int currentInc, int currentMod) {
    seed = currentSeed;
    inc = currentInc;
    mult = currentMult;
    mod = currentMod;
}

// This function will make the number newSeed the new seed
void rand_gen::set_seed(int newSeed) {
    seed = newSeed;
}

//This function will set the return value as the next random integer, and then return value is set as the new seed
int rand_gen::next() { 
    int randNum = ((mult * seed + inc) % mod);
    seed = randNum;
    return seed;
}

//This functino will print the values of the private member variables
void rand_gen::print_info() { 
        cout << "Seed: " << seed << endl;
        cout << "Multiplier: " << mult << endl;
        cout << "Increment: " << inc << endl;
        cout << "Modulus: " << mod <<endl;
}
