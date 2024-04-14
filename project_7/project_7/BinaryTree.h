// Author:  Evan Meyers
// UAID:    010955257

#ifndef PROJECT_7_BINARYTREE_H
#define PROJECT_7_BINARYTREE_H

#include "Address.h"

// Data node definition
class Node
{
public:
    Address Value;
    Node *Left;
    Node *Right;
};


class BinaryTree {

public:
    BinaryTree();
    ~BinaryTree();

    // Methods
    bool Insert(const Address& Value);
    bool Search(const string &key);
    int getRec();
    int getSrch();
    void Print();


private:
    // Helper functions
    bool SearchHelper(const string &key, Node * Tree);
    bool InsertHelper(const Address& Value, Node * &Tree);
    void PrintHelper(Node *Tree);

    int insRec = 0, srchRec = 0;

    // Tree pointer
    Node *Root;
};


#endif //PROJECT_7_BINARYTREE_H
