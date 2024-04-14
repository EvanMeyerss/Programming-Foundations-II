#include <iostream>
using namespace std;


class BestSeller {

public:

    // Constructors
    BestSeller();
    BestSeller(int y, int r, int tID, string w, string t, string a);
    BestSeller(const BestSeller & copy);
    ~BestSeller();

    // Getter Methods
    void getYear();
    void getRank();
    void getTitle_ID();
    void getWeek();
    void getTitle();
    void getAuthor();

    // Setter Methods
    void setYear(int year);
    void setRank(int rank);
    void setTitle_ID(int title_id);
    void setWeek(string week);
    void setTitle(string title);
    void setAuthor(string author);


    // Print
    void print() const;

private:
    int Year, Rank, Title_ID;
    string Week, Title, Author;

};

