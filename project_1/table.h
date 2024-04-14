#include <iostream>
#include "BestSeller.h"
#include <vector>

using namespace std;

class table {

public:

    // Constructors / Deconstructor
    table();
    table(const table & copy);
    ~table();

    // Methods
    void print();
    void read(const string & file);
    void find_title(const string & Title);
    void find_author(const string & Author);
    void find_week(const string & Week);

private:
    vector<BestSeller> Book;
    const int LIMIT = 100;
    string tempStr;

};

