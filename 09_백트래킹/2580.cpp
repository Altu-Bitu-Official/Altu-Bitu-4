// 2580 스도쿠
// 수정 사항: 틀렸지만, 제출일자까지 수정한 코드를 올립니다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;
const int SIZE = 9;

void printSudoku(vector<vector<int>> &sudokuBoard){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            cout << sudokuBoard[i][j] << " ";
        }
        cout << "\n";
    }
}

bool chkRow(vector<vector<int>> &sudokuBoard, int x, int y){
  for(int i = 0; i < SIZE; i++){
    if(sudokuBoard[x][y] == sudokuBoard[x][i]) {
      if(i != y){
        return false;
      }
      return true;
    }
    return true;
  }
}

bool chkCol(vector<vector<int>> &sudokuBoard, int x, int y){
  for(int i = 0; i < SIZE; i++){
    if(sudokuBoard[x][y] == sudokuBoard[i][y]) {
      if(i != x){
        return false;
      }
      return true;
    }
    return true;
  }
}

bool chkArea(vector<vector<int>> &sudokuBoard, int x, int y){
  // (x_zone, y_zone) : (x, y)가 속한 정사각형의 왼쪽 상단의 꼭짓점 좌표
  int x_zone = x / 3 * 3;
  int y_zone = y / 3 * 3;

  for(int i = 0; i < (SIZE)/3; i++){
    for(int j = 0; j < (SIZE)/3; j++){
      if(sudokuBoard[x_zone + i][y_zone + j]== sudokuBoard[x][y]){
        if(x_zone+i != x || y_zone+j != y){
          return false;
        }
        return true;
      }
    }
  }
  return true;
}

bool isPossible(vector<vector<int>> &sudokuBoard, int x, int y){
  return chkCol(sudokuBoard, x, y) && chkRow(sudokuBoard, x, y) && chkArea(sudokuBoard, x, y);
}

void dfs(vector<vector<int>> &sudokuBoard, vector<pi> &vec, int &N, int depth){
    bool flag =false;
    if(depth == N){
        flag =true;
        return;
    }
    for(int i = 1; i <= SIZE; i++){ //1부터 9까지의 수를 다 넣어보고, 그 후보군이 답을 만족시키는지/아닌지 판단
        sudokuBoard[vec[depth].first][vec[depth].second] = i;
        if(isPossible(sudokuBoard, vec[depth].first, vec[depth].second)) {
            dfs(sudokuBoard, vec, N, depth+1);
          if(flag){
            return;
          }
          sudokuBoard[vec[depth].first][vec[depth].second] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<vector<int>> sudokuBoard(SIZE, vector<int>(SIZE, 0));
    int N = 0; //몇개 채워야 하는지를 담은 변수
    vector<pi> vec; // 채워야 할 board의 좌표값을 담은 vector 배열
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
          cin >> sudokuBoard[i][j];
            if(sudokuBoard[i][j] == 0){ // 채워야 할 부분이면 해당 좌표 쌍들을 vec에 저장
                N++;
                vec.push_back({i, j}); 
            }
        }
    }
    dfs(sudokuBoard, vec, N, 0);
    printSudoku(sudokuBoard);
}
