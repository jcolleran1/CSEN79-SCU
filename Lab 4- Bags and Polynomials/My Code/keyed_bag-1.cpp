#include "keyed_bag.h"
#include <cassert>
#include <cmath>
#include <climits>
#include <iostream>
#include <iomanip>
using namespace std; 

namespace coen79_lab4 { 
    //Postcondition: The bag is emptied of all of its items
    keyed_bag::keyed_bag() {
        for(int i = 0; i < CAPACITY; i++) {
            keys[i] = "/0";
            data[i] = 0;
        }
        used = 0; 
    }

    //Postcondition: Keyed_bag is emptied of all its items
    void keyed_bag::erase() {
        keyed_bag();
        used = 0;
    }

    //Postcondition: Erases spefic key if found inside of the bag and returns true
    bool keyed_bag::erase(const key_type &key) {
        for(int i=0; i<used; i++) {
            if(keys[i] == key) {
                for(int j=i; j<used-1; j++) {
                    keys[j] = keys[j+1];
                    data[j] = data[j+1];
                }
                used--;
                return true;
            }
        }
        return false;
    }

    //precondition: The size of the array is less then the capasity of array keys
    //postcondition: Adds parameter entry to the bag of keys at a given key
    void keyed_bag::insert(const value_type &entry, const key_type &key) {
        assert((size() < CAPACITY) && (has_key(key) == false));
        keys[used] = key;
        data[used] = entry;
        used++;
    }

    //precondition: the size and the added size is less then the capacity
    //postcondition: Each item in addend is added to keyed_bag
    void keyed_bag::operator +=(const keyed_bag &addend) {
        assert(size() + addend.size() <= CAPACITY);  
        for (int i=0; i<addend.used; i++){     //iterate through all elements of addend bag
            if (!has_key(addend.keys[i])) { 
                keys[used] = addend.keys[i];
                data[used] = addend.data[i];
                used++;
            }
        }
    }
    //postcondition:returns true if the key is found in the bag
    bool keyed_bag::has_key(const key_type &key) const {
        for (int i = 0; i < used; i++) {  
            if (keys[i] == key) {
                return true;
            }
        }
        return false;
    }

    //precondition: has keys is true
    //postcondition: Data value at the key is returned
    keyed_bag::value_type keyed_bag::get(const key_type&key) const {
        assert(has_key(key));
        for (int i = 0; i < used; i++){
            if (keys[i] == key){
                return data[i];
            }
        }
        return 0;
    } 

    //postcondition: returns the amount of used items in keyed_bag
    keyed_bag::size_type keyed_bag::size() const {
        return used;
    }

    //postcondition: returnes the amount of times a item is used in the keyed_bag
    keyed_bag::size_type keyed_bag::count(const value_type &target) const {
        size_type count = 0;
        for (int i = 0; i < used; i++){
            if (data[i] == target){
                count++;
            }
        }
        return count;
    }

    //postcondition: returns true if their is a matching key in other bag and keyed_bag
    bool keyed_bag::hasDuplicateKey(const keyed_bag &otherBag) const {
        for (int i = 0; i < otherBag.used; ++i){
            if (has_key(otherBag.keys[i])){ 
                return true;
            }
        }
        return false;
    }
        
    //precondition: the size of bag 1 and bag 2 is less then or equal to the keyed_bag capacity
    //postcondition: returns the union of bag 1 and bad 2 
    keyed_bag operator +(const keyed_bag &b1, const keyed_bag &b2) {
        assert((b1.size() + b2.size()) <= keyed_bag::CAPACITY);
        keyed_bag b3;
        b3 += b1;
        b3 += b2;
        return b3;
    }
} 