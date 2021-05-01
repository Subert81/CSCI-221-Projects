/*
write a template-based class that implement a set of items. 
A set is a collection of items in which no item occurs more than once. 
Internally, you may represent the set using the data structure of your 
choice ( for example, list, vector, arrays, etc.). 
However, the class should externally support the following functions:
a.	Add a new item to the set. If the item is already in the 
    set then nothing happens.
b.	Remove an item from the set.
c.	Return the number of items in the set
d.	Determine if an item is a member of the set.
e.	Return a pointer to a dynamically created array containing each item in the set. 
The caller of this function is responsible for deallocating the memory
Test your class by creating different sets of different data types 
(for example, strings, integers, or other classes). 
If you add objects to your set, then you may need to overload 
the == and != operators for the object’s class s your template-based 
set class can properly determine membership

Author: "Name Goes Here!"
Version: 4/20/2021


*/


#include<iostream>
#include<vector>

using namespace std;

//set class using a vector as underlying data structure
template <class T>
class set {

    //vector of type T
    vector<T> elements;

public:
    //empty default constructor
    set() {
    }

    //returns true if item is on set.
    bool contains(T item) const {
        //looping through the vector and checking for item
        for (int i = 0; i < elements.size(); i++) {
            if (elements[i] == item) {
                //found
                return true;
            }
        }
        //not found

        return false;
    }

    //adds an item to the set
    void add(T item) {
        //adding to vector if not already present
        if (!contains(item)) {
            elements.push_back(item);
        }
    }

    //removes an item and return true if removed, false if not found
    bool remove(T item) {
        for (int i = 0; i < elements.size(); i++) {
            if (elements[i] == item) {
                //found, removing ith element on vector
                elements.erase(elements.begin() + i);
                return true;
            }
        }
        return false;
    }

    //returns the number of elements on set
    int size() const {
        return elements.size();
    }

    //returns a dynamic array containing set elements
    T* getElements() const {
        //creating array of enough size
        T* elems = new T[size()];
        //copying values from elements vector
        for (int i = 0; i < elements.size(); i++) {
            elems[i] = elements[i];
        }
        //returning array
        return elems;
    }
};

int main() {
    //enabling display of true/false values instead of 1/0
    cout << boolalpha;

    //creating an integer set
    set<int> intset;

    //adding some values
    intset.add(1);
    intset.add(55);
    intset.add(1); //will be ignored (duplicate)
    intset.add(150);
    intset.add(55); //will be ignored

    //fetching elements array from set and displaying it
    int* elements = intset.getElements();
    cout << "int set: ";
    for (int i = 0; i < intset.size(); i++) {
        cout << elements[i] << " ";
    }
    cout << endl;

    //de allocating memory
    delete[] elements;

    //testing contains and remove method
    cout << "contains 55: " << intset.contains(55) << endl;
    cout << "contains 101: " << intset.contains(101) << endl;

    cout << "removed 150? " << intset.remove(150) << endl;
    cout << "contains 150: " << intset.contains(150) << endl;

    //testing set of type string.

    set<string> stringset;
    stringset.add("Steve");
    stringset.add("Julia");
    stringset.add("Julia");
    stringset.add("Imogen");
    stringset.add("Ivy");

    string* strelements = stringset.getElements();
    cout << endl << "string set: ";
    for (int i = 0; i < stringset.size(); i++) {
        cout << strelements[i] << " ";
    }

    cout << endl;
    delete[] strelements;
    cout << "contains Steve: " << stringset.contains("Steve") << endl;
    cout << "contains Brutus: " << stringset.contains("Brutus") << endl;
    return 0;

}
