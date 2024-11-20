// FILE: node.cpp
//
//
//  COEN 79
//  --- Behnam Dezfouli, COEN, SCU ---
//
//
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
//
// INVARIANT for the node class:
//   The data of a node is stored in data_field
//   and the link to the next node is stored in link_field.

//node class Value Semantics: assignment and copy constructor may be used

#include "node.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
#include <iostream>

using namespace std;

namespace coen79_lab6
{
    // Precondition: head_ptr is the head pointer
    // Postcondition: returns  number of nodes in the linked list
    size_t list_length(const node* head_ptr)
    // Library facilities used: cstdlib
    {
        const node *cursor;
        size_t answer;

        answer = 0;
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
            ++answer;

        return answer;
    }

    // Precondition: head_ptr is the head pointer
    // Postcondition: New node with given entry is added and the head of the LL 
    // head_ptr now points to the head of the new LL
    void list_head_insert(node*& head_ptr, const node::value_type& entry)
    {
    	head_ptr = new node(entry, head_ptr);
    }

    // Precondition: previous_ptr points to a node in a LL
    // Postcondition: new node with given entry is added after previous_ptr points to
    void list_insert(node* previous_ptr, const node::value_type& entry)
    {
    	node *insert_ptr;
    	insert_ptr = new node(entry, previous_ptr->link( ));
    	previous_ptr->set_link(insert_ptr);
    }

    // OOPPPSS only code we edit
    node* list_search(node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
    	node *cursor;

    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    	    if (target == cursor->data( ))
        		return cursor;

    	return NULL;
    }

    const node* list_search(const node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
    	const node *cursor;

    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    	    if (target == cursor->data( ))
        		return cursor;

    	return NULL;
    }

    node* list_locate(node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
    	node *cursor;
    	size_t i;

    	assert (0 < position);
    	cursor = head_ptr;
    	for (i = 1; (i < position) && (cursor != NULL); i++)
    	    cursor = cursor->link( );

    	return cursor;
    }

    const node* list_locate(const node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
    	const node *cursor;
    	size_t i;

    	assert (0 < position);
    	cursor = head_ptr;
    	for (i = 1; (i < position) && (cursor != NULL); i++)
    	    cursor = cursor->link( );

    	return cursor;
    }

    void list_head_remove(node*& head_ptr)
    {
    	node *remove_ptr;

    	remove_ptr = head_ptr;
    	head_ptr = head_ptr->link( );
    	delete remove_ptr;
    }

    void list_remove(node* previous_ptr)
    {
    	node *remove_ptr;

    	remove_ptr = previous_ptr->link( );
    	previous_ptr->set_link( remove_ptr->link( ) );
    	delete remove_ptr;
    }

    void list_clear(node*& head_ptr)
    // Library facilities used: cstdlib
    {
    	while (head_ptr != NULL)
    	    list_head_remove(head_ptr);
    }

    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
    // Library facilities used: cstdlib
    {
    	head_ptr = NULL;
    	tail_ptr = NULL;

    	// Handle the case of the empty list.
    	if (source_ptr == NULL)
    	    return;

    	// Make the head node for the newly created list, and put data in it.
    	list_head_insert(head_ptr, source_ptr->data( ));
    	tail_ptr = head_ptr;

    	// Copy the rest of the nodes one at a time, adding at the tail of new list.
    	source_ptr = source_ptr->link( );
    	while (source_ptr != NULL)
    	{
    	    list_insert(tail_ptr, source_ptr->data( ));
    	    tail_ptr = tail_ptr->link( );
    	    source_ptr = source_ptr->link( );
    	}
    }

    // Precondition: start_ptr and end_ptr points to nodes in same LL 
    // where start points before or at end
    //  Postcondition: head_ptr and tail_ptr are pointers for a new LL with items 
    //  from start_ptr up to but != end_ptr. If end_ptr is NULL then its from start to end ptrs
    void list_piece(node* start_ptr, node* end_ptr, node*& head_ptr, node*& tail_ptr) {
        head_ptr=NULL;
        tail_ptr=NULL;

        if (start_ptr==NULL || start_ptr==end_ptr) {
            return;
        }

        node* temp = start_ptr;
        size_t pos = 1;
        while(temp != end_ptr) {
            ++pos;
            temp = temp->link();
        }

        list_copy(start_ptr, head_ptr, tail_ptr);
        temp = list_locate(head_ptr, pos);
        
        if(end_ptr != NULL) {   
            tail_ptr = head_ptr;
            while(tail_ptr->link() != temp) {
                tail_ptr = tail_ptr->link(); 
            }
            while(tail_ptr->link() != NULL) {
                list_remove(tail_ptr);
            }
        }
    }

