#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main() {
    string message,str,result,repeat;
    cin>>message;
    int length  = message.length();
    int len = 0;
    int start, end, begin = 0,num_repeat = 0;
    while (message != "x") {
        for (int i = 0; i < length; i++) {
            if(message[i] >= '0' && message[i] <= '9') {
                len++;
                end = start = i;
                result += message.substr(begin,start-begin-1);
                for(int j = i+1; j < length; j++) {
                    if(message[j] >= '0' && message[j] <= '9') {
                        end = j;
                        len++;
                    }
                    else break;
                }
                repeat = message.substr(start,len);
                stringstream ss;
                ss << repeat;
                ss >> num_repeat;
                str = message.substr(start-1,1);
                for(int k = 0; k < num_repeat; k++) {
                    result += str;
                }
                begin = end+1;
                num_repeat = 0;
                i = end;
                num_repeat = 0;
            }
        }
        str = message.substr(end+1,length-end);
        result += str;
        cout<<result<<endl;
        cin>>message;
        length  = message.length();
        result = "";
        begin = 0;
        len = 0;
    }
} 
