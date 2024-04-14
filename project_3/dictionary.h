//------------------------------
// Author: Evan Meyers
// UAID: 010955257
//------------------------------
using namespace std;

#include <iostream>
#include <fstream>
#include <string>

const int NUM_WORDS = 1000;
class dictionary {
public:
  dictionary();
  dictionary(const dictionary &copy);
  ~dictionary();

  void ReadFile();
  int binarySearch(const string& name, const int &low, const int &high);


private:
  int count;
  string word[NUM_WORDS][2];


};