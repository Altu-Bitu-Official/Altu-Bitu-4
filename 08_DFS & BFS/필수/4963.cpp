#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[51][51];
typedef pair<int, int> pi;

void bfs(int w, int h, vector<vector<int>> &graph) {
    queue<pi> q;
    
    //좌 우 상 하 좌상 우상 좌하 우하
    int dr[8] = {-1, 1, 0, 0, -1, 1, -1, 1 };
    int dc[8] = {0, 0, -1, 1, -1, -1, 1, 1 };
    //시작점 방문
    visited[w][h] = true;
    q.push({w, h});
    
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for(int i=0; i<8; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            //지도를 벗어나지 않음, 섬일 것, 방문하지 않음
            if(nr >= 0 && nr < w && nc >= 0 && nc < h ) {
                if( graph[nr][nc] == 1 && !visited[nr][nc]){
                    cout << nr << " " << nc <<" \n";
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                        
                }
            }
        }
        
    }
}

int main()
{
    int w, h;   //너비, 높이
    
    //입력
    while(true)
    {
        vector<vector<int>> graph; //지도
        int count = 0;  //섬의 개수
        cin >> w >> h;
        // 0 0 입력받으면 종료
        if(w == 0 && h == 0){
            return 0;
        }
        
        graph.assign(w, vector<int> (h, 0));
        
        for(int i=0; i<w; i++){
            for(int j=0; j<h; j++){
                cin >> graph[i][j];
                visited[i][j] = false;
            }
        }
        
        //bfs
        for(int i=0; i<w; i++){
            for(int j=0; j<h; j++){
                if(graph[i][j] == 1 && !visited[i][j]){
                    bfs(i, j, graph);
                    count++;
                }
            }
        }
        
        cout << "답:" << count << "\n";
            
    }
}

//https://jdselectron.tistory.com/53
//연결되어 있지 않은 다른 섬으로 건너가는 방법을 고민하다가 참고함 main의 bfs for문


