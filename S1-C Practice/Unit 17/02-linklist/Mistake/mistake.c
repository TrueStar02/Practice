/* This is a mistake */
/* I shouldn't make this mistake again */
bool AddItem(Item item,List *plist)
{	Node *pnode=*plist;
	while(pnode!=NULL)
		pnode=pnode->next;
	Node *pnew=(Node *)malloc(sizeof(Node));
	if(pnew==NULL)
		return 0;
	pnode=pnew;
	pnode->item=item;
	pnode->next=NULL;
	return 1;
}

