//
// Created by Admin on 2019-02-26.
// Definitionfile for housingQ
#include "housingQ.h"

void HousingQ::run() {
    cout << "Give the file a name: " << endl;
    string pFilename;
    cin >> pFilename;
    filename = pFilename;
    loadFile();  // Laddar in personer från listan
    menu();
}
void HousingQ::menu() {
    bool repeat = true;
    do {
        cout << endl;
        cout << "MAIN MENU" << endl;
        cout << "1: Add a person." << endl;
        cout << "2: Offer a house to the first person in the queue" << endl;
        cout << "3: Print the list of people." << endl;
        cout << "4: Print information about one person." << endl;
        cout << "5: Delete person from queue" << endl;
        cout << "6: Save queue to file" << endl;
        cout << "q: Exit program." << endl;

        char ch;
        cin >> ch;
        cin.get();
        switch (ch) {
            case '1': addPerson();
                break;
            case '2': offerHouse();
                break;
            case '3': showQueue();
                break;
            case '4': searchPerson();
                break;
            case '5': deletePerson();
                break;
            case '6': saveOnFile();
                break;
            case 'q': repeat = false;
                break;
            default:
                cout << "Invalid input!" << endl;
        }
    }while(repeat);
}
void HousingQ::addPerson() {
    string firstName;
    cout << "First Name: ";
    getline(cin, firstName);
    string lastName;
    cout << "Last Name: ";
    getline(cin, lastName);
    Name name{firstName, lastName};

    string streetAddress;
    cout << "Street address: ";
    getline(cin, streetAddress);
    string postNum;
    cout << "Zip code: ";
    getline(cin, postNum);
    string city;
    cout << "City: ";
    getline(cin, city);
    Address address{streetAddress, postNum, city};

    string persNr;
    cout << "Social security number: ";
    getline(cin, persNr);

    int shoeNr;
    cout << "Shoe size: ";
    cin >> shoeNr;
    cin.get();

    queueList.enque(Person(name, address, persNr, shoeNr));
    amountOfPeople++;
}
void HousingQ::offerHouse() {
    Person person;
    if (!queueList.deque(person)) {
        cout << "No person in the list!" << endl;
        return;
    }
    cout << "Offered a house to: " << endl;
    cout << "Name         : ";
    showName (person.getName());
    cout << "Address      : ";
    showAddress (person.getAddress());
    cout << "Social number: " << person.getPersNr() << endl;
    cout << "Shoe size    : " << person.getSkoNr() << endl << endl;

    amountOfPeople--;
}
void HousingQ::showQueue() {
    if(queueList.isEmpty()){
        cout << "The list is empty!" << endl;
    }
    else {
        cout << "Amount of people in the list: " << amountOfPeople << endl;
        int i = 0;
        for (auto &person : queueList) {
            cout << "Queue number: " << ++i << endl;
            cout << "Name         : ";
            showName(person.getName());
            cout << "Address      : ";
            showAddress(person.getAddress());
            cout << "Social number: " << person.getPersNr() << endl;
            cout << "Shoe size    : " << person.getSkoNr() << endl << endl;
        }
    }
}
void HousingQ::searchPerson() {
    if(queueList.isEmpty()){
        cout << "The list is empty!" << endl;
        return;
    }

    string searchPersNr;
    cout << "Search by typing in the social security number: " << endl;
    getline(cin, searchPersNr);

    int i = 0;
    for (auto &person : queueList){
        if(searchPersNr == person.getPersNr()){
            cout << "Queue number: " << ++i << endl;
            cout << "Name         : ";
            showName(person.getName());
            cout << "Address      : ";
            showAddress(person.getAddress());
            cout << "Social number: " << person.getPersNr() << endl;
            cout << "Shoe size    : " << person.getSkoNr() << endl << endl;
            return;
        }
    }
    cout << "The person you searched for is not in the list!" << endl;
}
void HousingQ::deletePerson() {
    if(queueList.isEmpty()){
        cout << "The list is empty!" << endl;
        return;
    }

    string searchPersNr;
    cout << "Search by typing in the social security number: " << endl;
    getline(cin, searchPersNr);

    for (auto &person : queueList){
        if(searchPersNr == person.getPersNr()){
            cout << "Name         : ";
            showName(person.getName());
            cout << "Address      : ";
            showAddress(person.getAddress());
            cout << "Social number: " << person.getPersNr() << endl;
            cout << "Shoe size    : " << person.getSkoNr() << endl << endl;

            queueList.del(person);
            amountOfPeople--;
            return;
        }
    }
    cout << "The person you searched for is not in the list!" << endl;
}
void HousingQ::saveOnFile() {
    ofstream of(filename);
    for (auto &person : queueList){
        of << person << endl;
    }
    cout << "Saved to file!" << endl;
}
void HousingQ::loadFile() {
    std::ifstream list(filename);
    if (list.is_open()) {
        Item temp;
        while (list >> temp) {
            queueList.enque(temp);
            amountOfPeople++;
        }
        list.close();
    }
}