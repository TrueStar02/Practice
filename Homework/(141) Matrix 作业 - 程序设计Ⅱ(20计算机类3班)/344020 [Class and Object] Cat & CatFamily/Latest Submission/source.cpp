#include<iostream>
using namespace std;
class Cat
{   public:
        string cat_name;
        int cat_age;
        Cat(string n,int a):cat_name(n),cat_age(a){}
};
class CatFamily
{   private:
        Cat * array[100];
        int size;
    public:
        CatFamily()
        {   int x;
            size=0;
            for(x=0;x<100;x++)
                array[x]=NULL;
        }
        bool add_a_cat(string n,int a)
        {   if(size==100)return 0;
            array[size]=new Cat(n,a);
            size++;
            return 1;
        }
        bool remove_a_cat(string n)
        {   int x;
            bool i=0;
            for(x=0;x<size;x++)
                if(n==array[x]->cat_name)
                {   delete array[x];
                    i=1;
                    break;
                }
            if(i)
            {   for(;x<size-1;x++)
                    array[x]=array[x+1];
                array[x]=NULL;
                size--;
                return 1;
            }
            return 0;

        }
        bool has_cat(string n)
        {   int x;
            for(x=0;x<size;x++)
                if(n==array[x]->cat_name)
                {   return 1;
                    
                }
        
            return 0;

        }
        Cat get_cat(string n)
        {   int x;
            for(x=0;x<size;x++)
                if(n==array[x]->cat_name)
                {   return *(array[x]);
                    
                }
        

        }
        string operator[](int n)
        {   return array[n]->cat_name;

        }
        int number_of_cats(){return size;}

};