#include <iostream>
#include <algorithm>
#include <iomanip>
#include <set>

using namespace std;

int n;
set<int> had;

int main()
{
 ios::sync_with_stdio(false);
 
 cin >> n;
 int ans = 0;
 
 for(int i = 1; i <= 2 * n; ++i)
 {
  int tmp; cin >> tmp;
  if(!had.count(tmp)) {had.insert(tmp); ans = max(ans, (int)had.size());}
  else had.erase(tmp);
 }
 
 cout << ans << endl;
 return 0;
}