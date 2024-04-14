// Author:  Evan Meyers
// UAID:    010955257

#include "HashTable.h"

using namespace std;


// Constructor
HashTable::HashTable(const int &SIZE) {
    Size = SIZE;
    Count = 0;
    Status = new char[Size];
    Value = new Address[Size];
    Key = new string[Size];

    for (int index = 0; index < Size; index++)
    {
        Status[index] = EMPTY;
        Key[index] = "";
    }
}

// Destructor
HashTable::~HashTable() {
    if (Status != nullptr)
        delete[]Status;
    if (Value != nullptr)
        delete[]Value;
    if (Key != nullptr)
        delete[]Key;
    Status = nullptr;
    Value = nullptr;
    Key = nullptr;
    Size = 0;
}

//-------------------------------------------

// insertAddress()
bool HashTable::Insert(string key, const Address &address) {
    // Check hash table overflow
    if (Count + 1 >= Size)
        return false;

    // Find desired key
    int index = Hash(key);
    while ((Key[index] != key) && (Status[index] != EMPTY))
        index = Hash2(index);

    // Insert value into hash table
    if (Key[index] == key)
    {
        Value[index] = address;
        return true;
    }

    // Find unoccupied location
    index = Hash(key);
    while (Status[index] == FULL) {
        index = Hash2(index);
        colCount++;
    }

    // Insert value into hash table
    Status[index] = FULL;
    Value[index] = address;
    Key[index] = key;
    Count++;
    return true;

}

// searchName()
int HashTable::Search(const string &key, Address &name) {
    // Find desired key
    int index = Hash(key);
    while ((Key[index] != key) && (Status[index] != EMPTY))
        index = Hash2(index);

    // Return value from hash table
    if (Key[index] == key)
        name = Value[index];
    return (Key[index] == key);
}

// Hash()
int HashTable::Hash(string key)  {
    long int num = 0;
    for (int i = 0; i < int(key.length()); i++)
        num += key[i];
    return num % Size;
}

// Hash2()
int HashTable::Hash2(int index)  {
    return (index + 1) % Size;
}

void HashTable::Print()
{
    cout << "Index\t" << "Status\t" << "Value\t" << "Key\n";
    for (int index = 0; index < Size; index++) {
        cout << index << "\t" << Status[index] << "\t";
//        Value[index].Print();
        cout << "\t" << Key[index] << "\n";
    }
    cout << "Count = " << Count << "\nCollisions: " << colCount << endl;
}

