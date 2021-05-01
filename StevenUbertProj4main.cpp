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

//resulting screen prints with the final money input values
int main() {
    Money input1, input2;
    cout << "Please enter a dollar amount beginning with $. It can be a decimal number up to two digits: " << endl;
    cin >> input1;
    cout << "Please enter a second dollar amount beginning with $. It can also be a decimal number up to two digits: : " << endl;
    cin >> input2;
    cout << "You entered: " << input1 << " and " << input2 << endl;
    cout << "10% of amount 1 is: " << input1.percent(10) << endl;
    cout << "10% of amount 2 is: " << input2.percent(10) << endl;

    if (input1 == input2) {
        cout << "Amounts are equal" << endl;
    }
    else {
        cout << "Amounts are different" << endl;
    }

    Money sum = input1 + input2;
    cout << "Sum of the two amounts is " << sum << endl;
    Money dif = input1 - input2;
    cout << "Difference of the two amounts is " << dif << endl;

    if (input1 < input2) {
        cout << "Amount 1 is less than amount 2" << endl;
    }
    else {
        cout << "Amount 1 is not less than amount 2" << endl;
    }
    if (input1 >= input2) {
        cout << "Amount 1 is greater than or equal to amount 2" << endl;
    }
    else {
        cout << "Amount 1 is not greater than or equal to amount 2" << endl;
    }

}