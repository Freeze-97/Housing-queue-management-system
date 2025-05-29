//
// Created by Admin on 2019-02-24.
// queue headerfile

#ifndef LABORATION3_QUEUE_H
#define LABORATION3_QUEUE_H

#include "person.h"

typedef Person Item;
class Node;
class QIterator {
private:
    Node *node;
public:
    QIterator() : node{nullptr} {}; // Förvald konstruktor
    explicit QIterator(Node *n) : node{n} {}; // Initieringskonstruktor
    Item &operator*() const;
    QIterator &operator++(); // prefix ++i
    const QIterator operator++(int); // postfix i++
    bool operator!=(const QIterator &qi) const;
};

// Next class
class QList {
private:
    Node *first, *last;
public:
    QList():first(nullptr),last(nullptr){};
    ~QList();
    void enque(Item const &newData);
    bool deque(Item &item);
    bool del(Item item);
    bool isEmpty()const;

    QIterator begin()const {return QIterator(first);}
    QIterator end() const {return QIterator(nullptr);}
};

#endif //LABORATION3_QUEUE_H
