#include "Matrix.h"
#include <exception>
using namespace std;


Matrix::Matrix(int lines, int cols) {
	
	if (lines <= 0 || cols <= 0) {
		throw exception();
	}

	lineCount = lines;
	colCount = cols;
	elements = new Triple[lines * cols];
	matrixSize = 0;
}

Matrix::~Matrix() {
	delete[] elements;
}


int Matrix::nrLines() const {
	return lineCount;
}


int Matrix::nrColumns() const {
	return colCount;
}


TElem Matrix::element(int i, int j) const {
	if (i < 0 || j < 0 || i >= lineCount || j >= colCount) {
		throw exception();
	}
	for (int index = 0; index < matrixSize; ++index) {
		if (elements[index].line == i && elements[index].col == j) {
			return elements[index].value;
		}
	}
	return NULL_TELEM;
}

TElem Matrix::modify(int i, int j, TElem e) {
	if (i < 0 || j < 0 || i >= lineCount || j >= colCount) {
		throw exception();
	}
	for (int index = 0; index < matrixSize; ++index) {
		if (elements[index].line == i && elements[index].col == j) {
			TElem ans = elements[index].value;
			elements[index].value = e;
			return ans;
		}
	}
	elements[matrixSize].line = i;
	elements[matrixSize].col = j;
	elements[matrixSize].value = e;
	++matrixSize;
}


