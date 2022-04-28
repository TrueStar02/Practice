#include<stdio.h>
#include<string.h>
#include<stdbool.h>
char *nbgets(char *st,int n);
enum rainbow{red,orange,yellow,green,cyan,blue,purple};
const char *colors[]={"red","orange","yellow","green","cyan","blue","purple"};
int main(void)
{	char choice[11];
	enum rainbow color;
	bool isfound=0;
	puts("Enter a color(empty to quit)");
	while(nbgets(choice,11)!=NULL&&choice[0]!='\0')
	{	for(color=red;color<=purple;color++)
			if(!strcmp(choice,colors[color]))
			{	isfound=0;
				break;
			}
		switch(color)
		{	case red:puts("Roses");
				break;
			case orange:puts("Poppies");
				break;
			case yellow:puts("Sunflowers");
				break;
			case green:puts("Grass!!!!!");
				break;
			case cyan:puts("I don't know!");
				break;
			case blue:puts("Blueberry");
				break;
			case purple:puts("Violets");
				break;
			default:puts("I don't know the color");		
		}
		isfound=0;
		puts("Next color");
	}
	puts("Goodbye~");
	return 0;
}
char *nbgets(char *st,int n)
{	char *ptr;
 	ptr=fgets(st,n,stdin);
 	int i=0;
 	if(ptr)
 	{	while(st[i]!='\0'&&st[i]!='\n')
  			i++;
  		if(st[i]=='\n')
  			st[i]='\0';
  		else
  			while(getchar()!='\n')
 				continue;
 	}
 	return ptr;
}
