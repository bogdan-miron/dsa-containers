#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c), currentNode(nullptr), currentFreq(0)
{
	first();
}

void BagIterator::first() {
	currentNode = bag.head;
	currentFreq = (currentNode != nullptr) ? 1 : 0;
}


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


bool BagIterator::valid() const {
	return currentNode != nullptr;
}



TElem BagIterator::getCurrent() const
{
	if (!valid()) {
		throw std::exception();
	}
	return currentNode->data;
}
