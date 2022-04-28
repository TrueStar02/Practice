#include<iostream>
using namespace std;
int sum(int, int, int);
int sum(int a = 0, int b = 100, int c = 0) {
    return a+b+c;
}
