/*create a database of books that are stored using a vector.Keep track of the author, title, and publication date of each book.Your program should have a main menu that allows the user to select from the following : (1) Add a book’s author, title, and date; (2) Print an alphabetical list of the books sorted by author; and (3) Quit.

Must use a class to hold the data for each book.This class must hold three string fields : one to hold the author’s name, one for the publication date, and another to hold the book’s title.Store the entire database of books in a vector in which each vector element is a book class object.

To sort the data, use the generic sort function from the library.Note that this requires you to define the < operator to compare two objects of type Book so that the author field from the two books are compared.A sample of the input / output behavior might look as follows.Your I / O need not look identical, this is just to give an idea of the functionality.Comment the codeand your functions.

    Select from the following choices :

1. Add new book

2. Print listing sorted by author

3. Quit


Author: Steven Ubert
Version: 4/25/2021


*/

#include <iostream>
#include "Book.h"
#include <vector>
#include <algorithm>
using namespace std;

Book::Book(string author, string title, string date)
{
    this->author = author;
    this->date = date;
    this->title = title;
}
string Book::getAuthor()
{
    return this->author;
}

void Book::setAuthor(string author)
{
    this->author = author;
}
string Book::getTitle()
{
    return title;
}
void Book::setTitle(string title)
{
    this->title = title;
}
string Book::getDate()
{
    return date;
}
void Book::setDate(string date)
{
    this->date = date;
}
void Book::display()
{
    cout << author << ", " << title << ", " << date << endl;
}

bool sortByAuthor(Book* b1, Book* b2)
{
    return (b1->getAuthor() < b2->getAuthor());
}

void printListOrderByAuthor(vector<Book*>& books)
{
    //sort by author
    sort(books.begin(), books.end(), sortByAuthor);
    vector<Book*>::iterator bookPtr;

    for (bookPtr = books.begin(); bookPtr != books.end(); bookPtr++)
    {

        (*bookPtr)->display();
    }
}

int main()
{

    //local variables
    int choice = 0; //user choice
    string author;  //author of the book
    string title;   //title of the book
    string date;    //data of the book
    vector<Book*> books;

    do
    {
        cout << "\n\nSelect from the following choices: \n";
        cout << "1. Add new Book\n";
        cout << "2. Print listing sorted by author\n";
        cout << "3. Quit\n";
        cout << "Please enter your choice:  ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter title:  ";
            getline(cin, title);

            cout << "Enter author:  ";
            getline(cin, author);

            cout << "Enter publication date:  ";
            getline(cin, date);
            books.push_back(new Book(author, title, date));
            break;

        case 2:
            cout << "\nThe books you entered so far, sorted alphabetically by author are: \n";
            printListOrderByAuthor(books);
            break;
        case 3:
            cout << "\nGood Bye....\n";
            break;

        default:
            cout << "Invalid, please enter a valid choice";
            break;
        }
    } while (choice != 3);
    cout << endl;
    return 0;
}