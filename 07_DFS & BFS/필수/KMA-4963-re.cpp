#include <iostream>
#include <vector>

using namespace std;

const int VISITED = 2;  //1이 아닌 수 아무거나
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};    //8개의 방향
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int sr, int sc, int h, int w, vector<vector<int>> &map) { // dfs 탐색
    map[sr][sc] = VISITED; // 방문 check

    for(int i = 0; i < 8; i++) { // 이어진 땅 없는지 8개의 방향을 탐색
        //탐색할 방향 설정
        int nr = sr + dr[i];    
        int nc = sc + dc[i];

        if(nr >= 0 && nr < h && nc >= 0 && nc < w && map[nr][nc] == 1) { // 안가본 땅 발견
            dfs(nr, nc, h, w, map); 
        }
    }
}

int cntIsland(int h, int w, vector<vector<int>> &map) { // 섬 개수 세기
    int cnt = 0;    //섬개수 cnt
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(map[i][j] == 1) { // 안가본 땅 발견 (0이나 2가 아니니까)
                cnt++;  //섬 개수 +1
                dfs(i, j, h, w, map); // (i,j)와 연결된 땅 탐색 (== 섬 만들기)
            }
        }
    }
    return cnt;
}

/*
 * [섬의 개수 세기]
 * 1. 땅을 발견할 때마다 그래프 탐색을 이용하여 연결된 땅을 찾아 섬을 만든다.
 * 2. 따라서 그래프 탐색 횟수가 섬의 개수가 된다.
*/

int main() {
    int w, h;
    vector<vector<int>> map;

    while(true) {
        // 입력
        cin >> w >> h;
        if(w == 0 && h == 0) { // 종료조건
            break;
        }
        map.assign(h, vector<int> (w, 0));  //h개의 행과 w개의 열을 가지는 map을 초기화하고 입력받는다
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        // 연산 & 출력
        cout << cntIsland(h, w, map) << '\n';
    }
    return 0;
}