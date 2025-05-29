//
// Created by Admin on 2019-02-08.
//

#ifndef LABORATION3_NAME_H
#define LABORATION3_NAME_H

#include <vector>
#include <string>
using namespace std;

// Class for name
class Name{
private:
    string firstName; // Members
    string lastName; // Only reachable via member functions

public:
    Name();
    Name(string pFirstName, string pLastName);

    void setFirstName(string pFirstName); // Set the first name
    void setLastName(string pLastName); // Set the last name

    // Used to get the first and last name, const because change is not needed
    string getFirstName() const;
    string getLastName() const;

    bool operator<(Name &name) const; // Less than
    bool operator==(const Name &name) const; // Equal to
    bool operator!=(const Name &name) const; // Not equal to
};
void showName(Name const &name); // Outside class,it will use member function

// Operators
ostream &operator<<(ostream &os, const Name &name);
istream &operator>>(istream &is, Name &name);

#endif //LABORATION3_NAME_H
