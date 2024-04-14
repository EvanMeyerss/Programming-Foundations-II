// Author:  Evan Meyers
// UAID:    010955257
#include <iostream>
using namespace std;


class BestSellerNode {

public:

    // Constructors
    BestSellerNode();
    BestSellerNode(int y, int r, int tID, string w, string t, string a);
    BestSellerNode(const BestSellerNode & copy);
    ~BestSellerNode();

    // Getter Methods
    BestSellerNode* getNext();
    int getYear() const;
    int getRank() const;
    int getTitle_ID() const;
    string getWeek() const;
    string getTitle() const;
    string getAuthor() const;
    int getSubYear() const;
    int getSubMonth() const;
    int getSubDay() const;

    // Setter Methods
    void setNext(BestSellerNode *newNext);
    void setYear(const string & year);
    void setRank(const string & rank);
    void setTitle_ID(const string & title_id);
    void setWeek(string week);
    void setTitle(string title);
    void setAuthor(string author);

    // Print
    void print() const;

private:
    BestSellerNode *Next;
    int Year, Rank, Title_ID;
    string Week, Title, Author;
    int subYear, subMonth, subDay;

};

