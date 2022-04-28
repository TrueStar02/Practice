#include<set>
#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;
int main()
{	ostream_iterator<string,char> out_iter(cout," ");
	string s1[5]={"love","is","an","open","door"};
	string s2[5]={"she","is","a","math","teacher"};
	set<string> sa(s1,s1+5);
	set<string> sb(s2,s2+5);
	cout<<"Set A:"<<endl;
	copy(sa.begin(),sa.end(),out_iter);
	cout<<endl<<"Set B:"<<endl;
	copy(sb.begin(),sb.end(),out_iter);
	cout<<endl<<"Union Set:"<<endl;
	set_union(sa.begin(),sa.end(),sb.begin(),sb.end(),out_iter);
	cout<<endl<<"Intersection Set:"<<endl;
	set_intersection(sa.begin(),sa.end(),sb.begin(),sb.end(),out_iter);
	cout<<endl<<"Difference Set:"<<endl;
	set_difference(sa.begin(),sa.end(),sb.begin(),sb.end(),out_iter);
	set<string> sc;
	set_union(sa.begin(),sa.end(),sb.begin(),sb.end(),insert_iterator<set<string>>(sc,sc.begin()));
	sc.insert("nest");
	cout<<endl<<"Set C:"<<endl;
	copy(sc.begin(),sc.end(),out_iter);
	cout<<endl<<"A range:"<<endl;
	copy(sc.upper_bound("city"),sc.lower_bound("shy"),out_iter);
	cout<<endl;
	return 0;
}
