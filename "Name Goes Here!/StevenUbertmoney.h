/*Do Practice Programm  #3 on page 738.
* redo practice programs 1 rom ch. 11, but this time define the Money
* ADT class in separate file.
* Modify the definition of the class money shown in display 11.8
* The operators <, <=, >, and >= have all been overloaded to apply to the type Money. (see self-test exercise 13
* The following member function has been added to the class definition.
* Money percent(int percentFigure) const;
* //returns a percentage of the money amount in the
* //calling object. For example, if percentFigure is 10,
* //then the value returned in 10% of the amount of
* //money represented by the calling object.
* For example, if purse is an object of type Money whose value represents the amount $100.10, then call
* purse.percent(10);
* returns 10% of $100.10; that is, it returns a value of type Money that represents the amount $10.01.
*
*
* Author: Steven Ubert
* Version: 3/7/2021
*/

#pragma once

#ifndef MONEY_H

#define MONEY_H

using namespace std;

//Create a class name, Money
class Money
{
public:

	//Define the methods
	friend bool operator < (const Money& price1, const Money& price2);
	friend bool operator <= (const Money& price1, const Money& price2);
	friend bool operator > (const Money& price1, const Money& price2);
	friend bool operator >= (const Money& price1, const Money& price2);
	friend const Money operator + (const Money& amount1, const Money& amount2);
	friend const Money operator - (const Money& amount1, const Money& amount2);
	friend bool operator == (const Money& amount1, const  Money& amount2);
	friend const Money operator - (const Money& amount);
	friend ostream& operator << (ostream& outputStream, const  Money& amount);
	friend istream& operator >> (istream& inputStream, Money& amount);
	Money();
	Money(double amount);
	Money(int dol, int cen);
	Money(int dol);
	double findTotalamount() const;
	int findTotaldolloars() const;
	int findTotalcents() const;
	const Money percent(int percent_figure) const;
private:
	//Member variables
	int dollars;
	int cents;
	int dType(double amount) const;
	int cType(double amount) const;
	int roundedNumber(double number) const;
};
#endif
