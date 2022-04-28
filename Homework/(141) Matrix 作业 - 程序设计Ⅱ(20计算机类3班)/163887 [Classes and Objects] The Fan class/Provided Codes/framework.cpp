
#include <iostream>
#include "source.h"
using namespace std;
int main()
{
  cout << "First fan properties: " << endl;
  Fan fan;
  fan.setSpeed(3);
  fan.setRadius(10);
  fan.setOn(true);
  fan.setColor("yellow");

  cout << "Fan speed: " << fan.getSpeed() << endl;
  cout << "Fan radius: " << fan.getRadius() << endl;
  cout << "Fan on? " << fan.isOn() << endl;
  cout << "Fan color: " << fan.getColor() << endl;

  Fan fan1;
  fan.setSpeed(2);
  fan.setRadius(5);
  fan.setOn(false);
  fan.setColor("blue");

  cout << "\nSecond fan properties: " << endl;
  cout << "Fan speed: " << fan1.getSpeed() << endl;
  cout << "Fan radius: " << fan1.getRadius() << endl;
  cout << "Fan on? " << fan1.isOn() << endl;
  cout << "Fan color: " << fan1.getColor() << endl;


  return 0;
}
