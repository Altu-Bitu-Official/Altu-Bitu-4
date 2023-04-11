#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int getIslandNum(int w, int h, vector<vector<int> > &graph) {
    int cnt=0;

    //해당 좌표 방문 여부 저장
    vector<vector<int> > visited;
    visited.assign(h, vector<int> (w, false));

    queue<pair<int, int> > q;

    //상하좌우대각선 이동 방향 경우
    int dr[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
    int dc[8] = {0, 0, -1, 1, 1, -1, 1, -1};

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            //지도 돌면서 아직 방문 안 한 땅 있으면 큐에 추가하고 인접한 땅 BFS 탐색
            if(graph[i][j]==1 && !visited[i][j]) {
                q.push(make_pair(i, j));

                while (!q.empty()) {
                    int r = q.front().first;
                    int c = q.front().second;

                    for(int k=0; k<8; k++) {
                        int nr = r+dr[k];
                        int nc = c+dc[k];

                        //이동했을때 범위 안이면서 방문하지 않은 땅이면 큐에 추가
                        if(nr>=0 && nr<h && nc>=0 && nc<w && graph[nr][nc]==1 && !visited[nr][nc]) {
                            q.push(make_pair(nr, nc));
                            visited[nr][nc] = true;
                        }
                    }
                    q.pop();
                }
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int w, h;

    while(true) {
        cin >> w >> h;

        if(w==0 && h==0) {
            break;
        }

        queue<pair<int, int> > q;

        vector<vector<int> > graph;
        graph.assign(h, vector<int> (w));

        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                cin >> graph[i][j];
            }
        }

        cout << getIslandNum(w, h, graph) << "\n";
    }

    return 0;
}