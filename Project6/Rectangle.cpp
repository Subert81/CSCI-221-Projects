#include "Rectangle.h"
#include <iostream>
#include <string>

using namespace std;

Rectangle::Rectangle() : Shape("Rectangle"), width(0), height(0)
{}

Rectangle::Rectangle(int newWidth, int newHeight) : Shape("Rectangle"), width(newWidth), height(newHeight)
{}

int Rectangle::getWidth()
{
    return width;
}

int Rectangle::getHeight()
{
    return height;
}

void Rectangle::setWidth(int newWidth)
{
    this->width = newWidth;
}

void Rectangle::setHeight(int newHeight)
{
    this->height = newHeight;
}

double Rectangle::getArea()
{
    return (((double)width) * ((double)height));
}
