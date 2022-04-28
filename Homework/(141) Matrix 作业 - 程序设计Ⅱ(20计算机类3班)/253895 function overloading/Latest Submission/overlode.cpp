#include<iostream>
#include"overlode.h"
int main() {
	int n;
	int a,b;
	double c,d;
	std::string str1,str2;
	std::cin>>n;
	while(n--) {
		std::cin>>a >> b ;
		std::cin>>c >> d;
		std::cin >> str1 >>str2;
		std::cout <<myplus(a, b) << endl;
		std::cout <<myplus(d, c) << endl;
		std::cout <<myplus(str1, str2) << endl;
	} 
	return 0;
}
