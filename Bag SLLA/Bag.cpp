#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
    capacity = 10; 
    nodes = new Node[capacity];
    head = -1;
    count = 0;

    firstEmpty = 0;
    for (int i = 0; i < capacity - 1; i++) {
        nodes[i].next = i + 1;
    }
    nodes[capacity - 1].next = -1;
}

void Bag::add(TElem e) {
    if (firstEmpty == -1) {
        resize();
    }

    int newPos = firstEmpty;
    firstEmpty = nodes[firstEmpty].next;

    nodes[newPos].data = e;
    nodes[newPos].next = head;
    head = newPos;
    count++;
}

bool Bag::remove(TElem e) {
    int current = head;
    int prev = -1;

    while (current != -1) {
        if (nodes[current].data == e) {
            if (prev == -1) {
                head = nodes[current].next;
            }
            else {
                nodes[prev].next = nodes[current].next;
            }

            nodes[current].next = firstEmpty;
            firstEmpty = current;

            count--;
            return true;
        }
        prev = current;
        current = nodes[current].next;
    }

    return false;
}

bool Bag::search(TElem e) const {
    int current = head;
    while (current != -1) {
        if (nodes[current].data == e) {
            return true;
        }
        current = nodes[current].next;
    }
    return false;
}

int Bag::nrOccurrences(TElem e) const {
    int occurrences = 0;
    int current = head;
    while (current != -1) {
        if (nodes[current].data == e) {
            occurrences++;
        }
        current = nodes[current].next;
    }
    return occurrences;
}

int Bag::size() const {
    return count;
}

bool Bag::isEmpty() const {
    return count == 0;
}

Bag::~Bag() {
    delete[] nodes;
}

void Bag::resize() {
    int newCapacity = capacity * 2;
    Node* newNodes = new Node[newCapacity];

    for (int i = 0; i < capacity; i++) {
        newNodes[i] = nodes[i];
    }

    for (int i = capacity; i < newCapacity - 1; i++) {
        newNodes[i].next = i + 1;
    }
    newNodes[newCapacity - 1].next = -1;

    firstEmpty = capacity;
    capacity = newCapacity;
    delete[] nodes;
    nodes = newNodes;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


