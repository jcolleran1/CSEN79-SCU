//FILE: sequence.cpp
//CLASS IMPLEMENTED: sequence (see sequence.h for documentation)
//
//
//  COEN 79
//  --- Behnam Dezfouli, COEN, SCU ---
//
//
//INVARIANT for the sequence class
//  1. The number of items in the sequence is stored in the member variable "many_nodes"
//
//  2. For an empty sequence, we do not care what is stored in any of data and head_ptr
//      and tail_ptr point to NULL; for a non-empty sequence, the items stored in the
//      sequence can be accessed using head_ptr and tail_ptr and we don't care what is
//      stored in the rest of the data.
//
//  3. If there is a current item, then it lies in *cursor; if there is no
//     current item, then cursor* equals NULL.
//
//  4. If there is a previous item, then it lies in precursor*.  If there is no previous
//       item, then precursor equals NULL.


#include <iostream>
#include <algorithm> //provides copy function
#include <cassert> //for assert function
#include "sequence.h" //header file for class
#include "node.h" // provides node class

using namespace std; //For copy function

namespace coen79_lab6
{
    // Default private member variable initialization function.
    void sequence::init()
    {
        //Initializing pointers to NULL
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        //Initializiing many_nodes (or our counter) to 0
        many_nodes = 0;
    }

    //CONSTRUCTOR IMPLEMENTATION for default constructor
    sequence :: sequence ()
    {
        init();
    }

    //Copy Constructor
    sequence :: sequence(const sequence& source)
    {
        init();
        *this = source;
    }

    // Postcondition: destructs then reinitializes the pointers
    sequence::~sequence() {
        list_clear(head_ptr);
        init();
    }

    // Postcondition: Curser goes to the head
    void sequence::start() {
        precursor = head_ptr;
        cursor = head_ptr;
    }

    // Postcondition: Curser goes to tail
    void sequence::end() {
        if(many_nodes == 0) {
            cursor = precursor = NULL;
        } else if (head_ptr == tail_ptr) {
            precursor = NULL;
            cursor = head_ptr;
        } else {
            precursor = list_locate(head_ptr, many_nodes-1);
            cursor = tail_ptr;
        }
    }

    // Precondition: is_item returns true.
    // Postcondition: advances cursor and precursor forward one item
    void sequence::advance() {
        assert(is_item());
        precursor = cursor;
        cursor = cursor->link();
    }

    // Postcondition: Inserts item before current item
    void sequence::insert(const value_type& entry) {
        if(!is_item() || !precursor) {
            list_head_insert(head_ptr, entry);
            if(!tail_ptr) {
                tail_ptr = head_ptr;
            }
            cursor = head_ptr;
            precursor = NULL;
            ++many_nodes;
        } else {
            list_insert(precursor, entry);
            cursor = precursor->link();
            ++many_nodes;
        }
    }

    // Postcondition: Attaches item after current
    void sequence::attach(const value_type& entry) {
        if(!head_ptr) {
            list_head_insert(head_ptr, entry);
            tail_ptr = head_ptr;
            cursor = head_ptr;
            precursor = NULL;
            ++many_nodes;
        } else if(!cursor) {
            list_insert(tail_ptr, entry);
            precursor = tail_ptr;
            tail_ptr = tail_ptr->link();
            cursor = tail_ptr;
            ++many_nodes;
        } else {
            list_insert(cursor, entry);
            precursor = cursor;
            if(tail_ptr == cursor) {
                tail_ptr = tail_ptr->link();
            }
            cursor = cursor->link();
            ++many_nodes;
        }
    }

    // Postcondition: List == source list
    void sequence::operator =(const sequence& source) {
        if(this == &source) {
            return;
        }   
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;
        start();
        node* tmp = source.head_ptr;
        while(tmp != source.cursor) {
            advance();
            tmp = tmp->link();
        }
    }
    // Precondition: is_item returns true.
    // Postcondition: Removes current item
    void sequence::remove_current() {
        assert(is_item());
        if(head_ptr == cursor && head_ptr == tail_ptr) {
            list_head_remove(head_ptr);
            init();
        } else if(head_ptr == cursor && head_ptr != tail_ptr) {
            list_head_remove(head_ptr);
            cursor = head_ptr;
            precursor = NULL;
        } else if(cursor == tail_ptr) {
            list_remove(precursor);
            cursor = NULL;
            tail_ptr = precursor;
        } else {
            list_remove(precursor);
            cursor = precursor->link();
        }
        --many_nodes;
    }

    // Postcondition: Returns # of nodes
    sequence::size_type sequence::size() const {
        return many_nodes;
    }

    // Postcondition: Returns true if there is an item pointed to by curser
    bool sequence::is_item() const {
        return (cursor != NULL);
    }

    // Postcondition: Retruns data pointed to by curser
    sequence::value_type sequence::current() const {
        return cursor->data();
    }
}

