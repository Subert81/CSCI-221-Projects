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

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Money.h"
using namespace std;

//Method definition of operator <
bool operator < (const Money& price1, const Money& price2)
{
	//Return output value
	return (price1.dollars < price2.dollars) ||
		((price1.dollars == price2.dollars) &&
			(price1.cents < price2.cents));
}

//Method definition of operator <=
bool operator <= (const Money& price1, const Money& price2)
{
	//Return output value
	return ((price1.dollars < price2.dollars) || ((price1.dollars == price2.dollars) &&
		(price1.cents < price2.cents)))
		|| ((price1.dollars == price2.dollars)
			&& (price1.cents == price2.cents));
}
//Method definition of operator>
bool operator > (const Money& price1, const Money& price2)
{
	//Return output value
	return (price1.dollars > price2.dollars)
		|| ((price1.dollars == price2.dollars) &&
			(price1.cents > price2.cents));
}

//Method definition of operator >=
bool operator >=(const Money& price1, const Money& price2)
{
	//Return output value
	return ((price1.dollars > price2.dollars) ||
		((price1.dollars == price2.dollars) &&
			(price1.cents > price2.cents))) ||
		((price1.dollars == price2.dollars) &&
			(price1.cents == price2.cents));
}

//Method definition of percent
const Money Money::percent(int per) const
{
	int ds = dollars * per / 100;
	int cs = dollars * per % 100 + cents * per / 100;
	return Money(ds, cs);
}

//Method definition of operator+
const Money operator + (const Money& amount1, const Money& amount2)
{
	int c1 = amount1.cents + amount1.dollars * 100;
	int c2 = amount2.cents + amount2.dollars * 100;
	int totalCents = (c1 + c2);
	int absCents = abs(totalCents);
	int totDollars = absCents / 100;
	int totCents = absCents % 100;
	if (totalCents < 0)
	{
		totDollars = -totDollars;
		totCents = -totCents;
	}
	//Return output value
	return Money(totDollars, totCents);
}
//Method definition of operator- with two parameters
const Money operator -(const Money& amount1, const Money& amount2)
{
	int c1 = amount1.cents + amount1.dollars * 100;
	int c2 = amount2.cents + amount2.dollars * 100;
	int differCents = c1 - c2;
	int absCents = abs(differCents);
	int totDollars = absCents / 100;
	int totCents = absCents % 100;
	if (differCents < 0)
	{
		totDollars = -totDollars;
		totCents = -totCents;
	}
	//Return output value
	return Money(totDollars, totCents);
}
//Method definition of operator==
bool operator == (const Money& amount1, const Money& amount2)
{
	//Return output value
	return((amount1.dollars == amount2.dollars) && (amount1.cents == amount2.cents));
}
//Method definition of operator- with one parameter
const Money operator - (const Money& amount)
{
	//Return output value
	return Money(-amount.dollars, -amount.cents);
}

Money::Money() : dollars(0), cents(0)
{
}
Money::Money(double amount) : dollars(dType(amount)), cents(cType(amount))
{
}
Money::Money(int dol) : dollars(dol), cents(0)
{
}
Money::Money(int dol, int cen)
{
	if ((dol < 0 && cen > 0) || (dol > 0 && cen < 0))
	{
		cout << "\n Inconsistent info ";
		exit(1);
	}
	dollars = dol;
	cents = cen;
}
//Method definition of findTotalamount
double Money::findTotalamount() const
{
	//Return output value
	return (dollars + cents * 0.01);
}
//Method definition of findTotaldolloars
int Money::findTotaldolloars() const
{
	//Return output value
	return dollars;
}
//Method definition of findTotalcents
int Money::findTotalcents() const
{
	//Return output value
	return cents;
}
//Method definition of dType
int Money::dType(double amount) const
{
	//Return output value
	return static_cast<int>(amount);
}
//Method definition of cType
int Money::cType(double amount) const
{
	double doubleCents = amount * 100;
	int intCents = (roundedNumber(fabs(doubleCents))) % 100;
	if (amount < 0)
		intCents = -intCents;
	return intCents;
}
//Method definition of roundedNumber
int Money::roundedNumber(double number) const
{
	//Return output value
	return floor(number + 0.5);
}
ostream& operator <<(ostream& outputStream, const Money& amount)
{
	int absDollars = abs(amount.dollars);
	int absCents = abs(amount.cents);
	if (amount.dollars < 0 || amount.cents < 0)
		outputStream << "$-";
	else
		outputStream << '$';
	outputStream << absDollars;
	if (absCents >= 10)
		outputStream << '.' << absCents;
	else
		outputStream << '.' << '0' << absCents;
	return outputStream;
}

istream& operator >> (istream& inputStream, Money& amount)
{
	char dollarSign;
	inputStream >> dollarSign;
	if (dollarSign != '$')
	{
		cout << "\n Error: illegal form for money input!";
		exit(1);
	}
	double incrementAmount;
	inputStream >> incrementAmount;
	amount.dollars = amount.dType(incrementAmount);
	amount.cents = amount.cType(incrementAmount);
	return inputStream;
}