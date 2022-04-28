#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define OPAQUE 		0x0001
#define SHOWBORDER	0x0100
#define FILLMASK	0xFFF1
#define BORDERMASK	0xF1FF
#define STYLEMASK	0xCFFF
const char *color[8]={"Black","Red","Green","Yellow","Blue","Purple","Cyan","White"};
const char *style[3]={"Solid","Dotted","Dashed"};
char showsettings(const short box);
int ColorNo(void);
short ChangeFillColor(short box);
short ChangeBorderColor(short box);
short ChangeBorderStyle(short box);
void eatline(void);
int main()
{	short box=0x2507;
	char ch;
	while((ch=showsettings(box))!='q')
	{	switch(ch)
		{	case 'a':box^=OPAQUE;
				break;
			case 'b':box=ChangeFillColor(box);
				break;
			case 'c':box^=SHOWBORDER;
				break;
			case 'd':box=ChangeBorderColor(box);
				break;
			case 'e':box=ChangeBorderStyle(box);
				break;
		}
	}
	return 0;
}
char showsettings(const short box)
{	printf("Opaque:%s\n",box&OPAQUE==1?"True":"Fause");
	printf("Fillcolor:%s\n",color[(box&(~FILLMASK))>>1]);
	printf("Border:%sShown\n",((box&SHOWBORDER)>>8)==1?"":"Not ");
	printf("Bordercolor:%s\n",color[(box&(~BORDERMASK))>>9]);
	printf("Borderstyle:%s\n",style[(box&(~STYLEMASK))>>12]);
	printf("A-Change Opaque       B-Change Fillcolor\n");
	printf("C-Change Border       D-Change Bordercolor\n");
	printf("E-Change Borderstyle  Q-Quit\n");
	char ch;
	while((ch=tolower(getchar()))&&strchr("abcdeq",ch)==NULL)
	{	puts("Enter A,B,C,D,E or Q!");
		eatline();
	}
	eatline();
	return ch;
}
int ColorNo(void)
{	int color;
	puts("Choose the color");
	puts("0-Black  1-Red    2-Green  3-Yellow");
	puts("4-Blue   5-Purple 6-Cyan   7-White");
	while(scanf("%d",&color)!=1||color<0||color>7)
	{	puts("Enter an interger between 0 and 7!");
		eatline();
	}
	eatline();
	return color;
}
short ChangeFillColor(short box)
{	int color=ColorNo();
	box&=FILLMASK;
	box|=(color<<1);
	return box;
}
short ChangeBorderColor(short box)
{	int color=ColorNo();
	box&=BORDERMASK;
	box|=(color<<9);
	return box;
}
short ChangeBorderStyle(short box)
{	puts("Choose the Border Style");
	puts("0-Solid  1-Dotted  2-Dashed");
	int style;
	while(scanf("%d",&style)!=1||style<0||style>2)
	{	puts("Enter an interger between 0 and 2!");
		eatline();
	}
	eatline();
	box&=STYLEMASK;
	box|=(style<<12);
	return box;
}
void eatline(void)
{	while(getchar()!='\n')
		continue;
}
