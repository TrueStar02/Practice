#include<iostream>
#include<cstring>
#include<new>
using namespace std;
struct chaff
{	char dross[20];
	int slag;
};
int main(void)
{	char *buffer=new char[128];
	chaff *unknown=new(buffer) chaff[3];
	int x;
	strcpy(unknown[0].dross,"String 0");
	unknown[0].slag=0;
	strcpy(unknown[2].dross,"String 2");
	unknown[2].slag=2;
	strcpy(unknown[1].dross,"String 1");
	unknown[1].slag=1;
	for(x=0;x<3;x++)
		cout<<unknown[x].dross<<" "<<unknown[x].slag<<endl;
	delete [] unknown;
	return 0;
}
