// 2580 스도쿠
// 왜!!!!!! 안되는지 모르겠습니다...ㅠㅠ 코멘트 부탁드리겠습니다...!ㅠㅠ 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;
bool isPossible(vector<vector<int>> &sudokuBoard, int x, int y){
    for(int i = 0; i < 9; i++){
        if(sudokuBoard[x][y] == sudokuBoard[x][i] && i != y){ //같은 열 체크
            return false; 
        }
        if(sudokuBoard[x][y] == sudokuBoard[i][y] && i != x){ // 같은 행 체크
            return false;
        }
    }
    // 구역 체크
    int x_zone= x/3;
    int y_zone = y/3;
    for(int i = (3*x_zone); i <= (3*x_zone)+3; i++){
        for(int j = (3*y_zone); j <= (3*y_zone+3); j++){
            if(sudokuBoard[x][y] == sudokuBoard[i][j]) {
                if(x != i && y != j){
                    return false;
                }
            }
        }
    }
    return true;
}
void dfs(vector<vector<int>> &sudokuBoard, vector<pi> &vec, int &N, int depth){
    bool flag =false;
    if(depth == N){
      flag =true;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << sudokuBoard[i][j] << " ";
            }
            cout << "\n";
        }
    }
    for(int i = 1; i <= 9; i++){
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
    vector<vector<int>> sudokuBoard(9, vector<int>(9, 0));
    int N = 0; //몇개 채워야 하는지를 담은 변수
    vector<pi> vec; // 채워야 할 board의 좌표값을 담은 vector 배열
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
          cin >> sudokuBoard[i][j];
            if(sudokuBoard[i][j] == 0){
                N++;
                vec.push_back({i, j}); 
            }
        }
    }
    dfs(sudokuBoard, vec, N, 0);
}