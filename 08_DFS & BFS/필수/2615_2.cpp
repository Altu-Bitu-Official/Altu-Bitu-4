// 오목
#include <iostream>
#include <vector>

using namespace std;

const int MAX_LEN = 19;
int winner = 0, row, col;
int baduk[MAX_LEN+1][MAX_LEN+1];

int dr[4] = {0,1,-1,1}, dc[4] = {1,0,1,1};

// 이전에 탐색된 방향인가 (반대방향에 해당 색상의 돌이 있었는가)
bool isFirstTravel(int r, int c, int dir, int color){
    int br = r - dr[dir];
    int bc = c - dr[dir];
    
    if (br>=1 && br<=MAX_LEN && bc>=1 && bc<=MAX_LEN && baduk[br][bc] == color){
        return false;
    }
    return true;
}

// 재귀 이용
int dfs(int r, int c, int dir, int color){
    int cnt = 1;
    int nr = r + dr[dir];
    int nc = c + dc[dir];
    
    if (nr>=1 && nr<=MAX_LEN && nc>=1 && nc<=MAX_LEN && baduk[nr][nc] == color){
        cnt += dfs(nr, nc, dir, color);
    }
    return cnt;
}

void game(){
    for (int j=1; j<=MAX_LEN; j++)
        for (int i=1; i<=MAX_LEN; i++){
            if (baduk[i][j] == 0)
                continue;
            for (int k=0; k<4; k++){ // 방향별 탐색
                if (!isFirstTravel(i, j, k, baduk[i][j]))
                    continue;
                if (dfs(i,j,k,baduk[i][j]) == 5){
                    winner = baduk[i][j];
                    row = i, col = j;
                    return;
                }
            }
        }
}

int main(){
    
    for (int i=1; i<=MAX_LEN; i++)
        for (int j=1; j<=MAX_LEN; j++)
            cin >> baduk[i][j];
            
    game();
    cout << winner << '\n';
    if (winner){
        cout << row << ' ' << col;
    }

    return 0;
}