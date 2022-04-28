#include "orderedlist.h"
void ShowList(Item item);
int main(void)
{	Item i1={"GFR","AIS",98};
	Item i2={"ACG","UNM",87};
	Item i3={"MPP","SCI",87};
	Item i4={"UNO","AGG",75};
	Item i5={"MPP","MAS",88};
	Item i6={"MPP","INS",88};
	List test;
	InitializeList(&test);
	printf("%d\n",AddItem(&test,i1));
	printf("%d\n",ListItemCount(&test));
	Traverse(&test,ShowList);
	printf("%d\n",AddItem(&test,i2));
		printf("%d\n",ListItemCount(&test));
	Traverse(&test,ShowList);
	printf("%d\n",AddItem(&test,i3));
		printf("%d\n",ListItemCount(&test));
	Traverse(&test,ShowList);
	printf("%d\n",AddItem(&test,i4));
		printf("%d\n",ListItemCount(&test));
	Traverse(&test,ShowList);
	printf("%d\n",DeleteItem(&test,&i3));
		printf("%d\n",ListItemCount(&test));
	Traverse(&test,ShowList);/*
	printf("%d\n",AddItem(&test,i5));
	Traverse(&test,ShowList);
	printf("%d\n",AddItem(&test,i6));
	Traverse(&test,ShowList);
	printf("%d\n",DeleteItem(&test,&i5));
	Traverse(&test,ShowList);
	printf("%d\n",AddItem(&test,i1));
	Traverse(&test,ShowList);
	printf("%d\n",DeleteItem(&test,&i5));
	Traverse(&test,ShowList);*/
	EmptyList(&test);
	return 0;
}
void ShowList(Item item)
{	printf("%s %s %d\n",item.title,item.director,item.score);
}
