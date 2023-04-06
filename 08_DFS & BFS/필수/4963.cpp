#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

const int VISITED = 2;

//방향 설정해주기 여기서는 3x3 기준으로 8개로 나누어 주었다. 대상이 되는 땅은 가운데에 있다고 생각을 하고
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void bfs(int sr, int sc, int h, int w, vector<vector<int>> &map) { // bfs 를 사용하여 탐색해 주기
    queue<pi> q;

    q.push({sr, sc}); // 일단 땅을 발견했으므로 que에 넣어주기
    map[sr][sc] = VISITED; // 방문했다고 1에서 2로 바꿔주기

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop(); //que 처음 값을 r,c로 지정해 주었으므로 더 이상 필요 없으니 pop 해주기

        for(int i = 0; i < 8; i++) { // 이어진 땅 없는지 탐색
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < h && nc >= 0 && nc < w && map[nr][nc] == 1) { // 땅 발견
                q.push({nr, nc}); //땅을 발견했으므로 que에 넣어주기
                map[nr][nc] = VISITED; // 방문했다고 체크해주기 -> 2로 바꿔줌
            }
        }
    }
}

int cntIsland(int h, int w, vector<vector<int>> &map) { // 섬 개수 세기
    int cnt = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(map[i][j] == 1) { // 땅 발견
                cnt++;
                bfs(i, j, h, w, map); // (i,j)와 연결된 땅 탐색 (== 섬 만들기)
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
    vector<vector<int>> map; //지나갔는지 아닌지를 확인 체크해주는 vector 생성

    while(true) {
        // 입력
        cin >> w >> h;
        if(w == 0 && h == 0) { // 종료조건
            break;
        }

        map.assign(h, vector<int> (w, 0));
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> map[i][j]; // 입력받아주기
            }
        }

        // 연산과 출력
        cout << cntIsland(h, w, map) << endl;
    }
    return 0;
}