#include <iostream>
#include "sequence.h"


using namespace std;
using coen79_lab6::sequence;

void printSequence(sequence &s) {
	sequence seq(s);
	seq.start();

	while(seq.is_item()) {
		cout << seq.current() << " ";
		seq.advance();
	}
    cout << endl;
}

int main(int argc, const char * argv[]) {
	sequence seq1, seq2;
//ATTACH
	seq1.attach(42);
	printSequence(seq1);
	seq1.attach(25);
	printSequence(seq1);
	seq1.attach(2);
	printSequence(seq1);
//INSERT
	seq1.insert(9);
	printSequence(seq1);
	seq1.insert(17);
	printSequence(seq1);
	seq1.attach(13);
	printSequence(seq1);
//REMOVAL
	cout << " *** End Removal Test *** " << endl;
	seq1.end();
	if (seq1.is_item()) {
		seq1.remove_current();
	} 
	printSequence(seq1);

	cout << " *** Start Removal Test *** " << endl;
	seq1.start();
	if (seq1.is_item()) {
		seq1.remove_current();
	} 
	printSequence(seq1);

	cout << " *** Middle Removal Test *** " << endl;
	seq1.start();
	seq1.advance();
	seq1.remove_current();
	printSequence(seq1);
//ASSIGNMENT
	cout << " *** First Assignment Test *** " << endl;
	seq2 = seq1;
	seq1.attach(5);
	printSequence(seq1);
	printSequence(seq2);
	seq2.insert(18);
	seq2.attach(92);
	printSequence(seq2);

	cout << " *** More Assignment Tests *** " << endl;
	sequence sequenceA, sEmpty, sOne, sTen;

	for (int i = 0; i < 5; i++) {
		sequenceA.attach(i);
	}
	sOne.attach(1.001);
	for (int i = 0; i < 10; i++) {
		sTen.attach(i);
	} 
	printSequence(sequenceA);
	sequenceA = sEmpty;
	printSequence(sequenceA);
	sequenceA = sOne;
	printSequence(sequenceA);
//IS ITEM
	cout << "Is item: " << sequenceA.is_item() << endl;
	sOne.advance();
	sequenceA = sOne;
	printSequence(sequenceA);
	cout << "Is item: " << sequenceA.is_item() << endl;
	sTen.start();
	sequenceA = sTen;
	printSequence(sequenceA);
	cout << "Is item: " << sequenceA.is_item() << endl;
	for (int i = 0; i < 4; ++i) sTen.advance();
	sequenceA = sTen;
	printSequence(sequenceA);
	cout << "Is item: " << sequenceA.is_item() << endl;
	sTen.end();
	sequenceA = sTen;
	printSequence(sequenceA);
	cout << "Is item: " << sequenceA.is_item() << endl;
	sTen.advance();
	sequenceA = sTen;
	printSequence(sequenceA);
	cout << "Is item: " << sequenceA.is_item() << endl;

//Lab example
	cout << " *** Lab Example *** " << endl;
	sequence labSequence;
	cout << "Size: " << labSequence.size() << endl;
	cout << "Is_Item: " << labSequence.is_item() << endl;
	labSequence.insert(12);
	printSequence(labSequence);
	labSequence.insert(17);
	printSequence(labSequence);
	labSequence.advance();

	cout << "Is_Item: " << labSequence.is_item() << endl;
	labSequence.insert(7);
	printSequence(labSequence);
	labSequence.attach(4);
	printSequence(labSequence);
	labSequence.advance();
	labSequence.advance();

	cout << "Size: " << labSequence.size() << endl;
	cout << "Is_Item: " << labSequence.is_item() << endl;
	labSequence.insert(3);
	printSequence(labSequence);
	labSequence.advance();
	labSequence.remove_current();
	printSequence(labSequence);
	labSequence.advance();
	labSequence.remove_current();
    printSequence(labSequence);
    labSequence.advance();
    labSequence.attach(11);
	printSequence(labSequence);
	labSequence.start();

	cout << "Start: " << labSequence.current() << endl;
	labSequence.end();
	cout << "End: " << labSequence.current() << endl;
    cout << "Displaying sequence_out.txt.";
}