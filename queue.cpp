//
// Created by Admin on 2019-02-24.
// Definitionfile

#include "queue.h"

class Node {
public:
    Node *next;
    Item data;
    Node (Node *n, Item newData) : next(n), data(newData) {}
};

// -----Functions for QIterator-----
Item &QIterator::operator*() const {
    return node->data;
}
QIterator &QIterator::operator++() {
    node = node->next;
    return *this;
}
const QIterator QIterator::operator++(int) {
    QIterator qiterator = *this;
    ++*this;
    return qiterator;
}
bool QIterator::operator!=(const QIterator &qi) const {
    return node != qi.node;
}

// -----Functions for Qlist-----
QList::~QList() {
    while(!isEmpty()) {
        Node *tmp = first;
        first = first->next;
        delete tmp;
    }
}
void QList::enque(Item const &newData) {
    Node *pNew = new Node(nullptr, newData);
    if(isEmpty()) {
        first = pNew;
        last = pNew;
    }
    else {
        last->next = pNew;
        last = pNew;
    }
}
bool QList::deque(Item &item) {
    if(isEmpty())
        return false;
    Node *n = first;
    item = n->data;
    first = first->next;
    if(isEmpty()) // List is empty now
        last = nullptr; // =nullptr
    delete n;
    return true;
}
bool QList::del(Item item) {
    if(isEmpty()) {
        return false;
    }
    if(first == last)
        if(first->data == item) {
            Node *n = first;
            first = nullptr;
            last = nullptr;
            delete n;
            return true;
        }
        else {
            return false;
        }
    Node *n1, *n2= nullptr;
    for(n1=first; n1 && n1->data != item; n2=n1, n1=n1->next );
        if (n1 != nullptr) {
            if (n1 == first) // If the first item is to be deleted
                first = first->next;
            else if (n1->next == nullptr) { // If the last item is to be deleted
                n2->next = nullptr;
                last = n2; // Note! Pointing to the last pointer!
            } else // If something other than the first or last element is to be deleted
                n2->next = n1->next;
            delete n1;
            return true;
        }
        else {
            return false;
        }
}
bool QList::isEmpty() const {
    return first== nullptr;
}


