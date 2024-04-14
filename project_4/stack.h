// Author:  Evan Meyers
// UAID:    010955257

#include <cmath>
#include <iostream>
using namespace std;

struct StackNode {
    int num;
    StackNode *Next;
};

class Stack {

public:
    //Constructors
    Stack();
    Stack(const Stack &stack);
    ~Stack();

    //Methods
    bool IsFull();
    bool IsEmpty();
    void Push(int num);
    void Pop(int &num);
    void Top(int &num);
    int GetLength();
    void Print();

private:
    StackNode *Head;
    int Length;

};


