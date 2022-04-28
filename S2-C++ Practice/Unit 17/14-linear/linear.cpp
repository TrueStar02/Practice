#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main(int argc,char *argv[])
{	if(argc<2)
	{	fprintf(stderr,"Are you kidding?\n");
		exit(EXIT_FAILURE);
	}
	ifstream fin[argc-1];
	ofstream fout("linear.txt");
	int x,n=argc-1;
	bool valid[argc-1];
	char temp[256],ch;
	for(x=0;x<argc-1;x++)
		valid[x]=1;
	for(x=1;x<argc;x++)
	{	fin[x-1].open(argv[x]);
		if(!fin[x-1].is_open())
		{	cerr<<"I can't open the file "<<argv[x]<<"!\n";
			valid[x]=0;
			n--;
		}
	}
	if(!fout.is_open())
	{	cerr<<"I can't create the output file!\n";
		exit(EXIT_FAILURE);
	}
	cout<<"Result:\n";
	while(n)
	{	for(x=0;x<argc-1;x++)
			if(valid[x])
			{	if(fin[x].getline(temp,256)&&!fin[x].eof())
				{	(fout<<temp).put('\n');
					(cout<<temp).put('\n');
				}
				else
				{	valid[x]=0;
					n--;
				}
				
			}
	}
	for(x=0;x<argc-1;x++)
		fin[x].close();	
	fout.close();
	return 0;
}
