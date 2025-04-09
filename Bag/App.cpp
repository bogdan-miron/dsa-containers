#include "Bag.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>
#include "BagIterator.h"

using namespace std;

int main() {

	testAll();
	cout << "Short tests over" << endl;
	testAllExtended();

	cout << "All test over" << endl;


	// testing the removing all occurences function
	Bag test;
	test.add(7);
	test.add(8);
	test.add(7);
	test.add(7);
	test.add(9);

	int removed = test.removeAllOccurences(7);
	cout << "Removed " << removed << " occurrences of 7" << endl;

	BagIterator it = test.iterator();
	while (it.valid()) {
		cout << it.getCurrent() << " ";
		it.next();
	}
	
	return 0;
}