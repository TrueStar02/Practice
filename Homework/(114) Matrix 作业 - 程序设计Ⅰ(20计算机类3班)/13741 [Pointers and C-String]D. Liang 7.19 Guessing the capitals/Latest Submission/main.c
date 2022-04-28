#include<stdio.h>
#include<string.h>
struct usa
{   char state[20];
    char capital[20];
};
const struct usa States[49]={{"Alabama","Montgomery"},{"Alaska","Juneau"},{"Arizona","Phoenix"},{"Arkansas","Little Rock"},{"California","Sacramento"},{"Colorado","Denver"},{"Connecticut","Hartford"},{"Delaware","Dover"},{"Florida","Tallahassee"},{"Georgia","Atlanta"},{"Hawaii","Honolulu"},{"Idaho","Boise"},{"Illinois","Springfield"},{"Maryland","Annapolis"},{"Minnesota","Saint Paul"},{"Iowa","Des Moines"},{"Maine","Augusta"},{"Kentucky","Frankfort"},{"Indiana","Indianapolis"},{"Kansas","Topeka"},{"Louisiana","Baton Rouge"},{"Oregon","Salem"},{"Oklahoma","Oklahoma City"},{"Ohio","Columbus"},{"North Dakota","Bismark"},{"New York","Albany"},{"New Mexico","Santa Fe"},{"New Jersey","Trenton"},{"New Hampshire","Concord"},{"Nevada","Carson City"},{"Nebraska","Lincoln"},{"Montana","Helena"},{"Missouri","Jefferson City"},{"Mississippi","Jackson"},{"Massachusettes","Boston"},{"Michigan","Lansing"},{"Pennslyvania","Harrisburg"},{"Rhode Island","Providence"},{"South Carolina","Columbia"},{"South Dakota","Pierre"},{"Tennessee","Nashville"},{"Texas","Austin"},{"Utah","Salt Lake City"},{"Vermont","Montpelier"},{"Virginia","Richmond"},{"Washington","Olympia"},{"West Virginia","Charleston"},{"Wisconsin","Madison"},{"Wyoming","Cheyenne"}};
char *nbgets(char *st,int n);
int main(void)
{   char state[21],capital[21];
    int tasks,x,y;
    scanf("%d",&tasks);
    getchar();
    for(x=1;x<=tasks;x++)
    {   fgets(state,21,stdin);
        fgets(capital,21,stdin);
        for(y=0;y<=48;y++)
            if(!strcmp(state,States[y].state))
                break;
        if(!strcmp(capital,States[y].capital))
            printf("Your anwswer is correct\n");
        else
            printf("The capital of %s is %s\n",States[y].state,States[y].capital);
    }
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