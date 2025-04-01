#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
	head = nullptr;
	tail = nullptr;
}


void Bag::add(TElem elem) {
	Node* current = head;
	while (current != nullptr) {
		if (current->data == elem) {
			current->frequency++;
			return;
		}
		current = current->next;
	}

	Node* newNode = new Node(elem);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}


bool Bag::remove(TElem elem) {
	Node* current = head;
	while (current != nullptr) {
		if (current->data == elem) {
			current->frequency--;
			if (current->frequency == 0) {
				if (current->prev) current->prev->next = current->next;
				else head = current->next;

				if (current->next) current->next->prev = current->prev;
				else tail = current->prev;
				delete current;
			}
			return true;
		}
		current = current->next;
	}
	return false;
}


bool Bag::search(TElem elem) const {
	Node* current = head;
	while (current != nullptr) {
		if (current->data == elem) {
			return true;
		}
		current = current->next;
	}
	return false;
}

int Bag::nrOccurrences(TElem elem) const {
	Node* current = head;
	while (current != nullptr) {
		if (current->data == elem) {
			return current->frequency;
		}
		current = current->next;
	}
	return 0; 
}


int Bag::size() const {
	int ans = 0;
	Node* current = head;
	while (current != nullptr) {
		ans += current->frequency;
		current = current->next;
	}
	return ans;
}


bool Bag::isEmpty() const {
	return head == nullptr;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	Node* current = head;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
	tail = nullptr;
}

