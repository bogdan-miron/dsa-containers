#pragma once

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0

class Matrix {
private:
    struct Node {
        int i; // line index
        int j; // column index
        TElem value;
        Node* next;
    };

    int numLines;   // number of lines in the matrix
    int numCols;    // number of columns in the matrix
    int capacity;   // capacity of the hash table
    int size;       // number of non-zero elements in the matrix
    Node** buckets; // array of pointers to Node (hash table with separate chaining)

public:
    // constructor
    Matrix(int nrLines, int nrCols);

    // destructor
    ~Matrix();

    // returns the number of lines
    int nrLines() const;

    // returns the number of columns
    int nrColumns() const;

    // returns the element from line i and column j (indexing starts from 0)
    // throws exception if (i,j) is not a valid position in the Matrix
    TElem element(int i, int j) const;

    // modifies the value from line i and column j
    // returns the previous value from the position
    // throws exception if (i,j) is not a valid position in the Matrix
    TElem modify(int i, int j, TElem e);

    // Additional helper methods (if needed) can be declared here
};