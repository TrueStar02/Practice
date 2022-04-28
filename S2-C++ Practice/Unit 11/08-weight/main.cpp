#include "weight.h"
int main(void)
{	double x=13398.92;
	Weight w1=x;
	Weight w2(6634.57);
	Weight w3(21,551.44);
	cout<<w1<<w2<<w3;
	cout<<(x>w2)<<(x<w2)<<(x==w2)<<(w2>=w3)<<(w2<=w3)<<(w2!=w3)<<endl;
	x=w1+w2;
	w1=w1-w2;
	Weight w4=112.5+x;
	w4.sw_mode(6);
	w4.sw_mode(3);
	w1.sw_mode(1);
	w2=2.0*w2;
	w3=w3/2.0;
	cout<<w1<<w2<<w3<<w4;
	return 0;
}
