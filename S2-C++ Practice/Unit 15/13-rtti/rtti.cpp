#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
class Grand
{	private:
		int hold;
	public:
		Grand(int h=0):hold(h){}
		virtual void Speak() const{cout<<"I am a grand class!\n";}
		int Value() const{return hold;}
};
class Superb:public Grand
{	public:
		Superb(int h=0):Grand(h){}
		virtual void Speak() const{cout<<"I am a superb class!\n";}
		virtual void Say() const{cout<<"I hold the superb value of "<<Value()<<endl;}
};
class NB:public Superb
{	private:
		char v;
	public:
		NB(int h=0,char ch=65):Superb(h),v(ch){}
		virtual void Speak() const{cout<<"I am a NB class!\n";}
		virtual void Say() const{cout<<"I hold the NB value of "<<Value()<<" and the letter "<<v<<endl;}
};
Grand * Make(void);
int main(void)
{	srand((unsigned int)time(0));
	Grand *pg;
	Superb *ps;
	int x;
	for(x=1;x<=10;x++)
	{	pg=Make();
		pg->Speak();
		if(ps=dynamic_cast<Superb *>(pg))
			ps->Say();
	}
	return 0;
}
Grand * Make(void)
{	Grand * temp;
	switch(rand()%3)
	{	case 0:temp=new Grand(rand()%100);
			break;
		case 1:temp=new Superb(rand()%100);
			break;
		case 2:temp=new NB(rand()%100,rand()%26+65);
			break;	
	}
	return temp;
}
