// 14889 스타트와 링크
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void calC(vector<vector<int>> &a, vector<bool> &visited, int &N, int &start, int &link){
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
          if(visited[i] && visited[j]) {
            start += a[i][j];
          }
          if(!visited[i] && !visited[j]) {
            link += a[i][j];
          }
       }
    }
    return;
}
void solve(vector<vector<int>> &a, vector<bool> &visited, int &ans, int &N, int depth, int next){ 
  //next는 다음값, 1로 초기화되어있어야
  if(depth == N/2) {
    int start, link; // 초기화 주의 // int start, link=0;
    start = 0, link = 0;// 멈추고 스타트,링크팀 능력치 각각 계산 
    calC(a, visited, N, start, link); // 수정 사항: 계산해주는 부분은 따로 함수로 빼는 것이 좋음!!
    int tmp = abs(start-link);
    tmp = min(ans, tmp);
    return;
  }
  for(int i = next; i < N; i++) {
    visited[i] = true;
    solve(a, visited, ans, N, depth+1, i+1); 
    visited[i] = false; // 부모노드 상태로 초기화
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int N;   
  vector<vector<int>> a(24, vector<int>(24));
  vector<bool> visited(24, false);
  int ans = 987654321; 
  cin >> N;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> a[i][j];
    } 
  }
  solve(a, visited, ans, N, 0, 1); 
  cout << ans;
}
