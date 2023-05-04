#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;


void bfs (int h, int w, queue<pi> &q, vector<vector<int>> &island, vector<vector<bool>> &visited){

    int dx[8] = {-1,-1,-1,0,1,1,1,0}; // 방향을 어떻게 설정해야할지 몰라 백준의 질문게시판 참고하였습니다.
    int dy[8] = {-1,0,1,1,1,0,-1,-1};

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i=0; i<8; i++){
            int nr = row + dx[i];
            int nc = col + dy[i];

            if(nr >= 0 && nr<h && nc>=0 && nc<w && (island[nr][nc]==1) && !visited[nr][nc]){
                q.push(make_pair(nr,nc));
                visited[nr][nc] = true;
            }
        }
    }

    return;
    
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int w, h;
    int count = 0;

    queue<pi> q;

    vector<vector<int>> island;

    vector<vector<bool>> visited;

    while(true){
        count = 0;
        cin >> w >> h;

        if (w == 0 && h ==0){
            break;
        }

        island.assign(h, vector<int> (w,0));
        visited.assign(h, vector<bool> (w, false));

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> island[i][j];
            }
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(island[i][j]==1 && !visited[i][j]){
                    q.push(make_pair(i,j));
                    visited[i][j] = true;
                    bfs(h, w, q, island, visited);
                    count ++;
                }
            }
        }

        cout << count << '\n';

    }
    return 0;
}