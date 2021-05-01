/*
* Do Programming Project #1 on page 923
*
* Write a program that converts 24-hour time to 12-hour time. The following is a sample dialogue:
* Enter time in 24-hour notation:
* 13:07
* That is the same as
* 1:07 PM
* Again? (y/n)
* Y
* Enter time in 24-hour notation:
* 10:15
* That is the same as
* 10:15 AM
* Again? (y/n)
* Y
* Enter time in 24-hour notation:
* 10:65
* There is no such time as 10:65
* Try again:
* Enter time in 24-hour notation:
* 16:05
* That is the same as
* 4:05 PM
* Again? (y/n)
* n
* End of Program
* You will define an exception class called TimFormatMistake. If the user enters and illegal time, like 10:65 or even gibberish like 8&*68, then your program will throw and catch a TimeFormatMistake

*
* Author Steven Ubert
* Version: 4/11/2021
* Programming Project #1 on page 923
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class TimeFormatMistake: public exception
{
virtual const char* what() const throw()
{
return "Time is invalid";
}
};

void getTimes(string str, int &hours, int &minutes) {
if(str.length() != 5) {
throw TimeFormatMistake();
}
if(str[0] < '0' || str[0] > '9') {
throw TimeFormatMistake();
}
if(str[1] < '0' || str[1] > '9') {
throw TimeFormatMistake();
}
if(str[2] != ':') {
throw TimeFormatMistake();
}
if(str[3] < '0' || str[3] > '9') {
throw TimeFormatMistake();
}
if(str[4] < '0' || str[4] > '9') {
throw TimeFormatMistake();
}
hours = (10 * (str[0]-'0')) + (str[1] - '0');
minutes = (10 * (str[3]-'0')) + (str[4] - '0');
if((hours < 0 || hours > 24) || (minutes < 0 || minutes > 59)) {
throw TimeFormatMistake();
}
}

int main() {
string str;
string zone;
int hours, mins;
while(true) {
cout << "Enter time in 24-hour notation: ";
cin >> str;
try {
getTimes(str, hours, mins);
if(hours >= 12) {
zone = "PM";
} else {
zone = "AM";
}
hours %= 12;
if(hours == 0) {
hours = 12;
}
cout << "That is the same as " << hours << ":" << setfill('0') << setw(2) << mins << " " << zone << endl;
} catch (exception& e) {
cout << "There is no such time as " << str << endl;
}
cout << "Again?(y/n)";
cin >> str;
if(str != "y") {
break;
}
}
return 0;
}