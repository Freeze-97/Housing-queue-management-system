# 🏠 Housing Queue Managment System


## 📋 Description

This program is a **command-line system for managing a housing queue**. It allows users to:

- Add people to the housing queue
- Offer housing to the first person in line
- View the entire queue
- Search for a specific person by social security number
- Delete a person from the queue
- Save and load the queue from a file

The queue is implemented using a custom linked list structure. Each person contains personal information such as name, address, social security number, and shoe size.

## 📂 Files

- `main.cpp` – Program entry point. Starts the system using `HousingQ`.
- `housingQ.h/cpp` – Handles the application logic and user menu.
- `person.h/cpp` – Defines a `Person` object.
- `name.h/cpp` – Defines a `Name` object used in `Person`.
- `address.h/cpp` – Defines an `Address` object used in `Person`.
- `queue.h/cpp` – Custom linked list queue implementation.

## 🧑‍💻 Features

- Add new people to the queue with full details
- Automatically offer a house to the next person in line
- View all people currently in the queue
- Search for individuals by their social security number
- Remove people from the queue
- Save queue state to a file and load it at startup

## 🖥️ Menu Options

MAIN MENU
1: Add a person.
2: Offer a house to the first person in the queue.
3: Print the list of people.
4: Print information about one person.
5: Delete person from queue.
6: Save queue to file.
q: Exit program.

## 💾 File Storage

- The queue is saved to a user-defined text file.
- Each person's data is stored in one line.
- When the program starts, it asks for the file name and loads data from it (if available).

## 🛠️ Compile and Run

### Compile (Linux/macOS):
```bash
g++ main.cpp housingQ.cpp person.cpp name.cpp address.cpp queue.cpp -o housing_queue
./housing_queue
```

### Compile (Windows):
```bash
g++ main.cpp housingQ.cpp person.cpp name.cpp address.cpp queue.cpp -o housing_queue.exe
housing_queue.exe
```
