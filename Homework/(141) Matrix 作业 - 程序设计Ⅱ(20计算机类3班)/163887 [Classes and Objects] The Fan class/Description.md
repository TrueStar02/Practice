# [Classes and Objects] The Fan class

## Description
```
Design a class named Fan to represent a fan. The class contains:
An int data field named speed that specifies the speed of the fan. A fan has three speeds indicated with a value 1, 2, or 3. The default value is 1.
A bool data field named on that spcifies whether the fan is on (default false).
A double data field named radius that specifies the radius of the fan (default 5).
A string data field named color that specifies the color of the fan (default blue).
A no-arg constructor that creates a default fan.
The accessor and mutator functions for all the data fields.
class Fan
{
public:
  Fan();
  int getSpeed();
  void setSpeed(int);
  bool isOn();
  void setOn(bool);
  double getRadius();
  void setRadius(double);
  string getColor();
  void setColor(string);
};
```