#include <iostream>
#include <vector>

using namespace std;

const int VISITED = 2; // 방문한 땅은 2로 표시
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1}; // dr과 dc로 상,하,좌,우,대각선을 표현

void dfs(int sr, int sc, int h, int w, vector<vector<int>> &map)
{                          // dfs 탐색하는 함수
    map[sr][sc] = VISITED; // 방문시 2로 체크

    for (int i = 0; i < 8; i++)
    {                        // 이어진 땅 없는지 탐색
        int nr = sr + dr[i]; // 인자로 받은 위치에서
        int nc = sc + dc[i]; // 상하좌우대각선을 for문을 통해 (nc,nr)로 저장하여 체크

        if (nr >= 0 && nr < h && nc >= 0 && nc < w && map[nr][nc] == 1)
        {                           // 범위에 존재하는 땅 발견
            dfs(nr, nc, h, w, map); // 재귀함수이용하여 방문체크해준다
        }
    }
}

int cntIsland(int h, int w, vector<vector<int>> &map)
{                               // 섬의 개수를 세는 함수
    int cnt = 0;                // count하는 변수 선언
    for (int i = 0; i < h; i++) // 이중for문으로 땅 체크
    {
        for (int j = 0; j < w; j++)
        {
            if (map[i][j] == 1)
            { // 땅 발견
                cnt++;
                dfs(i, j, h, w, map); // (i,j)와 연결된 땅 탐색 (== 섬 만들기)
            }
        }
    }
    return cnt;
}

int main()
{
    int w, h;                // 가로 w 세로 h
    vector<vector<int>> map; // 2차원 vector map선언

    while (true)
    {
        // 입력
        cin >> w >> h;
        if (w == 0 && h == 0)
        { // 종료조건
            break;
        }
        map.assign(h, vector<int>(w, 0)); // 높이가 h 가로가 w인 map을 0으로 할당
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j]; // 지도 사용자 정의
            }
        }

        cout << cntIsland(h, w, map) << '\n'; // 연산 , 출력
    }
    return 0;
}