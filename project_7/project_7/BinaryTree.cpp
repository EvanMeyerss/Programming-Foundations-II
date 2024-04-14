// Author:  Evan Meyers
// UAID:    010955257

#include "BinaryTree.h"

// Constructor
BinaryTree::BinaryTree() {
    Root = nullptr;
}

// Destructor
BinaryTree::~BinaryTree() {

}

// SearchHelper()
bool BinaryTree::SearchHelper(const string &key, Node *Tree) {
    srchRec++;
    // Data value not found
    if (Tree == nullptr)
        return false;

        // Data value found
    else if (Tree->Value.getKey() == key) {
        Tree->Value.Print();
        return true;
    }

        // Recursively search for data value
    else if (Tree->Value.getKey() > key)
        return (SearchHelper(key, Tree->Left));
    else

        return (SearchHelper(key, Tree->Right));

}

// Search()
bool BinaryTree::Search(const string &key) {
    // Call tree searching function
    return (SearchHelper(key, Root));
}

// InsertHelper()
bool BinaryTree::InsertHelper(const Address& add, Node *&Tree) {
    insRec++;
    // Insert data into the tree
    if (Tree == nullptr)
    {
        Tree = new Node;
        Tree->Value = add;
        Tree->Left = nullptr;
        Tree->Right = nullptr;
        return true;
    }

        // Data value already inserted
    else if (Tree->Value.Compare(add) == 0)
        return false;

        // Recursively search for insertion position
    else if (Tree->Value.Compare(add) == 1)
        return (InsertHelper(add, Tree->Left));
    else if (Tree->Value.Compare(add) == -1)
        return (InsertHelper(add, Tree->Right));

}

// Insert()
bool BinaryTree::Insert(const Address& add) {
    // Call tree insertion function
    return (InsertHelper(add, Root));
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(Node* Tree) {
    // Check terminating condition
    if (Tree != nullptr) {
        // Print left subtree with brackets
        if (Tree->Left != nullptr) {
            cout << "(";
            PrintHelper(Tree->Left);
            cout << ")";
        }

        // Print node value
        Tree->Value.Print();
        
        // Print right subtree with brackets
        if (Tree->Right != nullptr) {
            cout << "(";
            PrintHelper(Tree->Right);
            cout << ")";
        }
    }
}

// getRec()
int BinaryTree::getRec() {
    return insRec;
}

// getSrch()
int BinaryTree::getSrch() {
    return srchRec;
}

//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BinaryTree::Print()
{
    // Call tree printing function
    PrintHelper(Root);
    cout << endl;
}