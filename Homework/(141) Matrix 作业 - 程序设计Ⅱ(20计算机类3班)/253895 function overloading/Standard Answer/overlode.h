#include<iostream>
using namespace std;
int myplus(int a, int b);
double myplus(double a, double b);
string myplus(string a, string b);
int myplus(int a, int b){
 return a+b;
}
double myplus(double a, double b){
 return a+b;
}
string myplus(string a, const string b) {
 return a+b;
}
