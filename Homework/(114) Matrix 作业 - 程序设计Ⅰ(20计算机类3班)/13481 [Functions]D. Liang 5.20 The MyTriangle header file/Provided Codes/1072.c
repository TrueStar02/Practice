#include<stdio.h>
#include "MyTriangle.h"

int main(){
	double side1, side2, side3;
	scanf("%lf%lf%lf", &side1, &side2, &side3);
	if(isValid(side1, side2, side3)){
		printf("%.2lf", area(side1, side2, side3));
	}else{
		printf("Invalid!");
	}
	return 0;
}
