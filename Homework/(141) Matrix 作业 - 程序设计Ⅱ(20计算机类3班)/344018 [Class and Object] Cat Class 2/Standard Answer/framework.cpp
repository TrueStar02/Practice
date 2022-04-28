#include <iostream>
using namespace std;

#include "source.cpp"

void print_cat(const Cat& cat) {
	cout << "This is my cat: ";
	const char * name = cat.get_name();
	cout << name << endl;
}

int main() {
	string name, name2;
	cin >> name >> name2;
	Cat cat(name.c_str());
	Cat cat2(name2.c_str());
	cout << (cat.name == cat.get_name()) << endl;
	cout << (cat.name != name.c_str()) << endl;
	print_cat(cat);
	cat = cat2;
	cout << (cat.name == cat.get_name()) << endl;
	cout << (cat.name != cat2.name) << endl;
	print_cat(cat);
}