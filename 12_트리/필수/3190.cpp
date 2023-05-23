// 뱀
#include <iostream>
#include <vector>
using namespace std;

// 위쪽:0, 오른쪽:1, 아래쪽:2, 왼쪽:3
void gameStart(int n, vector<vector<bool>> &board, vector<char>direction){
    int t = 0; // 게임 시간
    int x1 = 1, y1 = 1; // 뱀 머리 위치
    int x2 = 1, y2 = 1; // 뱀 꼬리 위치
    int dir1 = 1; // 뱀 머리가 향하는 방향
 
    vector<vector<int>> isSnake(n+1, vector<int>(n+1,-1)); // 뱀의 몸이 있는지 여부
    while (true){
        t++; // 시간 update
        isSnake[x1][y1] = dir1; // 이전 머리 위치에 나아갈 방향 저장
        
        // 뱀이 몸의 길이를 늘려 머리를 다음칸에 위치시킴
        if (dir1 == 1){ // 오른쪽
            y1++;
        }
        else if (dir1 == 3){ // 왼쪽
            y1--;
        }
        else if (dir1 == 0){ // 위쪽
            x1--;
        }
        else{ // 아래쪽
            x1++;
        }
        
        if (x1 > n or x1 <= 0 or y1 > n or y1 <= 0 or (isSnake[x1][y1] != -1)){ // 벽에 닿거나 자기자신의 몸과 부딪치면 
            break;
        }
        
        if (board[x1][y1]){ // 사과가 있으면
            board[x1][y1] = false;
        }
        else{ // 사과가 없으면 몸의 길이를 줄임
            int cur = isSnake[x2][y2]; // 뱀의 꼬리가 향하는 방향
            isSnake[x2][y2] = -1; // 뱀이 공간을 차지X
            
            if (cur == 1){
                y2++;
            }
            else if (cur == 3){
                y2--;
            }
            else if (cur == 0){
                x2--;
            }
            else if (cur == 2){
                x2++;
            }
        }
        
        // t초 후 방향
        if (direction[t] == 'L'){ // 현재 방향에서 왼쪽으로 회전
            dir1 = (dir1 + 3) % 4;
        }
        else if (direction[t] == 'D'){ // 현재 방향에서 오른쪽으로 회전
            dir1 = (dir1 + 1) % 4;
        }
    }
    cout << t;
}

int main()
{
    int n, k, x, y, l, t;
    cin >> n >> k;
    vector<vector<bool>> board(n+1, vector<bool>(n+1,false)); // 보드에 사과여부 저장
    for (int i = 0; i<k; i++){
        cin >> x >> y;
        board[x][y] = true;
    }
    cin >> l;
    vector<char> dir(10001, 'C'); // t초 후 방향 변환
    while (l--){
        cin >> t >> dir[t]; // t초 후 방향 저장
    }
    gameStart(n, board, dir);
    return 0;
}