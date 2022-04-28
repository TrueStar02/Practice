#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
struct boxprops
{	bool opaque:				1;		
	unsigned int fillcolor:		3;		//black0	red1	green2 yellow3
	unsigned int:				4;
	bool showborder:			1;		
	unsigned int bordercolor:	3;		//blue4		purple5	cyan6	white7
	unsigned int borderstyle:	2;		//solid0	dotted1	dashed2
	unsigned int:				2;
};
const char *color[8]={"Black","Red","Green","Yellow","Blue","Purple","Cyan","White"};
const char *style[3]={"Solid","Dotted","Dashed"};
char showsettings(const struct boxprops *ptr);
int ColorNo(void);
void ChangeBorderStyle(struct boxprops *ptr);
void eatline(void);
int main()
{	struct boxprops box={1,3,1,2,2};
	char ch;
	while((ch=showsettings(&box))!='q')
	{	switch(ch)
		{	case 'a':box.opaque^=1;
				break;
			case 'b':box.fillcolor=ColorNo();
				break;
			case 'c':box.showborder^=1;
				break;
			case 'd':box.bordercolor=ColorNo();
				break;
			case 'e':ChangeBorderStyle(&box);
				break;
		}
	}
	return 0;
}
char showsettings(const struct boxprops *ptr)
{	printf("Opaque:%s\n",ptr->opaque==1?"True":"Fause");
	printf("Fillcolor:%s\n",color[ptr->fillcolor]);
	printf("Border:%sShown\n",ptr->showborder==1?"":"Not ");
	printf("Bordercolor:%s\n",color[ptr->bordercolor]);
	printf("Borderstyle:%s\n",style[ptr->borderstyle]);
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
void ChangeBorderStyle(struct boxprops *ptr)
{	puts("Choose the Border Style");
	puts("0-Solid  1-Dotted  2-Dashed");
	int style;
	while(scanf("%d",&style)!=1||style<0||style>2)
	{	puts("Enter an interger between 0 and 2!");
		eatline();
	}
	eatline();
	ptr->borderstyle=style;
		
}
void eatline(void)
{	while(getchar()!='\n')
		continue;
}
