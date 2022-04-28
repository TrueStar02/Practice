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
template<class V>
class LPHT
{	private:
		int _size;
		string * key;
		V * value;
		int n;
		int Hash(const string & k);
		bool resize(int nsize);
	public:
		LPHT();
		LPHT(const LPHT & ht);
		LPHT(LPHT && ht);
		~LPHT();
		LPHT & operator=(const LPHT & ht);
		LPHT & operator=(LPHT && ht);
		bool insert(const string & k,V v);
		bool erase(const string & k);
		bool contains(const string & k);
		V operator[](const string & k) const;
		V & operator[](const string & k);
		void showall(ostream & os);
		void clear(void);
		bool empty(void) const{return !_size;}
		int size(void) const{return _size;}
		int capacity(void){return n;}
};
string bad_key::what()
{	ostringstream strout;
	strout<<logic_error::what()<<key<<"!";
	return strout.str();
}
template<class V>
int LPHT<V>::Hash(const string & k)
{	int x,v=0;
	for(x=0;x<k.length();x++)
		v+=(x+1)*k[x];
	return v%n;
}
template<class V>
bool LPHT<V>::resize(int nsize)
{	if(nsize<25||nsize<_size)
		return 0;
	string * ktemp=key;
	V * vtemp=value;
	int temp=n;
	n=nsize;
	key=new string[nsize];
	value=new V[nsize];
	int x;
	for(x=0;x<nsize;x++)
		key[x]="";
	for(x=0;x<temp;x++)
		if(ktemp[x]!="")
		{	_size--;
			insert(ktemp[x],vtemp[x]);
		}
	delete [] ktemp;
	delete [] vtemp;
	return 1;
}
template<class V>
LPHT<V>::LPHT():n(25),_size(0)
{	int x;
	key=new string[25];
	value=new V[25];
	for(x=0;x<n;x++)
		key[x]="";
}
template<class V>
LPHT<V>::LPHT(const LPHT<V> & ht):n(ht.n),_size(ht._size)
{	key=new string[n];
	value=new V[n];
	int x;
	for(x=0;x<n;x++)
	{	key[x]=ht.key[x];
		value[x]=ht.value[x];
	}
}
template<class V>
LPHT<V>::LPHT(LPHT<V> && ht):n(ht.n),_size(ht._size)
{	key=ht.key;
	value=ht.value;
	ht.key=NULL;
	ht.value=NULL;
}
template<class V>
LPHT<V>::~LPHT()
{	delete [] key;
	delete [] value;
}
template<class V>
LPHT<V> & LPHT<V>::operator=(const LPHT<V> & ht)
{	if(&ht==this)
		return *this;
	delete [] key;
	delete [] value;
	n=ht.n;
	_size=ht._size;
	key=new string[n];
	value=new V[n];
	int x;
	for(x=0;x<n;x++)
	{	key[x]=ht.key[x];
		value[x]=ht.value[x];
	}
	return *this;
}
template<class V>
LPHT<V> & LPHT<V>::operator=(LPHT<V> && ht)
{	delete [] key;
	delete [] value;
	n=ht.n;
	_size=ht._size;
	key=ht.key;
	value=ht.value;
	ht.key=NULL;
	ht.value=NULL;
	return *this;
}
template<class V>
bool LPHT<V>::insert(const string & k,V v)
{	int x,index=Hash(k);
	if(key[index]=="")
	{	key[index]=k;
		value[index]=v;
		_size++;
		if(_size*2>n)
			resize(n*2);
		return 1;
	}
	else
	{	for(x=index+1;x<n;x++)
			if(key[x]=="")
			{	key[x]=k;
				value[x]=v;
				_size++;
				if(_size*2>n)
					resize(n*2);
				return 1;
			}
		if(x==n)
			for(x=0;x<index;x++)
				if(key[x]=="")
				{	key[x]=k;
					value[x]=v;
					_size++;
					if(_size*2>n)
						resize(n*2);
					return 1;	
				}
		if(x==index)
			return 0;
	}
}
template<class V>
bool LPHT<V>::erase(const string & k)
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
		for(x=del+1;x<n;x++)
			if(key[x]=="")
				break;
			else
			{	kt=key[x];
				vt=value[x];
				key[x]="";
				_size--;
				insert(kt,vt);
			}
		if(x==n)
			for(x=0;x<del;x++)
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
		if(_size*8<n&&n>=50)
			resize(n/2);
		return 1;
	}
}
template<class V>
bool LPHT<V>::contains(const string & k)
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
template<class V>
V LPHT<V>::operator[](const string & k) const
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
template<class V>
V & LPHT<V>::operator[](const string & k)
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
template<class V>
void LPHT<V>::showall(ostream & os)
{	int x;
	for(x=0;x<n;x++)
	{	os<<"Hash:"<<x;
		if(key[x]=="")
			os<<" No data\n";
		else
			os<<" Key:"<<key[x]<<" Value:"<<value[x]<<endl;
	}	
}
template<class V>
void LPHT<V>::clear(void)
{	int x;
	for(x=0;x<n;x++)
	key[x]="";
	size=0;
	resize(25);
}
#endif
