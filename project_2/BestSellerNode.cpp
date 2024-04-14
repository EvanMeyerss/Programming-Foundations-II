// Author:  Evan Meyers
// UAID:    010955257
#include "BestSellerNode.h"
#include <iostream>
#include <string>

using namespace std;



// Default Constructor
BestSellerNode::BestSellerNode() {
    Author = "N/A";
    Title = "N/A";
    Year = 0;
    Week = "N/A";
    Rank = 0;
    Title_ID = 0;
    subYear = 0;
    subMonth = 0;
    subDay = 0;
    Next;
}

// Main Constructor
BestSellerNode::BestSellerNode(int y, int r, int tID, string w, string t, string a) {

    Year = y;
    Rank = r;
    Title_ID = tID;
    Week = w;
    Title = t;
    Author = a;
    subYear = stoi(Week.substr(0,3));
    subMonth = stoi(Week.substr(5,6));
    subDay = stoi(Week.substr(8,9));

}

// Copy Constructor
BestSellerNode::BestSellerNode(const BestSellerNode &copy) {
    Year = copy.Year;
    Rank = copy.Rank;
    Title_ID = copy.Title_ID;
    Week = copy.Week;
    Title = copy.Title;
    Author = copy.Author;
    subYear = copy.subYear;
    subMonth = copy.subMonth;
    subDay = copy.subDay;
}


// Destructor
BestSellerNode::~BestSellerNode() {}


// Getters
BestSellerNode* BestSellerNode::getNext() {
    return Next;
}

int BestSellerNode::getYear() const {
    return Year;
}

string BestSellerNode::getAuthor() const
{
    return Author;
}

int BestSellerNode::getRank() const{
    return Rank;
}

string BestSellerNode::getTitle() const{
    return Title;
}

int BestSellerNode::getTitle_ID() const{
    return Title_ID;
}

string BestSellerNode::getWeek() const{
    return Week;
}

int BestSellerNode::getSubYear() const{
    return subYear;
};

int BestSellerNode::getSubMonth() const{
    return subMonth;
};

int BestSellerNode::getSubDay() const{
    return subDay;
};


// Setters
void BestSellerNode::setNext(BestSellerNode *newNext)
{
    Next = newNext;
}
void BestSellerNode::setYear(const string & year) {
    Year = stoi(year);
}

void BestSellerNode::setAuthor(string author) {
    Author = author;
}

void BestSellerNode::setRank(const string & rank) {
    Rank = stoi(rank);
}

void BestSellerNode::setTitle(string title) {
    Title = title;
}

void BestSellerNode::setTitle_ID(const string & title_id) {
    Title_ID = stoi(title_id);
}

// Week Setter
void BestSellerNode::setWeek(string week) {
    Week = week;
    subYear = stoi(Week.substr(0,4));
    subMonth = stoi(Week.substr(5,6));
    subDay = stoi(Week.substr(8,9));
}


// Print Method
void BestSellerNode::print() const {
    cout << "    Year:  " << Year << endl
         << "    Week:  " << Week << endl
         << "    Rank:  " << Rank << endl
         << "Title ID:  " << Title_ID << endl
         << "   Title:  " << Title << endl
         << "  Author:  " << Author << endl;
}