#include<iostream>
#include "golf.h"
using namespace std;
int main(void)
{	golf single,arr[3];
	setgolf(single,"Bian Runhua",8);
	int x;
	for(x=0;x<3;x++)
		while(!setgolf(arr[x]))
			continue;
	showgolf(single);
	for(x=0;x<3;x++)
		showgolf(arr[x]);
	handicap(single,9);
	showgolf(single);
	return 0;	
}
