//
// Created by Admin on 2019-02-08.
//

#ifndef LABORATION3_ADDRESS_H
#define LABORATION3_ADDRESS_H

#include <vector>
#include <string>
using namespace std;
// Class for address
class Address {
private:
    string streetAddress; // Data-members
    string postNum;
    string city;

public:
    Address(); // The default constructor
    Address(string pStreetAddress, string pPostNum, string pCity);

    void setStreetAddress(string pStreetAddress); // Give members addresses
    void setPostNum(string pPostNum);
    void setCity(string pCity);

    string getStreetAddress() const; // Get addresses from the members
    string getPostNum() const;
    string getCity() const;

    bool operator<(Address &address) const; // Less than
    bool operator==(const Address &address) const; // Equal to
    bool operator!=(const Address &address) const; // Not equal to
};
void showAddress(Address const &address);

ostream &operator<<(ostream &os, const Address &address);
istream &operator>>(istream &is, Address &address);

#endif //LABORATION3_ADDRESS_H
