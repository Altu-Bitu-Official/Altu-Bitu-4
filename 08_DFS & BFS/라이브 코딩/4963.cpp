#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
[섬의 개수 ]
1. 땅을 발견할 때마다 그래프 탐색을 이용하여 연결된 땅을 찾아 섬을 만든다
2. 그래프 탐색 횟수 = 섬의 개수
*/
typedef pair<int, int> pi;
const int VISITED = 2; // 방문한 땅은 2로 표시함
//상,하,좌,우,대각선 dr과 dc로 표현함
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};


//dfs 탐색 함수
void dfs(int sr, int sc, int h, int w, vector<vector<int>> &map)
{                          
    map[sr][sc] = VISITED; // 방문시 2로 체크함

    for (int i = 0; i < 8; i++)
    {
        // 이어진 땅 있는지 여부를 탐색
        int nr = sr + dr[i]; 
        int nc = sc + dc[i]; // 상하좌우대각선을 (nc,nr)로 저장하여 체크함

        if (nr >= 0 && nr < h && nc >= 0 && nc < w && map[nr][nc] == 1)
        {
            // 범위에 존재하는 땅 발견한 경우
            dfs(nr, nc, h, w, map); // 재귀함수를 이용하여 방문 체크함
        }
    }
}

// 섬의 개수를 세는 int 함수
int cntIsland(int h, int w, vector<vector<int>> &map)
{
    int cnt = 0; //섬의 개수를 세는 변수 cnt
    for (int i = 0; i < h; i++) 
    {
        // 이중 for문으로 체크
        for (int j = 0; j < w; j++)
        {
            if (map[i][j] == 1)
            { // 땅을 발견한 경우
                cnt++;
                dfs(i, j, h, w, map); // (i,j)와 연결된 땅 탐색해 섬을 만듦
            }
        }
    }
    return cnt;
}

int main()
{
    //입력
    int w, h; // 가로 w 세로 h
    vector<vector<int>> map; // 2차원 vector map 선언

    while (true)
    {
        // 입력
        cin >> w >> h;
        if (w == 0 && h == 0) // 종료할 조건
        { 
            break;
        }
        map.assign(h, vector<int>(w, 0)); // 높이가 h, 가로가 w인 map 초기화함
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j]; // 지도 사용자 정의
            }
        }
        // 연산, 출력
        cout << cntIsland(h, w, map) << '\n'; 
    }
    return 0;
}