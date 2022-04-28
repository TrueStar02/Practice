#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#define IDMASK		0x000000FF
#define SIZEMASK 	0x00007F00
#define COLORMASK	0x00070000
#define ALIGNMASK	0x00300000
#define BOLD		0x00400000
#define ITALIC		0x00800000
#define UNDERLINE	0x01000000
const char *align[3]={" left ","middle"," right"};
const char *color[8]={" black","  red "," green","yellow"," blue ","purple"," cyan "," white"};
unsigned int ChangeID(unsigned int mode);
unsigned int ChangeSize(unsigned int mode);
unsigned int ChangeColor(unsigned int mode);
unsigned int ChangeAlign(unsigned int mode);
char ShowSettings(unsigned int mode);
void eatline(void);
int main(void)
{	unsigned int mode=0x00000C01;
	char ch;
	while((ch=ShowSettings(mode))!='q')
	{	switch(ch)
		{	case 'a':mode=ChangeID(mode);
				break;
			case 'b':mode=ChangeSize(mode);
				break;
			case 'c':mode=ChangeColor(mode);
				break;
			case 'd':mode=ChangeAlign(mode);
				break;
			case 'e':mode^=BOLD;
				break;
			case 'f':mode^=ITALIC;
				break;
			case 'g':mode^=UNDERLINE;
				break;
		}
	}
	puts("Bye~");
	return 0;
}
char ShowSettings(unsigned int mode)
{	char ch;
	puts("  ID SIZE   COLOR  ALIGNMENT   B   I   U");
	printf("%4u%5u%8s%9s    ",mode&IDMASK,(mode&SIZEMASK)>>8,color[(mode&(COLORMASK))>>16],align[(mode&(ALIGNMASK))>>20]);
	printf("%3s %3s %3s\n\n",((mode&BOLD)>>22)==1?" on":"off",((mode&ITALIC)>>23)==1?" on":"off",((mode&UNDERLINE)>>24)==1?" on":"off");
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
unsigned int ChangeID(unsigned int mode)
{	unsigned int id;
	puts("Enter an ID between 0 and 255");
	while(scanf("%u",&id)!=1||id>255)
	{	eatline();
		puts("Enter an interger between 0 and 255!");
	}
	eatline();
	mode&=(~IDMASK);
	mode|=id;
	return mode;
}
unsigned int ChangeSize(unsigned int mode)
{	unsigned int size;
	puts("Enter the size between 0 and 127");
	while(scanf("%u",&size)!=1||size>127)
	{	eatline();
		puts("Enter an interger between 0 and 127!");
	}
	eatline();
	mode&=(~SIZEMASK);
	mode|=(size<<8);
	return mode;
}
unsigned int ChangeColor(unsigned int mode)
{	unsigned int color;
	puts("Choose the color");
	puts("0-Black  1-Red    2-Green  3-Yellow");
	puts("4-Blue   5-Purple 6-Cyan   7-White");
	while(scanf("%d",&color)!=1||color>7)
	{	puts("Enter an interger between 0 and 7!");
		eatline();
	}
	eatline();
	mode&=(~COLORMASK);
	mode|=(color<<16);
	return mode;
}
unsigned int ChangeAlign(unsigned int mode)
{	unsigned int align;
	puts("Choose the alignment mode");
	puts("0-Left  1-Middle    2-Right");
	while(scanf("%d",&align)!=1||align>2)
	{	puts("Enter an interger between 0 and 2!");
		eatline();
	}
	eatline();
	mode&=(~ALIGNMASK);
	mode|=(align<<20);
	return mode;
}
void eatline(void)
{	while(getchar()!='\n')
		continue;
}
