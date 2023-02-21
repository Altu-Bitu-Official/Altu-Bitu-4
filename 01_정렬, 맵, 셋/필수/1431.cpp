//1431 시리얼 번호
//커스텀함수 이용해서 sort해주면 되는 문제
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n;
vector<pair<int, string>> ans;

bool cmp(pair<int, string> a, pair<int, string> b) {
     if(a.second.size()==b.second.size()) { //길이 같으면
        if(a.first==b.first) { //각 자릿수확인하여 더한 값 같으면
             return a.second<b.second; //사전순 출력
       }
       return a.first<b.first; //각 자릿수 합 작은 것부터 출력
    } 
 return a.second.size()<b.second.size(); //길이 짧은거부터 출력
} 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  while(n--) {
      string input; int cnt=0;
      cin >> input;
      for(int i=0;i<input.size();i++) {
          if(input[i]>=65&&input[i]<=90) continue;
          else cnt+= input[i]-'0';
      } 
     ans.push_back({cnt, input});
  }
  sort(ans.begin(), ans.end(), cmp); 
  for(auto x:ans) {
       cout << x.second << "\n";
  } 
}