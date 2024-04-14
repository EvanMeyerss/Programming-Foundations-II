//------------------------------
// Author: Evan Meyers
// UAID: 010955257
//------------------------------

#include "dictionary.h"
using namespace std;
//------------------------------
//Constructor function
//------------------------------
dictionary::dictionary() {
    // Initialize word array
    count = 0;
    for (int i = 0; i < NUM_WORDS; i++)
        word[i][0] = "";
}

//------------------------------
// Copy constructor
//------------------------------
dictionary::dictionary(const dictionary &copy) {
    // Initialize word array
    count = copy.count;
    for (int i = 0; i < NUM_WORDS; i++) {
        word[i][0] = copy.word[i][0];
        word[i][1] = copy.word[i][1];
    }
}

//------------------------------
// Destructor function
//------------------------------
dictionary::~dictionary() {}

//------------------------------
// Read words into dictionary
//------------------------------
void dictionary::ReadFile() {

    //-----------------------------
    // Open rank.txt file
    //-----------------------------
    ifstream rank("words.txt");
    if (rank.fail()) {
        cerr << "Could not open file\n";
        return;
    }
    // Read strings into word array
    count = 0;
    string num;
    string str;
    rank >> num >> str;
    while (!rank.eof() && count < NUM_WORDS) {
        word[count][0] = num;
        word[count][1] = str;
        rank >> num >> str;
        count++;
    }
    rank.close();
}


//------------------------------
// Look up words in dictionary
//------------------------------
int dictionary::binarySearch(const string& name, const int &low, const int &high) {
    // Calculate midpoint index
    int mid = (low + high) / 2;

    // Check termination conditions
    if (low > high)
        return -1;
    else if (word[mid][1] == name)
        return stoi(word[mid][0]);

        // Handle recursive cases
    else if (word[mid][1].compare(name) > 0)
        return binarySearch(name, low, mid - 1);
    else
        return binarySearch(name, mid + 1, high);
}