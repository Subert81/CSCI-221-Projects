#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <iostream>
#include <string>
using namespace std;

class Rectangle : public Shape
{
public:
    Rectangle();
    Rectangle(int newWidth, int newHeight);
    int getWidth();
    int getHeight();
    void setWidth(int newWidth);
    void setHeight(int newHeight);
    virtual double getArea();
private:
    int width;
    int height;

};
#endif