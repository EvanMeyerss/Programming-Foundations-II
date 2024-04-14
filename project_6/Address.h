// Author:  Evan Meyers
// UAID:    010955257

#ifndef PROJECT_6_ADDRESS_H
#define PROJECT_6_ADDRESS_H

#include <string>
#include <iostream>

using namespace std;



class Address {

public:

    // Structs
    Address();
    Address(const float &LAT, const float &LON, const int &NUN, const string &NAME);
    Address(const Address &Address);
    ~Address();

    // Methods
    float getLat() const;
    float getLong() const;
    int getNum() const;
    string getName();
    string getNameK();

    void setLat(const float &LAT);
    void setLong(const float &LON);
    void setNum(const int &NUM);
    void setName(const string &NAME);
    void setNameK(int NUM, const string &NAME);

    void Print();


private:
    float lat, lon;
    string name, nameK;
    int num;
};


#endif //PROJECT_6_ADDRESS_H
