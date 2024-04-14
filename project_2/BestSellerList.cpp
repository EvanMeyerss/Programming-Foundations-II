// Author:  Evan Meyers
// UAID:    010955257
#include "BestSellerList.h"

BestSellerList::BestSellerList() {

}

BestSellerList::~BestSellerList() {}


// Methods

// Node Head insert method
bool BestSellerList::InsertHead(BestSellerNode* entry) {

    // Create new node
    BestSellerNode* tmpNode = new BestSellerNode();
    *tmpNode = *entry;
    tmpNode->setNext(Head);

    // Insert new node
    Head = tmpNode;


    return true;
}

// Node Tail insert method
bool BestSellerList::InsertTail(BestSellerNode* entry) {
    // Find tail node
    BestSellerNode *ptr = Head;
    while ((ptr != nullptr) && (ptr->getNext() != nullptr))
        ptr = ptr -> getNext();

    // Create new node
    BestSellerNode* tmpNode = new BestSellerNode();
    *tmpNode = *entry;
    tmpNode ->setNext(nullptr);

    // Insert new node
    if (ptr != nullptr)
        ptr ->setNext(tmpNode);
    else
        Head = tmpNode;

    return true;
}

bool BestSellerList::AuthorInsert(BestSellerNode* entry) {

    // Walk the list to insertion point
    BestSellerNode* curr = Head;
    BestSellerNode* prev = Head;
    while ((curr!=nullptr) && (curr->getAuthor().compare(entry->getAuthor()) < 0)) {
        prev = curr;
        curr = curr->getNext();
    }

    // Create a new node and connect to current node
    BestSellerNode* ptr = new BestSellerNode();
    *ptr = *entry;
    ptr->setNext(curr);

    // Connect previous node to new node
    if (prev == Head)
        Head = ptr;
    else
        prev->setNext(ptr);


    /*
    // Temporary Printer.
    // Delete for final version
    BestSellerNode *ptr2 = Head;
    if (Count < 20) {

        while (ptr2 != nullptr) {
            ptr2->print();
            cout << endl;
            ptr2 = ptr2->getNext();
        }
    }
    Count++;
    */

    return false;
}

bool BestSellerList::TitleInsert(BestSellerNode* entry) {

    // Walk the list to insertion point
    BestSellerNode* curr = Head;
    BestSellerNode* prev = Head;
    while ((curr!=nullptr) && (curr->getTitle().compare(entry->getTitle()) < 0)) {
        prev = curr;
        curr = curr->getNext();
    }

    // Create a new node and connect to current node
    BestSellerNode* ptr = new BestSellerNode();
    *ptr = *entry;
    ptr->setNext(curr);

    // Connect previous node to new node
    if (prev == Head)
        Head = ptr;
    else
        prev->setNext(ptr);

    return false;
}

void BestSellerList::Print(){}


// Finder Methods
void BestSellerList::find_author(const string &author)
{
    // Walk the list to desired value
    BestSellerNode* temp = Head;
    while (temp != nullptr) {
        if (temp->getAuthor() == author) {
            temp->print();
            cout << endl;
        }
        temp = temp->getNext();
    }


    if (temp==nullptr)
        cout << "The author, " << author << ", is not found within the list.\n\n";

}

void BestSellerList::find_title(const string &title)
{

}