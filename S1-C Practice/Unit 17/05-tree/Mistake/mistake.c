bool DeleteItem(Item *item,Tree *ptr)
{	Pair ppair=SeekItem(item,ptr);
	if(ppair.child==NULL)
	{	printf("Couldn't find this item\n");
		return 0;
	}
	DeleteNode(&ppair.child);
	ptr->items--;
	return 1;
}
