#ifndef ST_H_
#define ST_H_
#include <vector>
#include <stdexcept>
#include <sstream>
#include <iomanip>
using namespace std;
template <class K>
class bad_key : public logic_error
{
private:
	K key;

public:
	bad_key(K k) : key(k), logic_error("Haven't found the key ") {}
	virtual string what();
};
template <class K, class V>
class ST
{
private:
	vector<K> key;						//Store keys
	vector<V> value;					//Store values
	bool BinarySearch(K k, int &index); //Binary search function.If the key is founded,set index to the key's index and return 1.Otherwise,set index to where it is supposed and return 0

public:
	bool empty() { return !key.size(); } //return if the symbol table is empty
	int size() { return key.size(); }	 //return the symbol table's size
	bool insert(K k, V v);				 //Insert an element
	bool erase(K k);					 //Delete an element
	bool contains(K k);					 //Seek if a key is in the table
	int rank(K k) const;				 //Seek how many keys is smaller than k
	V operator[](K k) const;			 //Overloaded operator[] as search function
	V &operator[](K k);					 //Overloaded operator[] as search function
	void ShowAll(void);					 //Print all elements in standard format
	void tofile(ostream &os);			 //Print all elements in the input format
};
template <class K>
string bad_key<K>::what()
{
	ostringstream strout;
	strout << logic_error::what() << key << "!";
	return strout.str();
}
template <class K, class V>
bool ST<K, V>::BinarySearch(K k, int &index)
{
	int beg = 0, mid, end = key.size() - 1;
	if (end == -1) //If the symbol table is empty
	{
		index = 0;
		return 0;
	}
	while (beg < end)
	{
		mid = (beg + end) / 2;
		if (key[mid] == k) //If we find the key
		{
			index = mid;
			return 1;
		}
		else if (key[mid] > k) //Find the front half
			end = mid - 1;
		else //Find the back half
			beg = mid + 1;
	}				   //The last element
	if (key[beg] == k) //If we find the key
	{
		index = beg;
		return 1;
	}
	else //Otherwise
	{
		if (key[beg] < k) //If we should insert the key behind the element
			index = beg + 1;
		else //If we should insert the key in front of  the element
			index = beg;
		return 0;
	}
}
template <class K, class V>
bool ST<K, V>::insert(K k, V v)
{
	int index;
	if (!BinarySearch(k, index))			//If the key isn't conflict
	{										//We have got the place to insert
		key.insert(key.begin() + index, k); //Insert it
		value.insert(value.begin() + index, v);
		return 1;
	}
	else //If the key is conflict
		return 0;
}
template <class K, class V>
bool ST<K, V>::erase(K k)
{
	int index;
	if ((BinarySearch(k, index))) //If the key exists
	{
		value.erase(value.begin() + index); //Delete it
		key.erase(key.begin() + index);
		return 1;
	}
	else //If the key doesn't exist
		throw bad_key<K>(k);
}
template <class K, class V>
bool ST<K, V>::contains(K k)
{
	int i;
	return BinarySearch(k, i); //Judge whether the key exists
}
template <class K, class V>
int ST<K, V>::rank(K k) const
{
	int i;
	if (Binarysearch(k, i)) //If the key exists
		return i;
	else
		return -1;
}
template <class K, class V>
V ST<K, V>::operator[](K k) const
{
	int i;
	if (BinarySearch(k, i)) //If the key exists
		return value[i];
	else
		throw bad_key<K>(k);
}
template <class K, class V>
V &ST<K, V>::operator[](K k)
{
	int i;
	if (BinarySearch(k, i)) //If the key exists
		return value[i];
	else
		throw bad_key<K>(k);
}
template <class K, class V>
void ST<K, V>::ShowAll(void)
{
	int x;
	for (x = 0; x < key.size(); x++)
		cout << setw(7) << *(key.begin() + x) << setw(30) << *(value.begin() + x) << endl;
}
template <class K, class V>
void ST<K, V>::tofile(ostream &os)
{
	int x;
	for (x = 0; x < key.size(); x++)
	{
		os << key[x] << "="; //Print the name and "="
		value[x].tofile(os); //Print the polynomial in the input standard
	}
}
#endif
