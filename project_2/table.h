// Author:  Evan Meyers
// UAID:    010955257
#include <iostream>
//#include "BestSellerNode.h"
#include "BestSellerList.h"
#include <vector>

using namespace std;

class table {

public:

    // Constructors / Destructor
    table();
    table(const table & copy);
    ~table();

    // Methods
    void print();
    void print(const int & start,const int & end);
    void read(const string & file);
    void find_title(const string & Title);
    void find_author(const string & Author);
    void find_week(const int & strYear, const int & strMth, const int & strDay, const int & endYear, const int & endMth, const int & endDay);

private:

    //BestSeller tmpBook;
    string tempStr, throwAway;

};

