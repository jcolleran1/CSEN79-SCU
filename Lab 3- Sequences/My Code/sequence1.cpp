#include <iostream>    
#include "sequence1.h"  
#include <cassert>
#include <cmath>

using namespace std;
using namespace coen79_lab3;

namespace coen79_lab3 {

    // The sequence is initialized as an empty sequence
    sequence::sequence() {
        current_index = 0;
        used = 0;
    }

    //The current_index (iterator) is set at 0
    void sequence::start() {
        current_index = 0;
    }

    //The itertator points to the last used spot
    void sequence::end() {
        current_index = (used-1);
    }

    //The itertator points to the Capacity no matter the amount of items in sequence
    void sequence::last() {
        current_index = (CAPACITY-1);
    }

    //Interator increases by one if is_item function is true and the iterators location is less then the capacity
    void sequence::advance() {
        assert(is_item());
        if(current_index < CAPACITY) {
            current_index++;
        }
         
    }
    
    //Iterator value is reduced by 1 unless the it is already at the start
    void sequence::retreat() {
        if(current_index > 0) {
            current_index--;
        }
    }

    //A new copy of entry is insterted before the current item
    void sequence::insert(const value_type& entry) {
        assert(size() < CAPACITY);
        if(is_item() == 0) {
            current_index = 0;
        }
        for(int i = used; i > current_index; i--) {
            data[i] = data[i-1];
        }
        
        data[current_index] = entry;
        used++;
    }
    
    //Inserts a new copy of entry infront of the sequence
    void sequence::insert_front(const value_type& entry) {
        assert(size() < CAPACITY);
        start();
        insert(entry);
    }

    //Inserts a new copy of entry after the current item in the sequence
    void sequence::attach(const value_type& entry) {
        assert(size() < CAPACITY);
        if(used > 0) {
            for(int i = used-1; i > current_index; --i) {
                data[i+1] = data[i];
            }
            data[current_index+1] = entry;
            current_index++;
        } else {
            data[current_index] = entry;
        }
        used++;
    }

    //Inserts a new copu of entry in th back of the sequence
    void sequence::attach_back(const value_type& entry) {
        assert(size() < CAPACITY);
        end();
        attach(entry);
    }

    //The current item is removed and the one after it is the current item now
    void sequence::remove_current() {
        assert(is_item());
        for(int i = current_index; i < used; i++) {
            data[i] = data[i+1];
        }
        used--;
    }

    //Item in the front of the sequence is removed and start is called
    void sequence::remove_front() {
        assert(is_item());
        start();
        remove_current();
    }

    //Returns the mean value of the sequence
    double sequence::mean() const {
        double sum = 0;
        for(int i = 0; i < used; i++) {
                sum += data[i];
        }
        double mean = (double)sum / (double)used;
        return mean;
    }

    //returns the standard deviation of the sequence
    double sequence::standardDeviation() const {
        double tempMean = mean();
        double sq = 0;
        for(int i = 0; i < used; i++) {
            sq += (data[i] - tempMean) * (data[i] - tempMean);
        }
        double standDev = sqrt((double) sq / (double) used);
        return standDev;
    }

    // returns true when the iterator is less then items in the sequence
    bool sequence::is_item() const {
        return (current_index<used);
    }

    //Returns the amount of items used in the sequence
    sequence::size_type sequence::size() const {
        return used;
    }

    //Returns the value at the iterator
    sequence::value_type sequence::current() const {
        assert(is_item());
        return data[current_index];
    }

    //Returns item at index
    sequence::value_type sequence::operator[](int index) const {
        assert(index<used);
        return data[index];
    }
            
    //returns the all the items of the sequence rhs and lhs
    sequence operator+(sequence& lhs, sequence& rhs) {
        sequence newSeq(lhs);
        sequence right(rhs);
        right.start();
        for(int i = 0; i < right.size(); i++) {
            newSeq.attach(right.current());
            right.advance();
        }
        return newSeq;
    }

    //Adds all the items of rhs to lhs and returns it
    sequence operator+=(sequence& lhs, sequence& rhs) {
        rhs.start();
        for(int i = 0; i < rhs.size() - 1; i++) {
            lhs.attach(rhs.current());
            rhs.advance();
        }
        return lhs;
    }

    //Returns the sum of values of the sequence s
    sequence::value_type summation(const sequence &s) {
        sequence t(s);
        t.start();
        int sum = 0;
        for(int i = 0; i < t.size(); i++) {
            sum += t.current();
            t.advance();
        }
        return sum;      
    }
}