
class human:public animal
{   private:
        string name;
    public:
        human(string n):animal("Human",2),name(n){}
        void greeting()const
        { cout<<"Hello, I'm "<<name<<".\n";
        }
};