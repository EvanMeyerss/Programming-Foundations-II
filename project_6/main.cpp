// Author:  Evan Meyers
// UAID:    010955257

#include <iostream>
#include "HashTable.h"
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {

    // Initialize variables
    const int SIZE = 33129;
    Address map;
    HashTable table(SIZE);
    ifstream din;
    string sTemp, usrSearch;
    float fTemp;
    int iTemp;
    int addPlusOne, addPlusTwo, addMinusOne, addMinusTwo, intAddNum;
    string addNum, addRest;
    string searchPlusOne, searchPlusTwo, searchMinusOne, searchMinusTwo;


    din.open("address.txt");

    if (din.is_open()) {
        // Read file info
//        while (!din.eof()) {
        for (int x = 0; x < SIZE; x++) {
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


            map.setNameK(iTemp, sTemp);
            table.Insert(map.getNameK(), map);
        }
    }

    // Prints entire hash table of addresses
    // table.Print();
    cout << "Search for address: \n";
    getline(cin, usrSearch);
    if (table.Search(usrSearch, map)) {
        cout << "Address found!" << endl;
        map.Print();
    }
    else {
        cout << "Address not found\n\n" << "Searching for nearby addresses... \n";
        for ( int x = 0; x < usrSearch.length(); x++) {
            if((usrSearch[x] >= '0') && (usrSearch[x] <= '9')) {
                addNum += usrSearch[x];
            }
            else {
                addRest += usrSearch[x];
            }
        }
        intAddNum = stoi(addNum);
        addPlusOne = intAddNum + 1;
        addPlusTwo = intAddNum + 2;
        addMinusOne = intAddNum - 1;
        addMinusTwo = intAddNum - 2;

        searchPlusOne = to_string(addPlusOne) + addRest;
        searchPlusTwo = to_string(addPlusTwo) + addRest;
        searchMinusOne = to_string(addMinusOne) + addRest;
        searchMinusTwo = to_string(addMinusTwo) + addRest;

        if (table.Search(searchMinusTwo, map)) map.Print();
        if (table.Search(searchMinusOne, map)) map.Print();
        if (table.Search(searchPlusOne, map)) map.Print();
        if (table.Search(searchPlusTwo, map)) map.Print();
        if (!(table.Search(searchPlusTwo, map)) && !(table.Search(searchPlusOne, map)) && !(table.Search(searchMinusOne, map)) && !(table.Search(searchMinusTwo, map))) {
            cout << "No nearby addresses found\n";
        }
    }


    return 0;
}
