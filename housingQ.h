//
// Created by Admin on 2019-02-24.
//

#ifndef LABORATION3_HOUSINGQ_H
#define LABORATION3_HOUSINGQ_H

#include "queue.h"
#include <iostream>
#include <string>
#include <fstream>

class HousingQ {
private:
    QList queueList;
    int amountOfPeople = 0;
    string filename;

    void menu();
    void addPerson();
    void offerHouse();
    void showQueue();
    void searchPerson();
    void deletePerson();
    void saveOnFile();
    void loadFile();
public:
    void run();
    HousingQ() = default;
};

#endif //LABORATION3_HOUSINGQ_H
