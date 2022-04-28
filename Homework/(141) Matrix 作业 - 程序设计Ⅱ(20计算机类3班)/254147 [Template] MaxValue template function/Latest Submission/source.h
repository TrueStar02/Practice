#include<cctype>
template<class T>
T maxValue (const T value1, const T value2)
{   if(value1>value2)
       return value1;
    else
        return value2; 
}

char maxValue (const char value1, const char value2)
{   if(isalpha(value1)&&isalpha(value2))
    {if(toupper(value1)>=toupper(value2))
       return value1;
    else
        return value2;
    }
    else
    {if(value1>=value2)
       return value1;
    else
        return value2;

    } 
}