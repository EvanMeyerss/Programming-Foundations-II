// Author:  Evan Meyers
// UAID:    010955257
#include "BestSellerNode.h"
#include <iostream>
#include <string>

using namespace std;

class BestSellerList {

public:

    // Constructors
    BestSellerList();
    ~BestSellerList();

    // Methods
    BestSellerList* getHead();
    bool InsertHead(BestSellerNode* entry);
    bool InsertTail(BestSellerNode* entry);
    bool AuthorInsert(BestSellerNode* entry);
    bool TitleInsert(BestSellerNode* entry);
    void find_author(const string &author);
    void find_title(const string &title);
    void Print();


private:
    //BestSellerNode *bookNode;
    BestSellerNode *Head, *Tail;
    int Count = 0;

};