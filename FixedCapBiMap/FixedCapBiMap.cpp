#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"

FixedCapBiMap::FixedCapBiMap(int capacity) {
	if (capacity <= 0) {
		throw exception();
	}
	this->capacity = capacity;
	this->mapSize = 0;
	this->elements = new TElem[capacity];
}

FixedCapBiMap::~FixedCapBiMap() {
	delete[] this->elements;
}

bool FixedCapBiMap::add(TKey c, TValue v){
	if (this->mapSize == this->capacity) {
		throw exception();
	}
	int count = 0, index = 0;
	while (count < 2 && index < this->mapSize) {
		if (this->elements[index].first == c) {
			++count;
		}
		++index;
	}
	if (count == 2) {
		return false;
	}
	this->elements[this->mapSize] = {c, v};
	++(this->mapSize);
	return true;
}

ValuePair FixedCapBiMap::search(TKey c) const{
	ValuePair ans = { NULL_TVALUE, NULL_TVALUE };
	int index = 0, count = 0;
	while (count <= 2 && index < this->mapSize) {
		if (this->elements[index].first == c) {
			if (ans.first == NULL_TVALUE) {
				ans.first = this->elements[index].second;
			}
			else {
				ans.second = this->elements[index].second;
			}
			++count;
		}
		++index;
	}
	return ans;
}

bool FixedCapBiMap::remove(TKey c, TValue v){
	// move the last element of the container in the spot of the removal
	bool found = false;
	int index = 0;
	while (!found && index < this->mapSize) {
		if (this->elements[index].first == c && this->elements[index].second == v) {
			this->elements[index].first = this->elements[this->mapSize - 1].first;
			this->elements[index].second = this->elements[this->mapSize - 1].second;
			found = true;
			--(this->mapSize);
		}
		++index;
	}
	return found;
}


int FixedCapBiMap::size() const {
	return this->mapSize;
}

bool FixedCapBiMap::isEmpty() const{
	return (this->mapSize == 0);
}

bool FixedCapBiMap::isFull() const {
	return (this->mapSize == this->capacity);
}

FixedCapBiMapIterator FixedCapBiMap::iterator() const {
	return FixedCapBiMapIterator(*this);
}



