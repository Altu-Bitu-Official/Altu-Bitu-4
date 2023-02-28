#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
  int  n, m, sum;
  string input;
  map<string, bool> s;
  
  cin >> n >> m;
  while (n--)
  {
    cin >> input;
    s[input] = true;
  }
  sum = 0;
  while (m--)
  {
    cin >> input;
    if(s[input] == true)
      sum++;
  }
  cout << sum << "\n";
  return 0;
}