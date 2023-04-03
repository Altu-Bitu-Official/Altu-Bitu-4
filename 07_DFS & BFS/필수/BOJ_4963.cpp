#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> pi;

int cnt;    //섬의 개수
vector<vector<bool>> visited; //탐색한 좌표인지 확인


void dfs(vector<vector<int>> map, int i, int j, int h, int w) {
    int dx[8] = {1, 0, -1, 1, -1, 1, 0, -1}, dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    stack<pi> s;
    if (visited[i][j]) {    //이미 방문한 좌표일 경우 리턴
        return;
    }
    visited[i][j] = true;
    s.push({i, j});

    while (!s.empty()) {
        pi node = s.top();  //스택의 탑을 기준으로 탐색
        bool child = false;
        for (int a = 0; a < 8; a++) {
            int nx = node.first + dx[a], ny = node.second + dy[a];  

            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny]) {
                visited[nx][ny] = true;
                if (map[nx][ny]) {  //하위 노드 중 섬이 있을 경우
                    s.push({nx, ny});   //스택에 넣음
                    child = true;   //자식 노드 중 섬이 있었음으로 true.
                    break;
                }
            }
        }
        if (!child) {   //자식 노드 중 섬이 없었을 경우
            s.pop();    //팝해서 그 노드 탐색 종료. 다음 노드로 이동.
        }
    }
    cnt++;  //한 번 탐색이 끝났을 경우 카운트 1 증가 -> 섬의 개수.
}

int main() {
    int w, h;
    vector<vector<int>> map;

    while(1) {
        cin >> w >> h;
        if (w == 0) {
            break;
        }
        map.assign(h, vector<int> (w, 0));
        visited.assign(h, vector<bool> (w, false));
        cnt = 0;

        //입력
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j]) {    //만약 섬일 경우에 dfs 호출.
                    dfs(map, i, j, h, w);
                }
            }
        }
        cout << cnt << '\n';
    }

}