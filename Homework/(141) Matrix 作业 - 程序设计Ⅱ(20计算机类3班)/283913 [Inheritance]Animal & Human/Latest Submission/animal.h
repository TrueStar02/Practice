#include<iostream>
using namespace std;
class animal
{   private:
        string species;
        int eyes;
    public:
        animal(string s,int e):species(s),eyes(e){}
        void print_eyes()const
        {
            cout<<species<<" has "<<eyes<<" eyes.\n";
        }

};