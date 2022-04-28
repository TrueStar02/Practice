#include "vector.h"
#include<cstdlib>
#include<ctime>
#include<fstream>
int main(void)
{	srand((unsigned int)time(0));
	ofstream fout;
	int step,x,y,times;
	fout.open("result.txt");
	Vector result(0,0,0);
	Vector temp;
	cout<<"times:";
	cin>>times;
	cout<<"Steps:";
	double len;
	cin>>step;
	cout<<"Length of each step:";
	cin>>len;
	for(y=1;y<=times;y++)
	{	for(x=1;x<=step;x++)
		{	temp.reset(len,rand()%360,1);
			result=result+temp;
		}
		fout<<"Test #"<<y<<result;
		result.switch_mode();
		fout<<result<<endl;
		result.reset(0,0,0);
	}
	fout.close();
	return 0;
}
