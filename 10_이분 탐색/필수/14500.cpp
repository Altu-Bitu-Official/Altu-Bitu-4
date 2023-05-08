// 14500 테트로미노 (구현, 백트래킹)
/*
    'ㅜ' 모양을 제외한 나머지는 depth가 0부터 시작하여 4으로 끝나는 백트래킹으로 처리할 수 있습니다.
    'ㅜ' 모양을 처리 할 때에는, '+' 모양을 먼저 만들어준 다음에 
    가운데 부분에서 가장 최소값을 빼어주는 형태로 구현해줍니다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int dx[] = {1, -1, 0, 0}; // 동 서 남 북
const int dy[] = {0, 0, -1, 1}; 
int answer = 0;

// 'ㅜ'를 제외한 나머지 모양은 depth가 4인 dfs로 만들 수 있습니다.
void makeStandardShape(int &x, int &y, int depth, int sum, int &N, int &M, int TetroMino[][501], bool visited[][501]){
    if(depth == 4){
        answer = max(answer, sum);
        return;
    }
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M){
            // 맵의 탐색 범위를 벗어나면 제끼고
            continue; 
        }
        if(visited[nx][ny]){
            // 이미 방문한 좌표이면 제끼고
            continue;
        }

        visited[nx][ny] = true; // 방문 처리를 해준 후에,
        makeStandardShape(nx, ny, depth + 1, sum + TetroMino[nx][ny], N, M, TetroMino, visited);
        visited[nx][ny] = false;
    }
}

// 'ㅜ' 모양은 '+'모양에서, 동서남북 방향에서 하나씩 빼어주면 됩니다.
void makeWOOShape(int &x, int &y, int sum, int &N, int &M, int TetroMino[][501], bool visited[][501]){
    sum = TetroMino[x][y]; // 해당 좌표는 'ㅜ' 모양에서 가운데 부분의 좌표입니다.
    int sub = 987654321; // 가운데 부분에서 상, 하, 좌, 우로 뻗어나갈 좌표 중 가장 최솟값을 골라냅니다.
    // 가장 최솟값을 제거하면, 만들 수 있는 'ㅜ' 'ㅓ' 'ㅗ' 'ㅏ' 모양 중 가장 큰 값을 골라 낼 수 있습니다.

    /* '+' 모양 만들어주기 */ 
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1|| ny < 1 || nx > N || ny > M){
            // 한 칸 이동했을 때의 값이 맵의 탐색 범위를 넘어가면 제끼고
            continue;
        }
        if(visited[nx][ny]) {
            continue;
        } 
        sub = min(sub, TetroMino[nx][ny]); // 가장 작은 값을 골라냅니다.
        sum += TetroMino[nx][ny]; // 상하좌우에 있는 값을 모조리 더하면 '+' 모양이 완성됩니다.
    }
    /* 이제 상하좌우에 있는 값 중 작은 값을 빼어서 'ㅓ' 'ㅗ' 'ㅏ' 'ㅜ' 모양을 만듭니다. */
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
         if(nx < 1 || ny < 1 || nx > N || ny > M){
            continue;
            answer = max(answer, sum - sub);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    // 입력 받는다.
    int N, M;
    cin >> N >> M;
    int TetroMino[501][501];
    bool visited[501][501] = {false, }; 
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> TetroMino[i][j];
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            makeWOOShape(i, j, 0, N, M, TetroMino, visited);
            visited[i][j] = true;
            makeStandardShape(i, j, 0, 0, N, M, TetroMino, visited);
            visited[i][j] = false;
        }
    }

    cout << answer << "\n";
}