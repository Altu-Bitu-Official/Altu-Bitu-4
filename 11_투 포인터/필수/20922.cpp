// 20922 겹치는 건 싫어
/*
  투 포인터 알고리즘으로 풀 수 있는 문제였습니다.
*/ 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 100001;

int solve(int &N, int &K, vector<int> &a, int cnt[]){
  int s, e = 0; 
  int len = -987654321;
  while(s <= e && e < N){ // 투 포인터 알고리즘의 전제: [s는 e 포인터가 가리키는 인덱스값을 넘어갈 수 없음] && [e는 배열의 맨끝 인덱스 미만] 이어야 한다.
    if(cnt[a[e]] == K){ // 조건 미충족이 되는 순간
      //a[s]를 세어줬던 cnt배열 값을 감소시키고,
      // s의 포인터값을 하나 증가시킨다.
      cnt[a[s]]--;
      s++;
    }
    else {
      cnt[a[e]]++; //해당 값 증가시켜주고
      e++; // 오른쪽 포인터 증가
    }
    len = max(len, abs(s-e));
  }
  return len;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int N, K;
  cin >> N >> K;
  vector<int> a(N, 0); // 수열
  int cnt[MAX] = {0, };
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }  
  cout << solve(N, K, a, cnt) << "\n";
}