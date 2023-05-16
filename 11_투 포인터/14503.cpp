#include <iostream>
#include <vector>
 
using namespace std;

vector<vector<int>> clean;
vector<vector<int>> visited;
int n, m;
int result;
int count = 0;

void dfs(int x, int y, int d, int sum){
    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,1,0,-1};

    for (int i = 0; i < 4; i++) {
		// 선택할 칸 
        // 왼쪽, 아래, 오른쪽, 위 중 하나가 선택됨
        int nd = (d+3-i)%4; 
		int x1 = x + dx[nd]; 
		int y1 = y + dy[nd];

		if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m || clean[x1][y1]) { // 범위를 벗어났거나 이미 방문한 구간이라면 넘어가기
			continue;
		}

        if(!visited[x1][y1] && !clean[x1][y1]){
		    visited[x1][y1] = 1;
            dfs(x1, y1, nd, sum + 1);
        }

	}

    int x2 = x + dx[(d+2)%4];
    int y2 = y + dy[(d+2)%4];
        
    if( x2>=0 && x2<=n && y2>=0 && y2<=m ){
        if(!clean[x2][y2]){   
            dfs(x2, y2, d, sum); 
        }
        else{  
            if(count==0){
                result = sum;
                count++;
            }
        }
    }
 
}

int main(){ 
    cin >> n >> m;

    int x, y, d;
    cin >> x >> y >> d;

    clean.assign(n, vector<int>(m, 0));
    visited.assign(n, vector<int>(m, 0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> clean[i][j];
        }
    }
    
    visited[x][y] = 1;
    dfs(x,y,d,1);

    cout << result;
 
    return 0;
}