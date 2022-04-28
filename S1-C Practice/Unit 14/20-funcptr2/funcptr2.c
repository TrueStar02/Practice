#include<stdio.h>
#include<ctype.h>
void func1(void);
void func2(void);
void func3(void);
void deft(void);
int main(void)
{	char ch;
	void (*ptr)(void);
	ch=tolower(getchar());
	switch(ch)
	{	case 'a':ptr=func1;
			break;
		case 'b':ptr=func2;
			break;
		case 'c':ptr=func3;
			break;
		default:ptr=deft;
	}
	ptr();
	return 0;
}
void func1(void)
{	puts("Function 1");
}
void func2(void)
{	puts("Function 2");
}
void func3(void)
{	puts("Function 3");
}
void deft(void)
{	puts("Default");
}
