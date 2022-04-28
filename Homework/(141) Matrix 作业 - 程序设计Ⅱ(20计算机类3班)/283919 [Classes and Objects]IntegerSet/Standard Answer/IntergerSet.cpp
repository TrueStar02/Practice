// Lab 2: IntegerSet.cpp
// Member-function definitions for class IntegerSet.
#include <iostream>
#include <iomanip>
 
#include "IntegerSet.h"  // IntegerSet class definition
 
// constructor creates a set from array of integers
IntegerSet::IntegerSet(int array[], int size) {
    emptySet();
 
    for (int i = 0; i < size; i++)
        insertElement(array[ i ]);
}  // end IntegerSet constructor
 
// initializes a set to the empty set
void IntegerSet::emptySet() {
    for (int y = 0; y < 101; y++)
        set[ y ] = 0;
}  // end function emptySet
 
// returns the union of two sets
IntegerSet IntegerSet::unionOfSets(const IntegerSet &r) {
    IntegerSet temp;
 
     // if element is in either set, add to temporary set
    for (int n = 0; n < 101; n++)
        if (set[ n ] == 1 || r.set[ n ] == 1)
            temp.set[ n ] = 1;
 
    return temp;
}  // end function unionOfSets
 
// returns the intersection of two sets
IntegerSet IntegerSet::intersectionOfSets(const IntegerSet &r) {
    IntegerSet temp;
 
     // if element is in both sets, add to temporary set
    for (int w = 0; w < 101; w++)
        if (set[ w ] == 1 && r.set[ w ] == 1)
            temp.set[ w ] = 1;
 
    return temp;
}  // end function intersectionOfSets
 
// insert a new integer into this set
void IntegerSet::insertElement(int k) {
    if (validEntry(k))
        set[ k ] = 1;
    else
        std::cout << "Invalid insert attempted!\n";
}  // end function insertElement
 
// removes an integer from this set
void IntegerSet::deleteElement(int m) {
    if (validEntry(m))
        set[ m ] = 0;
    else
        std::cout << "Invalid delete attempted!\n";
}  // end function deleteElement
 
// determines if two sets are equal
bool IntegerSet::isEqualTo(const IntegerSet &r) const {
    for (int v = 0; v < 101; v++)
        if (set[ v ] != r.set[ v ])
            return false;  // sets are not-equal
 
    return true;  // sets are equal
}  // end function isEqualTo
 