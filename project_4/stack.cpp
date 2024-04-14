// Author:  Evan Meyers
// UAID:    010955257

#include "stack.h"

// Constructor
Stack::Stack() {
    Head = nullptr;
    Length = 0;
}

// Copy Constuctor
Stack::Stack(const Stack &stack) {

    // First Node
    StackNode *copy = new StackNode();
    Head = copy;

    // Walk the list and copy
    StackNode *ptr = stack.Head;
    while (ptr != nullptr) {
        copy -> Next = new StackNode();
        copy = copy -> Next;
        copy -> num = ptr -> num;
        copy -> Next = nullptr;
        ptr = ptr -> Next;
    }

    // Fix first node
    copy = Head;
    Head = copy -> Next;
    delete copy;
}

// Destructor
Stack::~Stack() {
    // Walk stack deleting data
    while (Head != nullptr) {
        StackNode *Temp = Head;
        Head = Head -> Next;
        delete Temp;
    }

    // Reset head
    Head = nullptr;
    Length = 0;
}

// Check if stack is full
bool Stack::IsFull() {
    return (false);
}

// Check if stack is empty
bool Stack::IsEmpty() {
    return (Length == 0);
}

// Push data into the stack
void Stack::Push(int num) {
    // Check for full stack
    if (IsFull()) return;

    // Allocate space for data
    StackNode *Temp = new StackNode;
    if (Temp == nullptr) return;

    // Insert data at head of list
    Temp -> num = num;
    Temp -> Next = Head;
    Head = Temp;
    Length++;
}

// Pop Method
void Stack::Pop(int &num) {
    // Check if stack is empty
    if (IsEmpty()) return;

    // Extract info from node
    num = Head -> num;

    // Pop item from linked list
    StackNode *Temp = Head;
    Head = Head -> Next;
    delete Temp;
    Length--;
}

// Show data from top of stack
void Stack::Top(int &num) {
    // Check if stack is empty
    if (IsEmpty()) return;

    // Return info from node
    num = Head -> num;
}

// Return stack length
int Stack::GetLength() {
    return Length;
}

// Print all records in stack
void Stack::Print() {
    // Walk the stack and print data
    cout << "stack: ";
    StackNode *Temp = Head;
    while (Temp != nullptr) {
        cout << Temp -> num << " ";
        Temp = Temp -> Next;
    }
    cout << endl;
}