// Author:  Evan Meyers
// UAID:    010955257

#include <iostream>
#include "stack.h"
using namespace std;

int main() {

    Stack stack;
    string str;
    int num1, num2, res;


    cout << "Enter postfix expression: ";
    cin >> str;

    while (str != "?") {
        // Push ints on stack
        if ((str[0] >= '0') && (str[0] <= '9')) stack.Push(stoi(str));

        // Handle ">"
        else if (str == ">") {
            if (stack.GetLength() < 2) {
                cout << "Error: Not enough data for '" << str << "' operation\n";
                return -1;
            }
            stack.Pop(num2);
            stack.Pop(num1);
            stack.Push(num1 > num2);
        }

        // Handle "<"
        else if (str == "<") {
            if (stack.GetLength() < 2) {
                cout << "Error: Not enough data for '" << str << "' operation\n";
                return -1;
            }
            stack.Pop(num2);
            stack.Pop(num1);
            stack.Push(num1 < num2);
        }

        // Handle "=="
        else if (str == "==") {
            if (stack.GetLength() < 2) {
                cout << "Error: Not enough data for '" << str << "' operation\n";
                return -1;
            }
            stack.Pop(num2);
            stack.Pop(num1);
            stack.Push(num1 == num2);
        }

        // Handle "!="
        else if (str == "!=") {
            if (stack.GetLength() < 2) {
                cout << "Error: Not enough data for '" << str << "' operation\n";
                return -1;
            }
            stack.Pop(num2);
            stack.Pop(num1);
            stack.Push(num1 != num2);
        }

        // Handle ">="
        else if (str == ">=") {
            if (stack.GetLength() < 2) {
                cout << "Error: Not enough data for '" << str << "' operation\n";
                return -1;
            }
            stack.Pop(num2);
            stack.Pop(num1);
            stack.Push(num1 >= num2);
        }

        // Handle "<="
        else if (str == "<=") {
            if (stack.GetLength() < 2) {
                cout << "Error: Not enough data for '" << str << "' operation\n";
                return -1;
            }
            stack.Pop(num2);
            stack.Pop(num1);
            stack.Push(num1 <= num2);
        }

        // Handle "&&"
        else if (str == "&&") {
            if (stack.GetLength() < 2) {
                cout << "Error: Not enough data for '" << str << "' operation\n";
                return -1;
            }
            stack.Pop(num2);
            stack.Pop(num1);
            stack.Push(num1 == 1 && num2 == 1);
        }

        // Handle "||"
        else if (str == "||") {
            if (stack.GetLength() < 2) {
                cout << "Error: Not enough data for '" << str << "' operation\n";
                return -1;
            }
            stack.Pop(num2);
            stack.Pop(num1);
            stack.Push(num1 == 1 || num2 == 1);
        }

        else {
            cout << "Error: Unexpect '" << str << "' in input\n";
            return -1;
        }
        cin >> str;
    }

    // Error checking on stack
    if (stack.GetLength() < 1) {
        cout << "Error: Not enough data for '" << str << "' operation\n";
        return -1;
    }
    else if (stack.GetLength() > 1) {
        cout << "Error: Too much data for '" << str << "' operation\n";
        return -1;
    }

    // Print result
    stack.Pop(res);
    if (res == 0) cout << "Result is false" << endl;
    else if (res == 1) cout << "Result is true" << endl;


    return 0;
}