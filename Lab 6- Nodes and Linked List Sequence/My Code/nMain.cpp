#include <iostream>
#include "node.h"

using namespace coen79_lab6;
using std::cout;
using std::endl;

int main() {
    node* list;
    node* head;
    node* tail;

    list_head_insert(list, 4.5);
    list_head_insert(list, 4);
    list_head_insert(list, 3.5);
    list_head_insert(list, 3);
    list_head_insert(list, 2.5);
    list_head_insert(list, 2);
    list_head_insert(list, 1.5);
    list_head_insert(list, 1);

    cout << "The list: ";
    list_print(list);
    
    cout << " *** list_piece tests *** " << endl;
    list_piece(NULL, NULL, head, tail);
    cout << "Empty: ";
    list_print(head);
    list_piece(list, list, head, tail);
    cout << "Both at head: " ;
    list_print(head);
    cout << "Three from head: " ;
    list_piece(list, list_locate(list, 4), head, tail);
    list_print(head);
    cout << "Three in middle: ";
    list_piece(list_locate(list,3), list_locate(list,6), head, tail);
    list_print(head);
    cout << "Three on end: ";
    list_piece(list_locate(list,6), NULL, head,tail);
    list_print(head);
    cout << "The end: ";
    list_piece(list_locate(list, list_length(list)), NULL, head, tail);
    list_print(head);
    cout << "Full list: ";
    list_piece(list, NULL, head, tail);
    list_print(head);

    cout << endl <<" *** list_copy_segment tests *** " << endl;
    cout << "Both at head: " ;
    head = list_copy_segment(list,1,1);
    list_print(head);
    cout << "Three from head: " ;
    head = list_copy_segment(list,1,3);
    list_print(head);
    cout << "Three in middle: ";
    head = list_copy_segment(list,3,5);
    list_print(head);
    cout << "Three on end: ";
    head = list_copy_segment(list,6,8);
    list_print(head);
    cout << "The end: ";
    head = list_copy_segment(list,8,8);
    list_print(head);
    cout << "Full list: ";
    head = list_copy_segment(list,1,8);
    list_print(head);

    cout << endl <<" *** list_insert_at tests *** " << endl;
    cout << "Inserting 0.5 at front:" << endl << '\t';
    list_insert_at(head, 0.5, 1);
    list_print(head);
    cout << "Inserting 4.75 at back:" << endl << '\t';
    list_insert_at(head, 4.75, 1+ list_length(head));
    list_print(head);
    cout << "Inserting 2.25 in middle:" << endl << '\t';
    list_insert_at(head, 2, 5);
    list_print(head);
    node* empty;
    cout << "Inserting -4.3 into an empty list:" << endl << '\t';
    list_insert_at(empty, -4.3, 1);
    list_print(empty);

    cout << endl << " *** list_occurrences tests *** " << endl;
    list_insert_at(head, 2, 5);
    list_insert_at(head, 2, 5);
    cout << "The list: ";
    list_print(head);
    cout << "Number of 0.5's: ";
    cout << list_occurrences(head, 0.5) << endl;
    cout << "Number of 4.75's: ";
    cout << list_occurrences(head, 4.75) << endl;
    cout << "Number of 3's: ";
    cout << list_occurrences(head, 3) << endl;
    cout << "Number of 2's: ";
    cout << list_occurrences(head, 2) << endl;
    cout << "Number of 0's: ";
    cout << list_occurrences(head, 0) << endl;

    cout << endl << " *** list_remove_at tests *** " << endl;
    cout << "The list: ";
    list_print(head);
    cout << "Removing first item:\n\t";
    list_remove_at(head, 1);
    list_print(head);
    cout << "Removing last item:\n\t";
    list_remove_at(head, list_length(head));
    list_print(head);
    cout << "Removing 3.5 from the middle:\n\t";
    list_remove_at(head, 9);
    list_print(head);

    cout << endl << " *** list_remove_dups tests *** " << endl;
    node* head_ptr = NULL;
    for(int i = 0; i<4; i++) {
        list_head_insert(head_ptr, 1);
    }
    list_print(head_ptr);
    list_remove_dups(head_ptr);
    list_print(head_ptr);
    
    cout << endl << " *** list_detect_loop tests *** " << endl;
    node* head_ptr2 = NULL;
    for(int i = 10; i>0; i--) {
        list_head_insert(head_ptr2, i);
    }

    node *temp;
    temp = list_locate (head_ptr2, 10);
    temp->set_link(head_ptr2->link()->link()->link()->link());
    node *loop_start = NULL;
    loop_start = list_detect_loop(head_ptr2);
    if (loop_start != NULL)
        std::cout << "Loop start location is: " << loop_start->data() << std::endl;
    return 0;
}