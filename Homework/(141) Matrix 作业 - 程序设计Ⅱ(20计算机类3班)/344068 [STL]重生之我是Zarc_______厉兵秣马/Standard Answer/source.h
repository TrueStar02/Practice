#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
void nature_complete(map<string, int> &nature)
{
	int num = 0;
	string Na;
	int Data;
	while (num < 7)
	{
		cin >> Na >> Data;
		nature.insert({ Na,Data });
		num++;
	}
}

void card_complete(vector<pair<string, int>>& card, map<string, int> &nature)
{
	int num;
	cin >> num;
	for (int i = 0; i < num;)
	{
		i++;
		string std;
		int A; int B; int C; int D; string E; int sum = 0;
		int EE;
		cin >> std >> A >> B >> C >> D >> E;
		if (A >= 12 || E == "god")
			continue;
		EE = nature[E];
		sum += A + 10 * B + 10 * C + 100000 * D + EE;
		card.push_back(make_pair(std, sum));
		//cout << std << " " << sum << endl;
	}
}

bool compare(pair<string, int> a, pair<string, int> b)
{
	if (a.second > b.second)
		return true;
	else
		return false;
}

void print(vector<pair<string, int>> ::iterator begin, vector<pair<string, int>> ::iterator end)
{
	int i = 4;
	while (i>0)
	{
		cout << (*begin).first;
		cout << endl;
		begin++;
		i--;
	}
}