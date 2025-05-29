//
// person.cpp
// Person member functions added with Address and Name

#include "person.h"
#include <iostream>
using namespace std;

// All functions for person
Person::Person() {
    persNr = " ";
    skoNr = 0;
}
Person::Person(Name pName, Address pAddress, string pPersNr, int pSkoNr) {
    name = pName;
    address = pAddress;
    persNr = pPersNr;
    skoNr = pSkoNr;
}

void Person::setName(Name pName) {
    name = pName;
}
void Person::setAddress(Address pAddress) {
    address = pAddress;
}

void Person::setPersNr(string pPersNr) {
    persNr = pPersNr;
}
void Person::setSkoNr(int pSkoNr) {
    skoNr = pSkoNr;
}
Name Person::getName() const {
    return name;
}
Address Person::getAddress() const {
    return address;
}
string Person::getPersNr() const {
    return persNr;
}
int Person::getSkoNr() const {
    return skoNr;
}
bool Person::operator<(Person &person) const {
    if(name == person.name) {
        return address < person.address;
    }
    return name < person.name;
}
bool Person::operator==(const Person &person) const {
    return name == person.name && address == person.address && persNr == person.persNr && skoNr == person.skoNr;
}
const char DELIM = '|';
ostream &operator<<(ostream &os, const Person &person) {
    os << person.getName();
    os << person.getAddress();
    os << person.getPersNr() << DELIM;
    os << person.getSkoNr();
    return os;
}
istream &operator>>(istream &is, Person &person) {
    Name tmpName;
    Address tmpAddress;
    string tmpPersNr;
    int tmpSkoNr;

    is >> tmpName;
    is >> tmpAddress;
    getline(is, tmpPersNr, DELIM);
    is >> tmpSkoNr;
    is.get();

    person.setName(tmpName);
    person.setAddress(tmpAddress);
    person.setPersNr(tmpPersNr);
    person.setSkoNr(tmpSkoNr);

    return is;
}
bool Person::operator!=(const Person &person) const {
    return name != person.name && address != person.address && persNr != person.persNr && skoNr != person.skoNr;
}

