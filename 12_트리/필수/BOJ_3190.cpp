#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;

deque<pi> d;

//벰을 움직이고, 계속 움직일 수 있는지 여부를 반환하는 함수
bool moveSnake(vector<vector<bool>>& board, int dir, pi& coor, int n) {
  int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
  coor = {coor.first + dx[dir], coor.second + dy[dir]};   //이동 후 머리 위치

  //벽에 부딪칠 때
  if (coor.first > n || coor.first <= 0 || coor.second > n || coor.second <= 0) {
    return true;  //끝 리턴
  }

  if (find(d.begin(), d.end(), coor) != d.end()){ //현재 위치와 겹치는 원소가 있을 때 == 자신의 몸에 부딛침
    return true;  //끝 리턴
  }
  //머리 푸시
  d.push_front(coor);
  if (board[coor.first][coor.second]) { //이동한 칸에 사과가 있을 때
    board[coor.first][coor.second] = false; //사과 먹기
    return false;
  }
  //사과가 없을 때
  d.pop_back(); //꼬리 제거
  return false;
}

int returnTime(vector<vector<bool>>& board, map<int, char>& m, int n) {
  int cnt = 0;  //게임 시간
  bool is_end = false;  //이동이 끝났는지 여부
  int dir = 0;  //방향
  pi coor = {1, 1}; //현재 머리 위치

  d.push_back(coor);  

  while (true) {
    is_end = moveSnake(board, dir, coor, n);  //이동 수행
    cnt++;  //이동 횟수 증가
    if (is_end) {   //끝났을 시 시간 리턴
      return cnt;
    }
    //방향 전환 : 왼쪽이 -, 오른쪽이 +
    if (m[cnt] == 'L') {
      if (dir == 0) {
        dir = 3;
      } else {
        dir--;
      }
    }
    else if (m[cnt] == 'D') {
      if (dir == 3) {
          dir = 0;
      } else {
          dir++;
       }
    }
  }
}


int main() {
  int n, k, l;
  vector<vector<bool>> board;
  map<int, char> m;

  //입력
  cin >> n >> k;
  board.assign(n+1, vector<bool>(n+1, false));

  while (k--) {
    int x, y;
    cin >> x >> y;
    board[x][y] = true;
  }
  cin >> l;

  while (l--) {
    int x;
    char y;
    cin >> x >> y;
    m[x] = y;
  }

  //출력
  cout << returnTime(board, m, n);
}