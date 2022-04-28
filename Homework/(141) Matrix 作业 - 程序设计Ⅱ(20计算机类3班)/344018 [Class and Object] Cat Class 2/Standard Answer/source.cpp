#include <cstring>

class Cat
{
	void _copy(const char * n) {
		name = new char[strlen(n)+1];
		strcpy(name, n);
	}
	
public:
	char * name;
	Cat(const char * n) {
		_copy(n);
	}
	Cat(const Cat & cat) {
		_copy(cat.name);
	}
	Cat & operator = (const Cat & cat) {
		delete [] name;
		_copy(cat.name);
		return *this;
	}
	const char* get_name() const {
		return name;
	}
};