#include <iostream>
#include <fstream>
#include <string>
#include "BinaryTree.h"

int main() {

    Address add1, add2;

    // Initialize variables
    Address map;
    BinaryTree tree;
    ifstream din;
    string sTemp, usrSearch, usrTxt;
    float fTemp, avgCall;
    int iTemp, insNum = 0, redo = 0;

    cout << "Enter name of address file:\n"; cin >> usrTxt;


    din.open(usrTxt);

    if (din.is_open()) {
        // Read file info
        while (!din.eof()) {
            insNum++;
            // Set latitude
            getline(din, sTemp, ' ');
            fTemp = stof(sTemp);
            map.setLat(fTemp);

            // Set longitude
            getline(din, sTemp, ' ');
            fTemp = stof(sTemp);
            map.setLong(fTemp);

            // Set street num
            getline(din, sTemp, ' ');
            iTemp = stoi(sTemp);
            map.setNum(iTemp);

            // Set street name
            getline(din, sTemp);
            map.setName(sTemp);


            map.setKey(iTemp, sTemp);
            tree.Insert(map);
        }
    }

    // Prints statistics of data insertion
    avgCall = (float)tree.getRec() / (float)insNum;
    cout << "Number of addresses inserted: " << insNum
         << "\nNumber of recursive calls: " << tree.getRec()
         << "\nAverage calls per insert: " << avgCall << endl;


    do {
        // Prompt user to search address
        cout << "\nEnter house number and street name:\n";
        cin.ignore();
        getline(cin, usrSearch);
        if (tree.Search(usrSearch)) {
            cout << "Number of recursive calls: " << tree.getSrch() << endl;
        }
        else {
            cout << "Address not found!\n";
        }

        cout << "\nWould you like to search for another address? (Yes = 1, No = 0);\n";
        cin >> redo;
        // Error checking on user input
        while (cin.fail() || (redo > 1 || redo < 0)) {
            cerr << "Invalid input. Try again:\n";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> redo;
        }
    }
    while (redo == 1);





    return 0;
}
