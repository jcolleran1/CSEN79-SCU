#include <iostream>
#include <cassert>
#include <string.h>
#include "mystring.h"
#include <cctype> 

using namespace std;

namespace coen79_lab5 {
//  Creates a string based on the char array argument
    string::string(const char str[]) {
        current_length = strlen(str);                         
        allocated = current_length + 1;                           
        characters = new char[allocated];                              
        strncpy(characters, str, allocated);                          
    }

//  Creates a string with a single char argument
    string::string(char c) {
        current_length = 1;                                             
        allocated = 2;                              
        characters = new char[2];                            
        characters[0] = c;                                              
        characters[1] = '\0';                                           
    }
    
//  Creates a copy of the source string
    string::string(const string& source) {
        current_length = source.length();
        allocated = current_length + 1;
        characters = new char[allocated];
        strncpy(characters, source.characters, allocated);
    }

//  Destructor destroys characters[] array on heap
    string::~string() {
        current_length = 0;                                           
        allocated = 0;
        delete[] characters;                                            
    }


    //Member funcions

//  Postcondition: string addend has been added to the end of the string.
    void string::operator +=(const string& addend) {
        current_length += addend.current_length;
        allocated = current_length + 1;
        reserve(allocated);
        strncat(characters, addend.characters, addend.current_length);
    }

//  Postcondition: array addend has been added to the end of the string.
    void string::operator +=(const char addend[ ]) {
        current_length = current_length + strlen(addend);             
        allocated = current_length + 1;       
        reserve(allocated);                    
        strncat(characters, addend, strlen(addend));    
    }

//  Postcondition: single character addend has been added to the end of the string
    void string::operator +=(char addend) {
        current_length++;                                        
        allocated = current_length + 1;           
        reserve(allocated);                
        characters[current_length-1] = addend;
        characters[current_length] = '\0';
    }

//  Postcondition: size of array is increased
    void string::reserve(size_t n) {
        char *newC;
        newC = new char[n];
        strncpy(newC, characters, current_length);
        allocated = n;
        delete [] characters;
        characters = newC;
    }

//  postconcdition: the source is copied to string
    string& string::operator =(const string& source) {
        this->dlt(0, current_length);
        if(current_length != source.current_length) {
            reserve(allocated);
        }
        strncpy(characters, source.characters, source.current_length+1);
        current_length = source.current_length;
        return *this;
    }

//  Precondtion: position <= length()
//  Postcondition: The source string is inserted into this string before the index
    void string::insert(const string& source, unsigned int position) {
        assert(position <= length());
        current_length = source.current_length + current_length;
        string temp = *this;
        reserve(source.current_length + current_length + 1);
        characters[0] = 0;
        strncpy(characters, temp.characters, position);
        characters[position] = 0;
        strncat(characters,source.characters,allocated-position);
        characters[position+source.current_length] = 0;
        strncat(characters,temp.characters + position, allocated - (position + source.current_length));
        characters[allocated-1] = 0;
    }

//  Precondition: (position + num) <= length( ).
//  Postcondition: paramerter num characters are deleted starting at index
    void string::dlt(unsigned int position, unsigned int num) {
        assert((position + num) <= length());
        for(int i = position; i < length() + 1; i++) {      
            characters[i] = characters[i+num];
        }
        current_length = current_length - num;
    }

//  Precondition: position < length()
//  Postcondtion: Character c given by the parameter replaces index
    void string::replace(char c, unsigned int position) {
        assert(position < length());
        characters[position] =  c;
    }

//  Precondition: (position + source.length()) <= length()
//  Postcondtion: starting at parameter postion the characters are replaced with those in source
    void string::replace(const string& source, unsigned int position) {
        assert((position + source.length()) <= length());
        for(int i = position; i < position + source.length(); ++i) {
            characters[i] = source.characters[i - position];
        }
    }

//  Constant member functions

//  Precondition: position < length( ).
//  Postcondition: returns char at index
    char string::operator [ ](size_t position) const {
        assert(position < length());
        return characters[position];
    }

//  Postcondition: returns first location of parameter c or -1 if nonexistent
    int string::search(char c) const {
        int i = 0;
        while(characters[i] != '\0') {
            if(characters[i] == c) {
                return i;
            }
            i++;
        }
        return -1;
    }

//  Postcondition: returns index of start of the given substring or -1 if nonexistent
    int string::search(const string& substring) const {
        for(size_t i = 0; i < (current_length - substring.current_length) + 1; i++) {
            if(strncmp(&characters[i], substring.characters, substring.current_length) == 0) {
                return i;
            }
        }
        return -1;
    }

//     Postcondition: returns number of times parameter c exists
    unsigned int string::count(char c) const {
        unsigned int count = 0;
        for(size_t i = 0; i < current_length; i++) {
            if(characters[i] == c) {
                count++;
            }
        }
        return count;
    }

// friends and non member functions

//  returns combo of s1 and s2 as string
    string operator +(const string& s1, const string& s2) {
        string newstr;
        newstr += s1;
        newstr += s2;
        return newstr;
    }

//  returns combo of s1 and addend as string
    string operator +(const string& s1, const char addend[ ]) {
        string newstr;
        newstr += s1;
        newstr += addend;
        return newstr;
    }

//  returns true if s1 and s2 are the same
    bool operator ==(const string& s1, const string& s2) {
        return(strcmp(s1.characters, s2.characters) == 0);
    }

//  returns true if s1 and s2 are not the same
    bool operator !=(const string& s1, const string& s2) {
        return(strcmp(s1.characters, s2.characters) != 0);
    }

//  returns true if s1 > s2
    bool operator > (const string& s1, const string& s2) {
        return(strcmp(s1.characters, s2.characters) > 0);
    }

//  returns true if s1 < s2
    bool operator < (const string& s1, const string& s2) {
        return(strcmp(s1.characters, s2.characters) < 0);
    }

//  returns true if s1 >= s2
    bool operator >=(const string& s1, const string& s2) {
        return((s1>s2) || (s1==s2));
    }

//  returns true if s1 <= s2
    bool operator <=(const string& s1, const string& s2) {
        return((s1<s2) || (s1==s2));
    }

//  Postcondition: string is read from ins not counting the white space at start up to next white space
    std::istream& operator >> (std::istream& ins, string& target) {
        char *in = new char[100];
        while (ins && isspace(ins.peek())) {
            ins.ignore();
        }
        ins >> in;
        target = string(in);
        return ins;     
    }

//  Postcondition: characters in source are printed as outs
    std::ostream& operator <<(std::ostream& outs, const string& source) {
        outs << source.characters;
        return outs;
    }

}