#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{	srand((unsigned int)time(0));
	FILE * fp;
	fp=fopen("task.txt","w");
	int x,n;
	scanf("%d",&n); 
	for(x=1;x<=n;x++)
	{	fprintf(fp,"%04d%02d%02d ",rand()%92+1930,rand()%12+1,rand()%31+1);
		fprintf(fp,"%c%c%c\n",rand()%26+65,rand()%26+65,rand()%26+65);
	}
	fclose(fp);
	return 0;
}
