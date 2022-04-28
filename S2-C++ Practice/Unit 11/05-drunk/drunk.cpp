#include "vector.h"
#include<cstdlib>
#include<ctime>
#include<fstream>
int main(void)
{	srand((unsigned int)time(0));
	ofstream fout;
	fout.open("result.txt");
	Vector result(0,0,0);
	Vector temp;
	cout<<"Steps:";
	int step,x;
	double len;
	cin>>step;
	cout<<"Length of each step:";
	cin>>len;
	for(x=1;x<=step;x++)
	{	temp.reset(len,rand()%360,1);
		temp.switch_mode();
		fout<<"Step:#"<<x<<"This Step:"<<temp;
		temp.switch_mode();
		fout<<temp;
		result=result+temp;
		fout<<"Here is:"<<result;
		result.switch_mode();
		fout<<result<<endl;
		result.switch_mode();
	}
	fout.close();
	return 0;
}
