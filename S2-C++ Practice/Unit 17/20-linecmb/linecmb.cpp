#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
struct File
{	ifstream fin;
	bool valid;
};
int main(int argc,char *argv[])
{	if(argc==1)
	{	cerr<<"Are you kidding?\n";
		exit(EXIT_FAILURE);
	}
	File f[argc-1];
	char temp[256];
	int x,num=argc-1;
	for(x=0;x<argc-1;x++)
	{	f[x].fin.open(argv[x+1]);
		f[x].valid=1;
	}
	ofstream fout("linecmb.txt");
	while(num)
	{	for(x=0;x<argc-1;x++)
			if(f[x].valid)
			{	f[x].fin.get(temp,256).get();
				cout<<temp;
				if(f[x].fin.eof())
				{	f[x].valid=0;
					num--;
				}
				else
					fout<<temp;
			}
		fout<<endl;
	}
	for(x=0;x<argc-1;x++)
		f[x].fin.close();
	fout.close();
	return 0;
}
