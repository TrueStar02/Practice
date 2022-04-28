# [Classes and Objects] The Rectangle class

## Description
```
Design a class named Rectangle to represent a rectangle. The class contains:
Two double data field named width and height that specify the width and height of the rectangle. The default values are 1 for both width and height.
A no-arg constructor that creates a default rectangle.
A constructor that creates a rectangle with the specified width and height.
The accessor and mutator functions for all the data fields. (getWidth, getHeight, setWidth, setHeight)
A function name getArea() that returns the area of this rectangle.
A function named getPerimeter() that returns the perimeter.
class Rectangle
{
  private:
    double width, height;
  public:
    Rectangle() ;
    Rectangle(double width, double height);
    double getWidth();
    double getHeight();
    void setWidth(double width);
    void setHeight(double height);
    double getArea();
    double getPerimeter();  
};
```
