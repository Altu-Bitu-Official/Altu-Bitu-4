#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool is_hansoo(int X) { //한수인지 아닌지 체크해주는 함수
  vector<int> jari; //각 자리수를 담는 벡터
  while(X!=0) { //584를 담으면 해당 벡터에 4, 8, 5순서대로 저장
    jari.push_back(X%10);
    X/=10;
  }
  bool flag = true; 
  int K= jari[1]-jari[0];
  for(int i=jari.size()-1; i>=1; i--) {
  (jari[i]-jari[i-1]==K)? : flag=false; 
  } 
  if(!flag) {
      return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int N;
  cin >> N; 
  int ans=0; //한수가 몇개인지 세어준다.
  for(int i=1; i<=N; i++) { //브루트 포스 진행
    if(is_hansoo(i)) {
      ans++; 
    } 
  }
  cout << ans;
}