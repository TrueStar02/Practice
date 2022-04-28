// Problem#: 17657
// Submission#: 4657151
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <string>

using namespace std;

class Fan {
    int speed;
    bool on;
    double radius;
    string color;
  public:
    Fan() {
        speed = 1;
        on = false;
        radius = 5;
        color = "blue";
    }
    int getSpeed() const {
        return speed;
    }
    void setSpeed(int a) {
        speed = a;
    }
    bool isOn() const {
        if (on) {
            return 1;
        }
        else {
            return 0;
        }
    }
    void setOn(bool a) {
        on = a;
    }
    double getRadius() const {
        return radius;
    }
    void setRadius(double a) {
        radius = a;
    }
    string getColor() const {
        return color;
    }
    void setColor(string a) {
        color = a;
    }
};                                 
