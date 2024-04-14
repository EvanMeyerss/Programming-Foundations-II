#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "table.h"

using namespace std;

// Default Table
table::table() {}

// Table copier
table::table(const table & copy) {
    for (int i = 0; i < Book.size(); i++) {
        Book[i] = copy.Book[i];
    }
}

// Table destructor
table::~table() {}


// Read method
void table::read(const string & file) {
    ifstream list(file);

    if (list.is_open()) {
        while (!list.eof()) {
            Book.push_back((getline(list, Book.setAuthor)));
        }

    }

}