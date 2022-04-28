#include<iostream>
#include<valarray>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{	vector<double> vec;
	int x;
	double temp;
	while((cin>>temp)&&(temp>0))
		vec.push_back(temp);
	sort(vec.begin(),vec.end());
	valarray<double> val(vec.size()),res(vec.size());
	for(x=0;x<vec.size();x++)
		val[x]=vec[x];
	res=sqrt(val)+2*val;
	for(x=0;x<vec.size();x++)
		cout<<val[x]<<"   "<<res[x]<<endl;
	return 0;
}
