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
		bool BinarySearch(K k,int & index);
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
bool ST<K,V>::BinarySearch(K k,int & index)
{	int beg=0,mid,end=key.size()-1;
	if(end==-1)
	{	index=0;
		return 0;
	}
	while(beg<=end)
	{	mid=(beg+end)/2;
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
	if(!BinarySearch(k,index))
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
	if((BinarySearch(k,index)))
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
	return BinarySearch(k,i);
}
template<class K,class V>
int ST<K,V>::rank(K k)const
{	int i;
	if(Binarysearch(k,i))
		return i;
	else
		return -1;
}
template<class K,class V>
V ST<K,V>::operator[](K k) const
{	
	int i;
	if(BinarySearch(k,i))
		return value[i];
	else
		throw bad_key<K>(k);
}
template<class K,class V>
V & ST<K,V>::operator[](K k)
{	int i;
	if(BinarySearch(k,i))
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