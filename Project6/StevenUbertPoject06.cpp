/*
* Pg 884 Practice Program # 3
* 
* Listed below are definitions of two classes that use inheritance, 
* code for their implementation, and a main function. 
* put the code into appropriate files with the necessary include statements 
* and preprocessor statements so that the program compiles and runs. 
* It should output “Circle has radius 2 and area 12.5664”.
* Add another class, Rectangle, that is also derived from the Shape class. modify the Rectangle class appropriately so it has private width and height variables, a constructor that allows the user to set the width and height, functions to retrieve the width and height, and an appropriately defined getArea function that calculates the area of the rectangle.
*
* The following code added to main should output 
* “rectangle has width 3 has height 4 and area 12.0”.
* 
* Author Steven Ubert
* Version: 4/3/2021
* Pg 884 Practice Program # 3
*/

#include "Circle.h"
#include "Rectangle.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
    //circle
    Circle c(2);
    cout << c.getName() << " has radius " << c.getRadius() << " and area " << c.getArea() << endl;

    //set precision for getArea
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    //rectangle 
    Rectangle r(3, 4);
    //results
    cout << r.getName() << " has width " << r.getWidth() << " has height " << r.getHeight() << " and area " << r.getArea() << endl;

    return 0;
}