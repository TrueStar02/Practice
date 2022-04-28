using namespace std;
class Fan
{   private:
        int speed;
        bool on;
        double radius;
        string color;
    public:
        Fan():speed(1),on(0),radius(5),color("blue"){}
        int getSpeed(){return speed;}
        void setSpeed(int x){speed=x;}
        bool isOn(){return on;}
        void setOn(bool x){on=x;}
        double getRadius(){return radius;}
        void setRadius(double x){radius=x;}
        string getColor(){return color;}
        void setColor(string t){color=t;}
};