// =====================
// framework source code
// =====================
#include <iostream>
#include <iomanip>

#include "source.h"
using namespace std;

void print(const Stock &obj)
{
  cout << fixed << setprecision(2) 
       << obj.getSymbol() << " "
	   << obj.getName() << " " 
	   << obj.getPreviousClosingPrice() << " " 
	   << obj.getCurrentPrice() << " " 
       << obj.changePercent()  << endl;
}


int main() {
	Stock obj1("SUNW","Sun Microsystems Inc");
	obj1.setPreviousClosingPrice(100);
	obj1.setCurrentPrice(90);
	print(obj1);

	return 0;
}
                                
