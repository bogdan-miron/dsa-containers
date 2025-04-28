#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;

BagIterator::BagIterator(const Bag& c) : bag(c), currentPos(-1)
{
   first();
}

void BagIterator::first() {
   currentPos = bag.head;
}

void BagIterator::next() {
   if (!valid()) {
       throw exception();
   }
   currentPos = bag.nodes[currentPos].next;
}

bool BagIterator::valid() const {
   return currentPos != -1;
}

TElem BagIterator::getCurrent() const
{
   if (!valid()) {
       throw exception();
   }
   return bag.nodes[currentPos].data;
}