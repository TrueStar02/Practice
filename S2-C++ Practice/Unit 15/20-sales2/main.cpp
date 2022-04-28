#include "sales.h"
#include<typeinfo>
int main(void)
{	double vals1[12]={123,234,324,535,922,346,254,737,754,467};
	double vals2[12]={1034,2141,6457,2352,2341,7566,4587,9302,9501,8876,9201,9456};
	Sales sales1(2011,vals1,12);
	LabelSales sales2("Walmart",2014,vals2,12);
	int x;
	try
	{	cout<<"Block 1\n";
		cout<<"Year:"<<sales1.Year()<<endl;
		for(x=0;x<12;x++)
			cout<<sales1[x]<<" ";
		cout<<"Year:"<<sales2.Year()<<endl;
		cout<<"Label:"<<sales2.Label()<<endl;
		for(x=0;x<=12;x++)
			cout<<sales2[x]<<" ";
		cout<<"End of block 1\n";
	}
	catch(Sales::bad_index & bad)
	{	cout<<bad.what();
		if(typeid(bad)==typeid(LabelSales::nbad_index))
		{	LabelSales::nbad_index & nb=dynamic_cast<LabelSales::nbad_index &>(bad);
			cout<<"Company:"<<nb.label_val()<<endl;
		}	
		cout<<"Bad Indedx:"<<bad.bi_val()<<endl;
	}
	try
	{	cout<<"Block 2\n";
		sales2[2]=3456;
		sales1[20]=360;
		cout<<"End of block 2\n";
	}
	catch(Sales::bad_index & bad)
	{	cout<<bad.what();
		if(typeid(bad)==typeid(LabelSales::nbad_index))
		{	LabelSales::nbad_index & nb=dynamic_cast<LabelSales::nbad_index &>(bad);
			cout<<"Company:"<<nb.label_val()<<endl;
		}	
		cout<<"Bad Indedx:"<<bad.bi_val()<<endl;
	}
	cout<<"Bye~\n";
	return 0;
}
