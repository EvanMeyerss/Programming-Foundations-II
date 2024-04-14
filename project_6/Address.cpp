// Author:  Evan Meyers
// UAID:    010955257

#include "Address.h"


// Default constructor
Address::Address() {
    lat = 0;
    lon = 0;
    num = 0;
    name = "";
}

// Default constructor
Address::Address(const float &LAT, const float &LON, const int &NUM, const string &NAME) {
    lat = LAT;
    lon = LON;
    num = NUM;
    name = NAME;
}

// Copy constructor
Address::Address(const Address &Address) {
    lat = Address.lat;
    lon = Address.lon;
    num = Address.num;
    name = Address.name;
}


// Destructor
Address::~Address()= default;

// ------------------------------------------------

// getLat()
float Address::getLat() const {
    return lat;
}

// getLong()
float Address::getLong() const {
    return lon;
}

// getNum()
int Address::getNum() const {
    return num;
}

// getName()
string Address::getName() {
    return name;
}

// getNameK()
string Address::getNameK() {
    return nameK;
}

// setLat()
void Address::setLat(const float &LAT) {
    lat = LAT;
}

// setLong()
void Address::setLong(const float &LON) {
    lon = LON;
}

// setNum()
void Address::setNum(const int &NUM) {
    num = NUM;
}

// setName()
void Address::setName(const string &NAME) {
    name = NAME;
}

// setNameK()
void Address::setNameK(int NUM, const string &NAME) {
    nameK = to_string(NUM) + ' ' + NAME;
    nameK.pop_back();
}

// Print()
void Address::Print() {
    cout << endl
         << "Latitude: " << lat << endl
         << "Longitude: " << lon << endl
         << "House Number: " << num << endl
         << "Street Name: " << name << endl << endl;
}


