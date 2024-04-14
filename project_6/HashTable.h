// Author:  Evan Meyers
// UAID:    010955257

#ifndef PROJECT_6_HASHTABLE_H
#define PROJECT_6_HASHTABLE_H

#include "Address.h"
#include <iostream>
using namespace std;

class HashTable {
public:

    // Structors
    HashTable(const int &SIZE);
    ~HashTable();

    // Methods
    bool Insert(string key, const Address &address);
    int Search(const string &key, Address &name);
    void Print();

private:

    int Hash(string key);
    int Hash2(int index);

    // Private constants
    static const char AVAIL = 'A';
    static const char EMPTY = 'E';
    static const char FULL = 'F';

    // Private data
    int Size;
    int Count;
    char *Status;
    Address *Value;
    string *Key;
    int colCount;

};


#endif //PROJECT_6_HASHTABLE_H
