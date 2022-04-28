#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
class Store
{	private:
		ofstream *ofs;
	public:
		Store(ofstream & of){ofs=&of;}
		bool operator()(const string & s); 
};
void ShowStr(const string & s){cout<<s<<endl;}
void GetStrs(ifstream & fin, vector<string> & v);
int main()
{   vector<string> vostr;
    string temp;
    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);
    ofstream fout("strings.txt", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();
    vector<string> vistr;
    ifstream fin("strings.txt", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {	cerr << "Could not open the file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);
    return 0;
}
bool Store::operator()(const string & s)
{	unsigned int len=s.size();
	if(ofs->is_open())
	{	ofs->write((char *)(&len),sizeof(len));
		ofs->write(s.data(),len);
		return 1;
	}
	else
		return 0;
}
void GetStrs(ifstream & fin, vector<string> & v)
{	unsigned int len;
	while(fin.read((char *)&len,sizeof(len)))
	{	char temp[len];
		fin.read(temp,len);
		v.push_back(temp);
	}
}
