#include "tree.h"
#include<fstream>
#include<cstring>
void Print(Item item);
char menu(void);
void eatline(void);
void AddWord(Tree & tr);
void DeleteWord(Tree & tr);
void SearchWord(Tree & tr);
Item MakeItem(void);
int main(void)
{	ifstream fin;
	fin.open("text.txt");
	Item item;
	item.fre=1;
	char ch;
	Tree wordtree;
	int x;
	char *pos,temp[21];
	while(fin.good())
	{	fin>>temp;
		pos=strpbrk(temp,".,?!;");
		if(pos!=NULL)
			*pos='\0';
		item.word=temp;
		for(x=0;x<item.word.length();x++)
			item.word[x]=tolower(item.word[x]);
		wordtree.add(item);
	}
	wordtree.del(item);
	cout<<"WordList:\n";
	wordtree.traverse(Print);
	while((ch=menu())!='q')
	{	switch(ch)
		{	case 'a':AddWord(wordtree);
				break;
			case 'c':cout<<"Total words:"<<wordtree.wordcount()<<endl;
				break;
			case 'd':DeleteWord(wordtree);
				break;
			case 'e':cout<<"IsEmpty:"<<wordtree.isempty();
				break;
			case 'f':cout<<"IsFull:"<<wordtree.isfull();
				break;
			case 'p':cout<<"WordList:\n";
				wordtree.traverse(Print);
				break;
			case 's':SearchWord(wordtree);
				break;
		}
	}
	fin.close();
	return 0;
}
void AddWord(Tree & tr)
{	Item item=MakeItem();
	tr.add(item);
}
void DeleteWord(Tree & tr)
{	Item item=MakeItem();
	if(tr.del(item))
		cout<<"Delete Successfully!\n";
	else
		cout<<"Delete Failed!\n";
}
void SearchWord(Tree & tr)
{	Item item=MakeItem();
	if(tr.search(item))
		Print(item);
	else
		cout<<"Search Failed!\n";
}
Item MakeItem(void)
{	Item item;
	item.fre=1;
	cout<<"Enter a word:";
	cin>>item.word;
	int x;
	for(x=0;x<item.word.length();x++)
		item.word[x]=tolower(item.word[x]);
	eatline();
	return item;
}
void Print(Item item)
{	cout<<item.word<<" exists "<<item.fre<<" time(s)\n";
}
char menu(void)
{	cout<<"Test Program\n";
	cout<<"A-Add C-Count D-Delete E-IsEmpty\n";
	cout<<"F-IsFull P-Print S-Search Q-Quit\n";
	char ch=tolower(cin.get());
	while(strchr("acdefpqs",ch)==NULL)
	{	eatline();
		cout<<"Enter A,C,D,E,F,P,S or Q!";
		ch=tolower(cin.get());
	}
	eatline();
	return ch;
}
void eatline(void)
{	while(cin.get()!='\n')
		continue;
}
