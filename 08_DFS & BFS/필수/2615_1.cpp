// 오목
#include <vector>
#include <iostream>

using namespace std;

/*
 * - 게임에서 이기면 연속된 다섯 개의 가장 왼쪽 위에 있는 바둑알을 출력해야 하므로 탐색 방향에 유의
 * - 여섯 알 이상이 연속이면 오목 X
 * 1. 바둑판의 상태를 입력받아 검은색 돌의 위치와 흰색 돌의 위치를 각각 저장
 * 2. 각각의 돌을 시작점으로 하여 오목을 만들 수 있는지 판단
 * 3. 최대 4개의 돌이 연속하거나, 5개의 돌이 연속했지만 탐색한 반대 방향에도 같은 색의 돌이 있으면 오목 실패
 * 4. 오목에 성공했으면 시작점으로 한 돌의 좌표 반환
 *           실패했으면 {0, 0} 반환
*/

typedef pair<int, int> pi;

int dx[4] = {0, 1, 1, -1}; // 세로, 가로, 대각선 탐색
int dy[4] = {1, 0, 1, 1};

bool isValid(vector<vector<int>> &baduk, pi s){
    int cnt, x, y, nx, ny;
    
    // 시작점 좌표 설정
    x = s.first;
    y = s.second;
    
    // 4가지 방향으로 탐색
    for (int i=0; i<4; i++){
        nx = x;
        ny = y;
        for (cnt = 0; cnt<5; cnt++){ // 5개의 연속된 돌 확인
            nx += dx[i]; // 이웃한 다음 돌의 위치 선정
            ny += dy[i];
            
            // 현재 탐색하는 돌이 같은 색 돌이면 -> 반복문 반복
            if (0<nx && nx<=19 && 0<ny && ny<=19 && baduk[nx][ny] == baduk[x][y])
                continue;
            break; 
        }
        if (cnt == 4){ // 탐색한 방향으로 다섯 알이 연속인 경우
            // 처음 시작 위치의 역방향 좌표
            nx = x - dx[i];
            ny = y - dy[i];
            // 역방향에 돌을 놓을 수 없을 때 -> 오목 O
            if (!(1<=nx && nx<=19 && 1<=ny && ny<=19)){
                return true;
            }
            // 역방향에 같은 색 돌이 없을 때 -> 오목 O
            else if (baduk[nx][ny] != baduk[x][y]){
                return true;
            }
        }
    }
    return false;
}

// 5개의 돌 중 가장 왼쪽에 있는 바둑알 위치 반환
// 해당 색의 돌이 게임을 이기면 가장 왼쪽 위에 있는 바둑알의 위치를, {0, 0} 리턴
pi solution(vector<vector<int>> &baduk, vector<pi> &stones){
    for (auto s: stones){
        if (isValid(baduk, s)){ // s를 시작점으로 오목이 가능하다면
            return s;
        }
    }
    return {0,0};  //{0, 0} 반환
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    vector<vector<int>> baduk(20, vector<int> (20,0));
    vector<pi> black, white;
    
    // 입력
    for (int i=1; i<=19; i++)
        for (int j=1; j<=19; j++){
            cin >> baduk[i][j];
            if (baduk[i][j] == 1)
                black.push_back({i,j});
            else if (baduk[i][j] == 2)
                white.push_back({i,j});
        }
        
    pi black_win = solution(baduk, black); // 검은 바둑돌이 이긴 경우 처음 위치
    pi white_win = solution(baduk, white); // 흰 바둑돌이 이긴 경우 처음 위치
    
    // 누가 이긴지 판단
    if (black_win.first)
        cout << "1\n" << black_win.first << " " << black_win.second;
    else if (white_win.first)
        cout << "2\n" << white_win.first << " " << white_win.second;
    else
        cout << 0;
    
    return 0;
}
