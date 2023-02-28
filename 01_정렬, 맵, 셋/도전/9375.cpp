//9375 map 이용하는 문제
#include <iostream>
#include <map>
using namespace std;
int t;
int n;
int cnt;
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> t;
  while(t--){
    cin >> n;
    map<string, int> mp;
    for(int i = 0; i < n; i++) {
      string fashion, kind;
      cin >> fashion >> kind;
      mp[kind]++;
    }
    cnt=1;
    for(auto x=mp.begin(); x!=mp.end(); x++){
      cnt *= (x->second)+1;
    }
    cout << cnt-1 << "\n";
  }
}