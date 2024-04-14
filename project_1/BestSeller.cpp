#include "BestSeller.h"
#include <iostream>

using namespace std;




// Default Constructor
BestSeller::BestSeller() {}

// Main Constructor
BestSeller::BestSeller(int y, int r, int tID, string w, string t, string a) {

    Year = y;
    Rank = r;
    Title_ID = tID;
    Week = w;
    Title = t;
    Author = a;

}

// Copy Constructor
BestSeller::BestSeller(const BestSeller &copy) {
    Year = copy.Year;
    Rank = copy.Rank;
    Title_ID = copy.Title_ID;
    Week = copy.Week;
    Title = copy.Title;
    Author = copy.Author;
}

// Destructor
BestSeller::~BestSeller() {}




// Getters
void BestSeller::getYear() {
    cout << Year << endl;
}

void BestSeller::getAuthor() {
    cout << Author << endl;
}

void BestSeller::getRank() {
    cout << Rank << endl;
}

void BestSeller::getTitle() {
    cout << Title << endl;
}

void BestSeller::getTitle_ID() {
    cout << Title_ID << endl;
}

void BestSeller::getWeek() {
    cout << Week << endl;
}




// Setters

void BestSeller::setYear(int year) {
    Year = year;
}

void BestSeller::setAuthor(string author) {
    Author = author;
}

void BestSeller::setRank(int rank) {
    Rank = rank;
}

void BestSeller::setTitle(string title) {
    Title = title;
}

void BestSeller::setTitle_ID(int title_id) {
    Title_ID = title_id;
}

void BestSeller::setWeek(string week) {
    Week = week;
}



// Print Method

void BestSeller::print() const {
    cout << "Year: " << Year
         << " Week: " << Week
         << " Rank: " << Rank
         << " Title ID: " << Title_ID
         << " Title: " << Title
         << " Author " << Author << endl;
}

