//
// Created by Admin on 2019-02-08.
//

#ifndef LABORATION3_PERSON_H
#define LABORATION3_PERSON_H

#include "address.h"
#include "name.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Class for person
class Person{
private:
    // Data members
    Name name;
    Address address;
    string persNr;
    int skoNr;

public:
    Person(); // Pre constructor
    Person(Name pName, Address pAddress, string pPersNr, int pSkoNr);// Constructor with parameters

    void setName(Name pName);
    void setAddress(Address pAddress);
    void setPersNr(string pPersNr);
    void setSkoNr(int pSkoNr);

    Name getName() const;
    Address getAddress() const;
    string getPersNr() const;
    int getSkoNr() const;

    //Operator
    bool operator<(Person &person) const; // Less than
    bool operator==(const Person &person) const; // Equal to
    bool operator!=(const Person &person) const; // Not equal to
};

ostream &operator<<(ostream &os, const Person &person);
istream &operator>>(istream &is, Person &person);

#endif //LABORATION3_PERSON_H
