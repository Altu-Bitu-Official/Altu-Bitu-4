#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
  return a.first < b.first;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int  n, s, sum, p1, p2;
  string input;
  map<int, int> m;
  
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    for (int j = 0; j < s; j++)
    {
      cin >> p1 >> p2;
      m.insert(make_pair(p1, p2));
    }
    // 맵을 벡터로 바꿔 sort
    vector<pair<int,int>> v(m.begin(), m.end());
    sort(v.begin(),v.end(),cmp);
    map<int, int>::iterator ite = m.begin(); // 시작자의 두번째를 max로 바꿔가면서 
    int max_score = (*ite).second;
    sum = 0;
    for(auto iter:m)
    {
      if(iter.second<= max_score)
      {
        sum++;
        max_score = iter.second;
      }
    }
    cout << sum << "\n";
    m.clear();
  }
  return 0;
}