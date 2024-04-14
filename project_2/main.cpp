// Author:  Evan Meyers
// UAID:    010955257
#include <iostream>
#include "table.h"

using namespace std;

int main() {

    cout << "---------------------\n"
         << "| Name:\tEvan Meyers |\n"
         << "| UAID:\t010955257   |\n"
         << "---------------------\n\n";

    // Initialize table for list of books
    table file;
    BestSellerList bookList;

    // Reads "nyt_best_sellers.tsv" file with ifstream
    file.read("nyt_best_sellers.tsv");

    // Print all Best Seller books
    bookList.find_author("John Galsworthy");


    return 0;
}