    // Precondition: head_ptr is the head pointer of LL
    // Postcondition: Returns the number of times arget appears as the data of a node
    // LL doesnt change
    size_t list_occurrences(node* head_ptr, const node::value_type& target) {
        size_t count = 0;
        const node* temp = head_ptr;
        while (temp) {
            if(temp->data() == target){
                ++count; 
            }
            temp = temp->link();
        }
        return count;
    }

    // Precondition: head_ptr is the head pointer in LL. 0 < position <= list_length(head_ptr)+1.
    // Postcondition: New node with entry as data at position
    void list_insert_at(node*& head_ptr, const node::value_type& entry, size_t position) {
        if(position == 1) {
            list_head_insert(head_ptr, entry);
        } else if (position == list_length(head_ptr) + 1 ) {
            list_insert(list_locate(head_ptr, list_length(head_ptr)), entry);
        } else {
            list_insert(list_locate(head_ptr, position -1), entry);  
        }  
    }

    // Precondition: head_ptr is the head pointer in LL. 0 < position <= list_length(head_ptr)
    // Postcondtion: node at position removed
    node::value_type list_remove_at(node*& head_ptr, size_t position) {
        node::value_type tmp;
        if(position == 1) {
            tmp = head_ptr->data();
            list_head_remove(head_ptr);
        } else {
            node* pHolder = list_locate(head_ptr, position-1);
            tmp = pHolder->data();
            list_remove(pHolder);
        }
        return tmp;
    }

    // Precondition: head_ptr is the head pointer
    // (1 <= start) && (start <= finish) && (finish <= list_length(head_ptr))
    // Postcondtion: returns head pointer as new list from start to end
    node* list_copy_segment(node* head_ptr, size_t start, size_t finish) {
        assert(start >= 1);
        assert(start <= finish);
        assert(finish <= list_length(head_ptr));
        if(!head_ptr) {
            return NULL;
        } 
        node* startP = list_locate(head_ptr, start);
        node* endP = list_locate(head_ptr, finish);
        endP = endP->link();
        node* head, *tail;
        list_piece(startP, endP, head, tail);
        return head;
    }

    // Precondition: head_ptr is the head pointer LL and << is defined
    // Postcondition: The value_type of all the nodes in the LL are printed
    void list_print (const node* head_ptr) {
        if(!head_ptr){
            cout << endl;
            return;
        }
        const node* temp = head_ptr;
        cout << temp->data();
        temp = temp->link();
        while(temp) {
            cout << ", " << temp->data();
            temp = temp->link();
        }
        cout << endl;
    }

    // Precondition: head_ptr is the head pointer
    // Postcondition: Removes duplicates
    void list_remove_dups(node* head_ptr) {
        if(head_ptr == NULL) {
            return;
        }
        node* slow = head_ptr;
        node* fast;
        while(slow->link()) {
            fast = slow;
            while(fast->link()) {
                if(fast->link()->data() == slow->data()) {
                    list_remove(fast);   
                } else {
                    fast = fast->link();
                }
            }
            
            
        }
    }

    // Precondition: head_ptr is the head pointer
    // Postcondition:If there is a loop the return value is the start of the loop ELSE NULL
    node* list_detect_loop (node* head_ptr) {
        node* slow = head_ptr;
        node* fast = head_ptr;
        if(!fast->link() || !fast->link()->link()) {
            return NULL;
        } do {
            slow = slow->link();
            fast = fast->link()->link();
        } while(slow != fast && (fast->link() || fast->link()->link()));

        if(slow == fast) {
            cout << "the pointers met!" << endl;
            fast = head_ptr;
            while(fast != slow){
                fast = fast->link();
                slow = slow->link();
            }
            return fast;
        }
        return NULL;
    }
    
}
