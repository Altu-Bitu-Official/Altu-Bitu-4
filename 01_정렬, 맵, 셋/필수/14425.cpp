//14425 문자열 집합 
#include <iostream>
#include <set>
#include <string>
using namespace std;
int n, m;
set<string> s;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  // 집합에 문자열 입력받기
  while(n--){
    string input;
    cin >> input;
    s.insert(input);
  }
  int cnt=0; // 몇개가 집합에 포함되어있는지 세어주는 카운팅 변수
  // 입력받은 집합에 해당 문자열이 있는지 확인 
  while(m--){
    string input;
    cin >> input;
    if(s.find(input)==s.end()) continue; //집합에 해당 문자열이 없으면 제끼고
    cnt++; //아니면 개수 카운트
  }
  cout << cnt;
}