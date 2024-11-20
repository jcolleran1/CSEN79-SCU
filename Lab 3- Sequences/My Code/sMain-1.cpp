#include "sequence1.h"

using namespace coen79_lab3;

void printSequence(sequence &seq){
    seq.start();
    std::cout << "Contents: ";
    for(sequence::size_type i = 0; i < seq.size(); ++i){
        std::cout << seq[i] << " ";
    }
    std::cout << std::endl;
    seq.end();
}
void printStats(sequence &seq){
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Mean: " << seq.mean() << std::endl;
    std::cout << "StdDev: " << seq.standardDeviation() << std::endl;
    std::cout << "Sum: " << summation(seq) << std:: endl;
    printSequence(seq);
    std::cout << "-----------------------------" << std::endl;
}

int main(){
    /*
    ● Create sequence object tester1
    ● Insert 1, 2, 3
    ● Printstats(tester1)
    ● Create sequence object tester2
    ● Insert 2, 3, 4
    ● Printstats(tester2)
    ● Sequence object tester3 = tester1+tester2
    ● Printstats(tester3)
    */
    sequence tester1;
    tester1.insert(1);
    tester1.insert(2);
    tester1.insert(3);
    printStats(tester1);

    sequence tester2;
    tester2.insert(2);
    tester2.insert(3);
    tester2.insert(4);   
    printStats(tester2);

    sequence tester3 = (tester1 + tester2);
    std::cout << "tester 3 : " << std::endl;
    printStats(tester3);
    std::cout << "tester 3 functions : " << std::endl;
    tester3.advance();
    printStats(tester3);

    tester3.advance();
    printStats(tester3);

    tester3.remove_front();
    printStats(tester3);
    
    tester3.advance();
    printStats(tester3);


    tester3.remove_front();
    printStats(tester3);
    
    tester3.advance();
    printStats(tester3);

    tester3.remove_current();
    printStats(tester3);

    tester3.attach_back(14);
    printStats(tester3);

    return 0;
}