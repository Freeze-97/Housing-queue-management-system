#include "name.h"
#include <iostream>
#include <fstream>
using namespace std;

// Name member functions
Name::Name(){
    firstName = "Empty";
    lastName = "Empty";
}
Name::Name(string pFirstName, string pLastName) {
    firstName = pFirstName;
    lastName = pLastName;
}
void Name::setFirstName(string pFirstName) {
    firstName = pFirstName;
}
void Name::setLastName(string pLastName) {
    lastName = pLastName;
}
string Name::getFirstName() const {
    return firstName;
}
string Name::getLastName() const {
    return lastName;
}
void showName(Name const &name){
    cout << name.getFirstName() << " ";
    cout << name.getLastName() << endl;
}
const char DELIM = '|';
ostream &operator<<(ostream &os, const Name &name) {
    os << name.getFirstName() << DELIM;
    os << name.getLastName() << DELIM;
    return os;
}
istream &operator>>(istream &is, Name &name){
    string tmpFirstName, tmpLastName;
    getline(is, tmpFirstName, DELIM);
    getline(is, tmpLastName, DELIM);
    name.setFirstName(tmpFirstName);
    name.setLastName(tmpLastName);
    return is;
}
bool Name::operator<(Name &name) const {
    if(lastName == name.lastName){
        return firstName < name.firstName;
    }
    return lastName < name.lastName;
}
bool Name::operator==(const Name &name) const {
    return firstName == name.firstName && lastName == name.lastName;
}
bool Name::operator!=(const Name &name) const {
    return firstName != name.firstName && lastName != name.lastName;
}
