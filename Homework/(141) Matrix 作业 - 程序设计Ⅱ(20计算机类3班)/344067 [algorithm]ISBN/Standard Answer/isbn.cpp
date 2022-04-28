#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main() {
 int time; 
    string isbn;
    int num;
    cin>>time;
    while(time && cin>>isbn) {
     time--;
        string str;
        int weight = 0;
        int digit[10];
        int j = 0;
        int length = isbn.length();
        for(int i = 0; i < length; i++) {
            if(isbn[i] >= '0' && isbn[i] <= '9') {
                num = isbn[i]-'0';
                digit[j] = num;
                j++;
            }
        }
        for(int i = 0; i < j; i++) {
            weight += digit[i]*(10-i);
        }
        weight = 11 - weight % 11;
        if(weight != 10 && weight != 11) {
            stringstream ss;
            ss << weight;
            ss >> str;
        }
        else if(weight == 11) {
            str = '0';
        }
        else {
            str = 'X';
        }
        isbn += '-';
        isbn += str;
        cout<<isbn<<endl;
    }
} 
