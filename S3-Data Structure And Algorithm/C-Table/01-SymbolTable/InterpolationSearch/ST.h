#ifndef ST_H_
#define ST_H_
#include<vector>
#include<stdexcept>
#include<sstream>
using namespace std;
template<class K>
class bad_key:public logic_error
{	private:
		K key;
	public:
		bad_key(K k):key(k),logic_error("Haven't found the key "){}
		virtual string what();		
};
template<class K,class V>
class ST
{	private:
		vector<K> key;
		vector<V> value;
		bool InterpolationSearch(K k,int & index);
	public:
		bool empty(){return !key.size();}
		int size(){return key.size();}
		bool add(K k,V v);
		bool del(K k);
		bool contains(K k);
		int rank(K k)const;
		V operator[](K k) const;
		V & operator[](K k);
		void ShowAll(void);
};
template<class K>
string bad_key<K>::what()
{	ostringstream strout;
	strout<<logic_error::what()<<key<<"!";
	return strout.str();
}
template<class K,class V>
bool ST<K,V>::InterpolationSearch(K k,int & index)
{	int beg=0,mid,end=key.size()-1;
	if(end==-1)
	{	index=0;
		return 0;
	}
	while(beg<=end)
	{	if(k<key[beg])
		{	index=beg;
			return 0;
		}
		else if(k>key[end])
		{	index=end+1;
			return 0;
		}
		mid=beg+(end-beg)*(k-key[beg])/(key[end]-key[beg]);
		if(key[mid]==k)
		{	index=mid;
			return 1;
		}
		else if(key[mid]>k)
			end=mid-1;
		else
			beg=mid+1;
	}
	index=beg;
	return 0;
}
template<class K,class V>
bool ST<K,V>::add(K k,V v)
{	int index;
	if(!InterpolationSearch(k,index))
	{	key.insert(key.begin()+index,k);
		value.insert(value.begin()+index,v);
		return 1;
	}
	else
		return 0;
}
template<class K,class V>
bool ST<K,V>::del(K k)
{	int index;
	if((InterpolationSearch(k,index)))
	{	value.erase(value.begin()+index);
		key.erase(key.begin()+index);
		return 1;
	}
	else
		throw bad_key<K>(k);
}
template<class K,class V>
bool ST<K,V>::contains(K k)
{	int i;
	return InterpolationSearch(k,i);
}
template<class K,class V>
int ST<K,V>::rank(K k)const
{	int i;
	if(InterpolationSearch(k,i))
		return i;
	else
		return -1;
}
template<class K,class V>
V ST<K,V>::operator[](K k) const
{	
	int i;
	if(InterpolationSearch(k,i))
		return value[i];
	else
		throw bad_key<K>(k);
}
template<class K,class V>
V & ST<K,V>::operator[](K k)
{	int i;
	if(InterpolationSearch(k,i))
		return value[i];
	else
		throw bad_key<K>(k);
}
template<class K,class V>
void ST<K,V>::ShowAll(void)
{	cout<<"ShowAll:\n";
	int x;
	for(x=0;x<key.size();x++)
		cout<<*(key.begin()+x)<<"   "<<*(value.begin()+x)<<endl;
}
#endif
