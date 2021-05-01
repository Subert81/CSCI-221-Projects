#include <iostream>
using namespace std;

class Book
{
private:
    string author; //author of the book
    string title;  //title of the book
    string date;   //data of the book

public:
    Book(string author, string title, string date);
    string getAuthor();
    void setAuthor(string author);
    string getTitle();
    void setTitle(string title);
    string getDate();
    void setDate(string date);
    void display();
};
