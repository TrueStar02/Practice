#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
struct charactertype
{	unsigned int id:		8;
	unsigned int size:		7;
	unsigned int:			1;
	unsigned int color:		3;
	unsigned int:			1;
	unsigned int alignment:	2;
	bool		 bold:		1;
	bool		 italic:	1;
	bool		 underline:	1;
	unsigned int:			7;
};
const char *align[3]={" left ","middle"," right"};
const char *color[8]={" black","  red "," green","yellow"," blue ","purple"," cyan "," white"};
unsigned int GetID(void);
unsigned int GetSize(void);
unsigned int GetColor(void);
unsigned int GetAlign(void);
char ShowSettings(struct charactertype mode);
void eatline(void);
int main(void)
{	struct charactertype mode={1,12,0,0,0,0,0};
	char ch;
	while((ch=ShowSettings(mode))!='q')
	{	switch(ch)
		{	case 'a':mode.id=GetID();
				break;
			case 'b':mode.size=GetSize();
				break;
			case 'c':mode.color=GetColor();
				break;
			case 'd':mode.alignment=GetAlign();
				break;
			case 'e':mode.bold^=1;
				break;
			case 'f':mode.italic^=1;
				break;
			case 'g':mode.underline^=1;
				break;
		}
	}
	puts("Bye~");
	return 0;
}
char ShowSettings(const struct charactertype mode)
{	char ch;
	puts("  ID SIZE   COLOR  ALIGNMENT   B   I   U");
	printf("%4u%5u%8s%9s    ",mode.id,mode.size,color[mode.color],align[mode.alignment]);
	printf("%3s %3s %3s\n\n",mode.bold==1?" on":"off",mode.italic==1?" on":"off",mode.underline==1?" on":"off");
	puts("A-Change Font       B-Change Size  C-Change Color");
	puts("D-Change Alignment  E-Change Bold  F-Change Italid");
	puts("G-Change Underline  Q-Quit");		
	while((ch=tolower(getchar()))&&strchr("abcdefgq",ch)==NULL)
	{	eatline();
		puts("Enter A~G or Q!");
	}
	eatline();
	return ch;
}
unsigned int GetID(void)
{	unsigned int id;
	puts("Enter an ID between 0 and 255");
	while(scanf("%u",&id)!=1||id>255)
	{	eatline();
		puts("Enter an interger between 0 and 255!");
	}
	eatline();
	return id;
}
unsigned int GetSize(void)
{	unsigned int size;
	puts("Enter the size between 0 and 127");
	while(scanf("%u",&size)!=1||size>127)
	{	eatline();
		puts("Enter an interger between 0 and 127!");
	}
	eatline();
	return size;
}
unsigned int GetColor(void)
{	unsigned int color;
	puts("Choose the color");
	puts("0-Black  1-Red    2-Green  3-Yellow");
	puts("4-Blue   5-Purple 6-Cyan   7-White");
	while(scanf("%d",&color)!=1||color>7)
	{	puts("Enter an interger between 0 and 7!");
		eatline();
	}
	eatline();
	return color;
}
unsigned int GetAlign(void)
{	unsigned int align;
	puts("Choose the alignment mode");
	puts("0-Left  1-Middle    2-Right");
	while(scanf("%d",&align)!=1||align>2)
	{	puts("Enter an interger between 0 and 2!");
		eatline();
	}
	eatline();
	return align;
}
void eatline(void)
{	while(getchar()!='\n')
		continue;
}
