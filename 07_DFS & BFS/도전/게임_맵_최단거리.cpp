#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

const int NOT_VISITED = -1;

int bfs(vector<vector<int>> &maps) { // 상대 팀 진영에 도착하기 이해 지나가야 하는 칸의 수 반환
    int n = maps.size(), m = maps[0].size();
    vector<vector<int>> w(n, vector<int> (m, NOT_VISITED)); // 해당 칸까지 가기 위해 지나가야 하는 칸 수
    queue<pi> q;

    // 시작점 push
    q.push({0, 0});
    w[0][0] = 1;

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        if(r == n-1 && c == m-1) { // 상대팀 진영에 도착한 경우
            return w[n-1][m-1];
        }
        int weight = w[r][c]; // (r,c)까지 이동하는데 지나간 칸의 수
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // 다음 칸으로 이동할 수 있는 경우 (== 벽이 아니고 방문한 적이 없는 칸인 경우)
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && maps[nr][nc] && w[nr][nc] == NOT_VISITED) {
                q.push({nr, nc});
                w[nr][nc] = weight+1;
            }
        }
    }
    return w[n-1][m-1];
}

int solution(vector<vector<int> > maps)
{
    return bfs(maps);
}

/*
 * 상대 팀 진영에 도착하기 위해 지나가야 하는 칸의 개수 구하기
 * == 최단 거리 구하기
 * -> bfs를 이용한다!
*/

int main() {
    vector<vector<int>> maps = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}};

    // 연산 & 출력
    cout << solution(maps);
    return 0;
}