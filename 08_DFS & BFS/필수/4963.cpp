#include <iostream>
#include <vector>

#define MAX_SIZE 50
 
using namespace std;

typedef pair<int,int> pi;

int n,m;
vector<vector<int>> island;
vector<vector<bool>> visited;
int dy[] = {0,0,-1,1,-1,-1,1,1};
int dx[] = {1,-1,0,0,-1,1,-1,1};

void dfs(int y, int x) {
    visited[y][x] = true;
 
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
 
        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if (island[ny][nx] == 1 && visited[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
}

int main(){
    while(true){

        cin>>n>>m;
        island.assign(m,vector<int>(n,0)); // 초기화해주기
        visited.assign(m,vector<bool>(n,false)); // 초기화해주기
        if (n ==0 && m==0){
            break; //-> 0,0이 들어올 경우 계산을 끝낸다.
        }

        for(int i=0; i<m;i++){
            for(int j =0; j<n; j++){
                cin>>island[i][j];
            }
        }

        int count =0;
        for(int i=0; i<m; i++){
            for(int j=0;j<n;j++){
                if(island[i][j]==1 && visited[i][j] == false){
                    dfs(i,j);
                    count++;
                }
            }
        }
        cout<<count<<endl;

    }
}