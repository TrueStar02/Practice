#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
void file_out(ostream & os,const double fo,const double *fe,int n);
int main()
{	ofstream fout;
	fout.open("out.txt");
	if(!fout.is_open())
	{	cout<<"Error in opening the file!\n";
		exit(EXIT_FAILURE);
	}
	double obj,eps[5];
	cin>>obj;
	int x;
	for(x=0;x<=4;x++)
		cin>>eps[x];
	file_out(cout,obj,eps,5);
	file_out(fout,obj,eps,5);
	return 0;
}
void file_out(ostream & os,const double fo,const double *fe,int n)
{	ios_base::fmtflags initial;
	initial=os.setf(ios_base::fixed);
	os.precision(0);
	os<<"Focal length of objective:"<<fo<<"mm\n";
	os.setf(ios::showpoint);
	os.precision(1);
	os<<"f.l.eyepiece";
	os.width(15);
	os<<"magnification"<<endl;
	int i;
	for(i=0;i<n;i++)
	{	os.width(12);
		os<<fe[i];
		os.width(15);
		os<<int(fo/fe[i]+0.5)<<endl;
	}
	os.setf(initial);
}
