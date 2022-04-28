

#include<iostream>
#include<valarray>
using namespace std;
void Show(const valarray<int> & vi,int col);
int main(void)
{	
	int arr[12]={3,9,2,6,8,4,0,7,1,5,9,3};
	valarray<int> val(arr,12);
	Show(val,3);
	valarray<int> vcol(val[slice(1,4,3)]);
	Show(vcol,1);
	valarray<int> vrow(val[slice(1,3,1)]);
	Show(vrow,3);
	val[slice(0,4,3)]=valarray<int>(val[slice(1,4,3)])+valarray<int>(val[slice(2,4,3)]);
	Show(val,3);
	return 0;
}
void Show(const valarray<int> & vi,int col)
{	int x;
	for(x=0;x<vi.size();x++)
	{	cout<<vi[x]<<" ";
		if(x%col==col-1)
			cout<<endl;
	}
}
