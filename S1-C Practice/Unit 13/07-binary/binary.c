#include<stdio.h>
#include<stdlib.h>
int main()
{	double arr[1000],val;
	int x;
	long pos,index;
	for(x=0;x<1000;x++)
	arr[x]=100.0*x+1.0/(x+1);
	FILE *fp;
	if((fp=fopen("number.txt","wb"))==NULL)
	{	fprintf(stderr,"I can't open the flie!\n");
		exit(EXIT_FAILURE);
	}
	fwrite(arr,sizeof(double),1000,fp);
	if(fclose(fp))
	{	fprintf(stderr,"I can't close the file!\n");
		exit(EXIT_FAILURE);
	}
	if((fp=fopen("number.txt","rb"))==NULL)
	{	fprintf(stderr,"I can't open the flie!\n");
		exit(EXIT_FAILURE);
	}
	printf("where to read?\n");
	while(scanf("%ld",&index)==1&&index>=0&&index<100)
	{	pos=index*sizeof(double);
		fseek(fp,pos,SEEK_SET);
		fread(&val,sizeof(double),1,fp);
		printf("%lf\n",val);
		printf("where to read?\n");
	}
	if(fclose(fp))
	{	fprintf(stderr,"I can't close the file!\n");
		exit(EXIT_FAILURE);
	}
	printf("Byebye!\n");
	return 0;
}
