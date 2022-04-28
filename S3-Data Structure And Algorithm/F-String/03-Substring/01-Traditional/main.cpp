#include<iostream>
#include "violent.h"
int main()
{   string str("hsfajdkfhsajlkfhvsjklahfvjklasehfcjlkawehgfulikaweghfcvluisaehgfel");
    cout<<match(str,"saj")<<endl;
    cout<<match(str,"zz")<<endl;
    cout<<match("",str)<<endl;
    return 0;
}