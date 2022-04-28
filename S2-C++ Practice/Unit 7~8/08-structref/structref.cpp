#include<iostream>
using namespace std;
struct data
{	string name;
	int attempts;
	int score;
	double efficiency;
};
void display(const data &detail);
void makedata(data &detail);
data & calc(data &target,const data &source);
int main(void)
{	data detail1={"Paff",23,19};
	data detail2={"Neko",25,11};
	data detail3={"Robo-Head",19,16};
	data detail4={"Ivy",76,75};
	data detail5={"Vanessa",33,33};
	data team={"WholeTeam"};
	makedata(detail1);
	makedata(detail2);
	makedata(detail3);
	makedata(detail4);
	makedata(detail5);
	calc(calc(calc(calc(calc(team,detail1),detail2),detail3),detail4),detail5);
	display(detail1);
	display(detail2);
	display(detail3);
	display(detail4);
	display(detail5);
	display(team);
	return 0;
}
void display(const data &detail)
{	cout<<detail.name<<" Attempts:"<<detail.attempts<<" Score:"<<detail.score<<" Efficiency:"<<detail.efficiency<<endl;
}
void makedata(data &detail)
{	detail.efficiency=(double)detail.score/(double)detail.attempts;
}
data & calc(data &target,const data &source)
{	target.attempts+=source.attempts;
	target.score+=source.score;
	makedata(target);
	return target;
}
