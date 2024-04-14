//------------------------------
// Author: Evan Meyers
// UAID: 010955257
//------------------------------

#include <iostream>
#include "dictionary.h"
#include <algorithm>

using namespace std;

//------------------------------------
// Function that cleans the strings
//------------------------------------
string wordClean(string &str) {

    // Lowercases the input str
    for (int x = 0; x < str.length(); x++) {
        str[x] = tolower(str[x]);
    }

    // Removes symbols from str
    str.erase(remove(str.begin(), str.end(), '.'), str.end());
    str.erase(remove(str.begin(), str.end(), '('), str.end());
    str.erase(remove(str.begin(), str.end(), ')'), str.end());
    str.erase(remove(str.begin(), str.end(), ','), str.end());
    str.erase(remove(str.begin(), str.end(), ';'), str.end());
    str.erase(remove(str.begin(), str.end(), '!'), str.end());
    str.erase(remove(str.begin(), str.end(), '"'), str.end());
    str.erase(remove(str.begin(), str.end(), '?'), str.end());
    str.erase(remove(str.begin(), str.end(), '_'), str.end());
    str.erase(remove(str.begin(), str.end(), ':'), str.end());


    return str;
}

int main() {

    float avg;
    int numWords = 0, totDif = 0, usrChoice, wordRes;
    string str, sample;
    dictionary temp;
    temp.ReadFile();

    // Prompt user for input
    cout << "\nChoose a book sample to have its complexity calculated:\n\n"
         << "\t\t(1) The Cat in the Hat\n"
         << "\t\t(2) Alice in Wonderland\n"
         << "\t\t(3) Robinson Crusoe\n"
         << "\t\t(4) The Time Machine\n"
         << "\t\t(5) David Copperfield\n";
    cin >> usrChoice;

    // Error checking on user input
    while (cin.fail() || (usrChoice > 5 || usrChoice < 1)) {
        cerr << "Invalid input. Try again:\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> usrChoice;
    }

    // Assign user input to corresponding sample text files
    if (usrChoice == 1) {
        sample = "sample1.txt";
    }
    else if (usrChoice == 2) {
        sample = "sample2.txt";
    }
    else if (usrChoice == 3) {
        sample = "sample3.txt";
    }
    else if (usrChoice == 4) {
        sample = "sample4.txt";
    }
    else if (usrChoice == 5) {
        sample = "sample5.txt";
    }

    // Create and open sample file the user selected
    ifstream source(sample);
    // Error checking on sample file
    if (source.fail()) {
        cerr << "Could not open file\n";
        return 0;
    }

    // Read words from sample document and compare to the ranked words text file.
    // Uses boolean search method to find word and assigns proper word ranking once word is or isn't found
    while (!source.eof()) {

        source >> str;
        str = wordClean(str);
        wordRes = temp.binarySearch(str, 0, 999);

        // Checks if the word is not within the array, and if not, sets the difficulty of the word to 1001
        if (wordRes == -1) {
            totDif += 1001;
            wordRes = 1001;
            numWords++;
        }
        else {
            totDif += wordRes;
            numWords++;
        }
        cout << str << " " << wordRes << endl;

    }

    avg = (float)totDif / (float)numWords;
    cout << endl << "Number of words: " << numWords << endl << "Average word rank: " << avg << endl;
    source.close();

    return 0;
}

