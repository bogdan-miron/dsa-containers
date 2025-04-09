#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;

/*
O(1)
theta(1)
omega(1)
*/
BagIterator::BagIterator(const Bag& c): bag(c), currentNode(nullptr), currentFreq(0)
{
	first();
}


/*
O(1)
theta(1)
omega(1)
*/
void BagIterator::first() {
	currentNode = bag.head;
	currentFreq = (currentNode != nullptr) ? 1 : 0;
}

/*
O(1)
theta(1)
omega(1)
*/
void BagIterator::next() {
	if (!valid()) {
		throw std::exception();
	}
	if (currentFreq < currentNode->frequency) {
		currentFreq++;
	}
	else {
		currentNode = currentNode->next;
		currentFreq = (currentNode != nullptr) ? 1 : 0;
	}
}

/*
O(1)
theta(1)
omega(1)
*/
bool BagIterator::valid() const {
	return currentNode != nullptr;
}


/*
O(1)
theta(1)
omega(1)
*/
TElem BagIterator::getCurrent() const
{
	if (!valid()) {
		throw std::exception();
	}
	return currentNode->data;
}
