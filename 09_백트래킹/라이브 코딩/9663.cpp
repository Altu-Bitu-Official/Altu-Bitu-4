// N-Queen
#include <iostream>
#include <vector>

using namespace std;

const int N = 15;

int n, ans;

bool is_queen_in_col[N];
bool is_queen_in_left[2*N];
bool is_queen_in_right[2*N];

void backtrack(int r){ // 현재 행의 번호 r
    // 종료 조건
    if (r == n){
        ans++;
        return;
    }
    // 열번호 c
    for (int c=0; c<n; c++){
      // 세로, 좌하향 대각선, 우하향 대각선 모두에 퀸이 없을 경우 -> 퀸 배치
      if (!is_queen_in_col[c] && !is_queen_in_left[r+c] && !is_queen_in_right[r-c+n]){
          is_queen_in_col[c] = true;
          is_queen_in_left[r+c] = true;
          is_queen_in_right[r-c+n] = true;
          
          // 다음 행에 퀸 놓기
          backtrack(r+1);
          
          // 반납
          is_queen_in_col[c] = false;
          is_queen_in_left[r+c] = false;
          is_queen_in_right[r-c+n] = false;
      }
    }
}

int main(){
    
    cin >> n;
    backtrack(0);
    cout << ans;
    
    return 0;
}