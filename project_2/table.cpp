// Author:  Evan Meyers
// UAID:    010955257
#include <iostream>
#include <fstream>
#include <string>
#include "table.h"

using namespace std;

// Default Table
table::table() {}

// Table copier
table::table(const table & copy) {
    //for (int i = 0; i < Book.size(); i++) {
    //    Book[i] = copy.Book[i];
}
//}

// Table destructor
table::~table() {}


// Read method
void table::read(const string & file) {
    ifstream list(file);
    BestSellerList testList;
    BestSellerNode* tmpNode = new BestSellerNode();

    if (list.is_open()) {
        getline(list, throwAway);
        while (!list.eof())
        {
            // Set Year
            getline(list, tempStr, '\t');
            tmpNode -> setYear(tempStr);

            // Set Week
            getline(list, tempStr, '\t');
            tmpNode -> setWeek(tempStr);

            // Set Rank
            getline(list, tempStr, '\t');
            tmpNode -> setRank(tempStr);

            // Set Title_ID
            getline(list, tempStr, '\t');
            tmpNode -> setTitle_ID(tempStr);

            // Set Title
            getline(list, tempStr, '\t');
            tmpNode -> setTitle(tempStr);

            // Set Author
            getline(list, tempStr, '\n');
            tmpNode -> setAuthor(tempStr);

            // Store tmpBook in the Book vector
            testList.AuthorInsert(tmpNode);

        }

        list.close();
    }

        // Error checking for opening the file
    else {
        cerr << "can't find file\n";
    }
}

// Print method
void table::print() {
    BestSellerNode* current;
    while (current != nullptr) {
        current -> print();
        cout << endl << endl;
        current = current -> getNext();
    }
}