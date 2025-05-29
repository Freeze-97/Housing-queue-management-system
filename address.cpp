//
// Created by Admin on 2019-02-06.
//
#include "address.h"
#include <iostream>
using namespace std;

// Address member functions
Address::Address() {
    streetAddress = "Empty";
    postNum = "Empty";
    city = "Empty";
}
Address::Address(string pStreetAddress, string pPostNum, string pCity) {
    streetAddress = pStreetAddress;
    postNum = pPostNum;
    city = pCity;
}
void Address::setStreetAddress(string pStreetAddress) {
    streetAddress = pStreetAddress;
}
void Address::setPostNum(string pPostNum) {
    postNum = pPostNum;
}
void Address::setCity(string pCity) {
    city = pCity;
}
string Address::getStreetAddress() const {
    return streetAddress;
}
string Address::getPostNum() const {
    return postNum;
}
string Address::getCity() const {
    return city;
}
void showAddress(Address const &address) {
    cout << address.getStreetAddress() << ", ";
    cout << address.getPostNum() << ", ";
    cout << address.getCity() << endl;
}
bool Address::operator<(Address &address) const {
    if(city == address.city) {
        return streetAddress < address.streetAddress;
    }
    return city < address.city;
}
bool Address::operator==(const Address &address) const {
    return streetAddress == address.streetAddress && city == address.city && postNum == address.postNum;
}
const char DELIM = '|';
ostream &operator<<(ostream &os, const Address &address) {
    os << address.getStreetAddress() << DELIM;
    os << address.getPostNum() << DELIM;
    os << address.getCity() << DELIM;
    return os;
}
istream &operator>>(istream &is, Address &address){
    string tmpStreetAddress, tmpPostNum, tmpCity;

    getline(is, tmpStreetAddress, DELIM);
    getline(is, tmpPostNum, DELIM);
    getline(is, tmpCity, DELIM);

    address.setStreetAddress(tmpStreetAddress);
    address.setPostNum(tmpPostNum);
    address.setCity(tmpCity);

    return is;
}
bool Address::operator!=(const Address &address) const {
    return streetAddress != address.streetAddress && city != address.city && postNum != address.postNum;
}

