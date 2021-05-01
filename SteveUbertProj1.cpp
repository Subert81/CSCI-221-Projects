/* This program requires the student to write 3 functions described in
* Program project 4 (Page 535) and Program Project 6 (Page 536).
* The student also need to add a print function to print out an array.
* The student may watch video notes on MyProgrammingLab to get the idea
* on how to write the main function and three of these four functions
*
*
* Author: Steve Ubert
* Version: 1/24/2021
*/


#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

void reverse(char word[], int count);
// Precondition: c string with a user provided sentence.
// Postcondition: sets two pointers front and rear to the starting and ending
//                positions in the c string and swap their values.  Looping 
//                through the entire c-string until the word is reversed. 

string* addEntry(string* dynamiccArray, int& size, string newEntry);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: A new dynamic array is created, which is one larger than
//                dynamicArray All elements from dynamicArray are copied to
//                new array, the new entry is added to new array, the size
//                is increased, the dynamicArray is deleted, new dynamic
//                array is returned.

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: The function should search dynamicArray for entryToDelete.
//                If not found, the request should be ignored and the
//                unmodified dynamicArray returned. If found, create a new
//                dynamic array one element smaller than dynamicArray. Copy
//                all element except entryToDelete into the new array, delete
//                dynamicArray, decrement size, and return the new dynamic
//                array

void print(const string* dynamicArray, int size);
// Precondition: dynamicArray point to a array of strings with give size,
// Postcondition: The elements in dynamic array will be print out. One
//                element per line followed by its index


int main() {
	/** Problem 4 **/
	char word[100];
	int count;

	//prompt user for sentence with 100 max characters
	cout << "Enter a sentence(max characters are 100 characters): ";
	cin.getline(word, 100);

	//obtain length of word
	string wordLength = word;
	count = wordLength.length() - 1;

	//call reverse method to reverse word and print results
	reverse(word, count);

	/* ********************************    */


	/** Problem 6 **/
	int arraySize = 5;

	string* names = new string[arraySize];
	names[0] = "Steve";
	names[1] = "Julia";
	names[2] = "Imogen";
	names[3] = "Ivy";
	names[4] = "Schmidt";

	//Print initial array
	print(names, arraySize);
	//Add Entry
	names = addEntry(names, arraySize, "Brutus");
	//Print after entry added
	print(names, arraySize);

	//delete entry
	names = deleteEntry(names, arraySize, "Steve");
	//print results
	print(names, arraySize);

	//test if/else path
	names = deleteEntry(names, arraySize, "Saffi");
	print(names, arraySize);

	//test to add additional names and print results 
	names = addEntry(names, arraySize, "Harold");
	print(names, arraySize);

	names = addEntry(names, arraySize, "Cindy");
	print(names, arraySize);
}

//reverse takes a word as a c string and swaps the beginning and 
//last word moving inward
void reverse(char word[], int count) {
	char* first;
	char* last;
	char temp;

	//for loop to reverse word
	for (int i = 0; i <= count / 2; i++) {
		//pointer variables to point to characters in c string
		first = &word[i];
		last = &word[count - i];

		//if clause to ensure program works for even and odd numbered words
		if (i != (count - i)) {
			temp = *first;
			*first = *last;
			*last = temp;
		}
	}

	//display results
	cout << "The sentence in reverse is: ";
	for (int i = 0; i <= count; i++) {
		cout << word[i];

	}
	cout << endl;
}


//creates new dynamic array, then copies the old array data and adds
//new entry.  Deletes old array
string* addEntry(string* dynamicArray, int& size, string newEntry)
{
	//increment size variable
	size++;

	//new dynamic array created for new size
	string* newArray = new string[size];

	//adds data to new array
	for (int i = 0; i < size; i++) {
		if (i < size - 1)
			newArray[i] = dynamicArray[i];
		else
			newArray[i] = newEntry;
	}
	//removes old dynamic array from memory
	delete[] dynamicArray;

	return newArray;
}

//create new dynamic array with out the value provided by the user
string* deleteEntry(string* dynamicArray, int& size, string entryToDelete)
{
	bool toDelete = false;
	int deletedIndex = 0;
	//test for key provided by user, sets bool value to true if found;
	for (int i = 0; i < size; i++) {
		if (dynamicArray[i] == entryToDelete) {
			toDelete = true;
			deletedIndex = i;
			break;
		}
	}

	//returns new dynamic array if key is in dynamic array
	//returns same dynamic array if key is not in the array
	if (toDelete) {

		//sort dynamic array to ensure deleted index and whitespace does not get
		//copied into new array
		for (int i = deletedIndex; i < size - 1; i++) {
			string temp = dynamicArray[i];
			dynamicArray[i] = dynamicArray[i + 1];
			dynamicArray[i + 1] = temp;
		}// end sort loop

		//decrement size variable for new array size
		size--;

		//create new dynamic array
		string* newArray = new string[size];

		//copy data from provided array to new dynamic array
		for (int i = 0; i < size; i++) {
			newArray[i] = dynamicArray[i];
		}

		//delete original array
		delete[] dynamicArray;
		return newArray;

	}//end toDelete if statement
	else
		//return original array
		return dynamicArray;


}

//prints dynamic array
void print(const string* dynamicArray, int size)
{
	for (int i = 0; i < size; i++) {
		cout << dynamicArray[i] << " " << i << endl;
	}
	cout << endl;

}