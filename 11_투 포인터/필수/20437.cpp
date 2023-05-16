// 20437 문자열 게임 2
/*
  알파벳 문자별로 등장한 인덱스의 위치값의 1차원 배열 안에서 
  투 포인터 간의 간격이 일정한 '슬라이딩 윈도우(Sliding Window) 기법'을 이용하면 됩니다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 97654321;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    string W;
    vector<vector<int>> alpha_loc(26); // 알파벳 문자별로 등장한 인덱스의 위치 값들을 저장해준다.
    vector<int> cnt(26); // 알파벳 문자별로 등장한 횟수를 저장해준다.
    int K;
    cin >> W;
    cin >> K;
    
    for(int i = 0; i < W.size(); i++){
      int cur_alphaBet = W[i]-'a';
      cnt[cur_alphaBet]++; // 알파벳 문자별로 등장한 횟수를 저장해주는 작업 
      alpha_loc[cur_alphaBet].push_back(i); // 알파벳 문자별로 등장한 인덱스의 위치 값을 저장해주는 작업
    }
    int mn_len = MAX;
    int mx_len = 0;
    // 디버깅: cout << alpha_loc[0]; :: 기대 output :3 (O)

    for(int i = 0; i < W.size(); i++){
      int cur_alphaBet = W[i]-'a';
      if(cnt[cur_alphaBet] >= K){ // 정답의 후보군이 될 수 있는 알파벳 문자에 대하여
        // 투 포인터 - 슬라이딩 윈도우 기법 적용
        int s = 0;
        int e = K-1;
        // 길이가 K인 s, e 인덱스 지정
        while(e < alpha_loc[cur_alphaBet].size()) {
          int cur_len = alpha_loc[cur_alphaBet][e]-alpha_loc[cur_alphaBet][s]+1;
          s++;
          e++;
          mx_len = max(mx_len, cur_len); // mx_len: 문자열 최대 길이 업데이트
          mn_len = min(mn_len, cur_len); // mn_len: 문자열 최소 길이 업데이트
        }
      }
    }

    if(mx_len == 0 || mn_len == MAX) {
      cout << "-1\n";
    }

    else {
      cout << mn_len << " " << mx_len << "\n"; 
    }

  }
}