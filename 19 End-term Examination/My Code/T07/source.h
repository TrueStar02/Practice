#include<stdio.h>
#include<stdlib.h>

static int comp(const void *ptr1,const void *ptr2);
static double Key(struct Bread br);
void sort(struct Bread breads[], int size)
{	qsort(breads,size,sizeof(struct Bread),comp);
}
static int comp(const void *ptr1,const void *ptr2)
{	struct Bread *b1=(struct Bread *)ptr1;
	struct Bread *b2=(struct Bread *)ptr2;
	double key1=Key(*b1),key2=Key(*b2);
	if ((key2-key1)>0.000001)
		return 1;
	else
		return -1;
}
static double Key(struct Bread br)
{	if(br.weight>br.price&&br.weight>br.size)
		return (br.price+br.size);
	else if(br.price>br.size)
		return (br.size+br.weight);
	else
		return (br.price+br.weight);
}
