#include <iostream>
#include "BestSeller.h"

using namespace std;

// Name: Evan Meyers
// UAID: 010955257


int main() {

    cout << "---------------------\n"
         << "|Name:\tEvan Meyers |\n"
         << "|UAID:\t010955257   |\n"
         << "---------------------\n\n";

    // Initialize table for list of books
   // table bookList;
    BestSeller testBook;

    testBook.setAuthor("Test");
    testBook.print();

    // Reads "nyt_best_sellers.tsv" file with ifstream
    //bookList.read("nyt_best_sellers.tsv");


    return 0;
}
