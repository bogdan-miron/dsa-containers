#include "Matrix.h"
#include <exception>

Matrix::Matrix(int nrLines, int nrCols)
    : numLines(nrLines), numCols(nrCols), capacity(13), size(0) {
    buckets = new Node * [capacity]();
}

int Matrix::nrLines() const {
    return numLines;
}

int Matrix::nrColumns() const {
    return numCols;
}

TElem Matrix::element(int i, int j) const {
    if (i < 0 || i >= numLines || j < 0 || j >= numCols) {
        throw std::exception();
    }

    int hash = (i * 31 + j) % capacity;
    Node* current = buckets[hash];
    while (current != nullptr) {
        if (current->i == i && current->j == j) {
            return current->value;
        }
        if (current->i > i || (current->i == i && current->j > j)) {
            break;
        }
        current = current->next;
    }
    return NULL_TELEM;
}

TElem Matrix::modify(int i, int j, TElem e) {
    if (i < 0 || i >= numLines || j < 0 || j >= numCols) {
        throw std::exception();
    }

    int hash = (i * 31 + j) % capacity;
    Node* prev = nullptr;
    Node* current = buckets[hash];
    TElem oldValue = NULL_TELEM;

    // search for the element
    while (current != nullptr) {
        if (current->i == i && current->j == j) {
            oldValue = current->value;
            if (e != NULL_TELEM) {
                // update the existing node's value
                current->value = e;
            }
            else {
                // remove the node
                if (prev == nullptr) {
                    buckets[hash] = current->next;
                }
                else {
                    prev->next = current->next;
                }
                delete current;
                size--;
            }
            return oldValue;
        }
        else if (current->i > i || (current->i == i && current->j > j)) {
            // passed the possible position
            break;
        }
        prev = current;
        current = current->next;
    }

    // insert new element if e is not zero
    if (e != NULL_TELEM) {
        Node* newNode = new Node{ i, j, e, nullptr };
        if (prev == nullptr) {
            newNode->next = buckets[hash];
            buckets[hash] = newNode;
        }
        else {
            newNode->next = prev->next;
            prev->next = newNode;
        }
        size++;
    }

    return oldValue;
}

Matrix::~Matrix() {
    for (int i = 0; i < capacity; ++i) {
        Node* current = buckets[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] buckets;
}