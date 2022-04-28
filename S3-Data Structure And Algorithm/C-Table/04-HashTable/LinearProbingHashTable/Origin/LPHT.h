#ifndef LPHT_H_
#define LPHT_H_
#include<iostream>
#include<stdexcept>
#include<sstream>
using namespace std;
class bad_key:public logic_error
{	private:
		string key;
	public:
		bad_key(string k):key(k),logic_error("Haven't found the key "){}
		virtual string what();		
};
template<class V,int n>
class LPHT
{	private:
		int _size;
		string key[n];
		V value[n];
		int Hash(const string & k);
	public:
		LPHT();
		bool insert(const string & k,V v);
		bool erase(const string & k);
		bool contains(const string & k);
		V operator[](const string & k) const;
		V & operator[](const string & k);
		void showall(ostream & os);
		void clear(void);
		bool empty(void) const{return !_size;}
		int size(void) const{return _size;}
};
string bad_key::what()
{	ostringstream strout;
	strout<<logic_error::what()<<key<<"!";
	return strout.str();
}
template<class V,int n>
int LPHT<V,n>::Hash(const string & k)
{	int x,v=0;
	for(x=0;x<k.length();x++)
		v+=(x+1)*k[x];
	return v%n;
}
template<class V,int n>
LPHT<V,n>::LPHT()
{	int x;
	for(x=0;x<n;x++)
	key[x]="";
	_size=0;
}
template<class V,int n>
bool LPHT<V,n>::insert(const string & k,V v)
{	int x,index=Hash(k);
	if(key[index]=="")
	{	key[index]=k;
		value[index]=v;
		_size++;
		return 1;
	}
	else
	{	for(x=index+1;x!=index;x=(x+1)%n)
			if(key[x]=="")
			{	key[x]=k;
				value[x]=v;
				_size++;
				return 1;
			}
		if(x==index)
			return 0;
	}
}
template<class V,int n>
bool LPHT<V,n>::erase(const string & k)
{	int x,del=-1,index=Hash(k);
	for(x=index;x<n;x++)
	{	if(key[x]==k)
		{	del=x;
			break;
		}
		else if(key[x]=="")
			return 0;
	}
	if(x==n)
		for(x=0;x<index;x++)
			if(key[x]==k)
			{	del=x;
				break;
			}
			else if(key[x]=="")
				return 0;
	if(del==-1)
		return 0;
	else
	{	key[del]="";
		string kt;
		V vt;
		for(x=del+1;x!=del;x=(x+1)%n)
			if(key[x]=="")
				break;
			else
			{	kt=key[x];
				vt=value[x];
				key[x]="";
				_size--;
				insert(kt,vt);
			}
		_size--;
		return 1;
	}
}
template<class V,int n>
bool LPHT<V,n>::contains(const string & k)
{	int x,index=Hash(k);
	if(key[index]=="")
		return 0;
	else
	{	for(x=index;x<n;x++)
			if(key[x]==k)
				return 1;
			else if(key[x]=="")
				return 0;
		if(x==n)
			for(x=0;x<index;x++)
				if(key[x]==k)
					return 1;
				else if(key[x]=="")
					return 0;
		if(x==index)
			return 0;
	}
}
template<class V,int n>
V LPHT<V,n>::operator[](const string & k) const
{	int x,index=Hash(k);
	if(key[index]=="")
		throw bad_key(k);
	else
	{	for(x=index;x<n;x++)
			if(key[x]==k)
				return value[x];
			else if(key[x]=="")
				throw bad_key(k);
		if(x==n)
			for(x=0;x<index;x++)
				if(key[x]==k)
					return value[x];
				else if(key[x]=="")
					throw bad_key(k);
		if(x==index)
			throw bad_key(k);
	}
}
template<class V,int n>
V & LPHT<V,n>::operator[](const string & k)
{	int x,index=Hash(k);
	if(key[index]=="")
		throw bad_key(k);
	else
	{	for(x=index;x<n;x++)
			if(key[x]==k)
				return value[x];
			else if(key[x]=="")
				throw bad_key(k);
		if(x==n)
			for(x=0;x<index;x++)
				if(key[x]==k)
					return value[x];
				else if(key[x]=="")
					throw bad_key(k);
		if(x==index)
			throw bad_key(k);
	}
}
template<class V,int n>
void LPHT<V,n>::showall(ostream & os)
{	int x;
	for(x=0;x<n;x++)
	{	os<<"Hash:"<<x;
		if(key[x]=="")
			os<<" No data\n";
		else
			os<<" Key:"<<key[x]<<" Value:"<<value[x]<<endl;
	}	
}
template<class V,int n>
void LPHT<V,n>::clear(void)
{	int x;
	for(x=0;x<n;x++)
	key[x]="";
	size=0;
}
#endif
