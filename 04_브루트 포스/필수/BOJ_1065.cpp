#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

set<int> make_hansu()
{
  set<int> hansu;
  for (int i = 1; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      int k = j - i;
      if (j + k >= 0 && j + k <= 9)
      {
        hansu.insert(i*100 + j * 10 + j + k);
      }
    }
  }
  return hansu;
}

int main() {
  int n, count = 0;
  cin >> n;
  if (n <= 99)
  {
    cout << n;
  }
  else if (n <= 110)
  {
    cout << "99";
  }
  else if (n <= 998)
  {
    set<int> s = make_hansu();
    for(auto iter = s.begin(); iter != s.end(); iter++){
      if ((*iter) > n)
      {
        cout << 99 + count;
        break;
      }
      count++;
    }
  }
  else if (n == 999 || n == 1000)
  {
    cout << "144";
  }
  return 0;
}