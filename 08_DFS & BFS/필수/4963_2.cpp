// 섬의 개수
#include <iostream>
#include <vector>

using namespace std;

int w, h;
int dr[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dc[8] = {1, -1, 0, 0, 1, -1, 1, -1};

vector<vector<bool>> visited;

void dfs(int i, int j, vector<vector<int>> &arr){

    visited[i][j] = true;
    
    for (int k=0; k<8; k++){
        int next_i = i + dr[k];
        int next_j = j + dc[k];
        
        if (next_i>=0 && next_i<h && next_j>=0 && next_j<w && arr[next_i][next_j] && !visited[next_i][next_j]){
            dfs(next_i, next_j, arr);
        }
    }
    return;
}

int main(){
    
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    vector<vector<int>> arr;
    
    while (1){
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        arr.assign(h, vector<int>(w,0));
        int cnt = 0;
        visited.assign(h, vector<bool>(w, false));
        
        for (int i=0; i<h; i++)
            for (int j=0; j<w; j++){
                cin >> arr[i][j];
            }
        
        for (int i=0; i<h; i++)
            for (int j=0; j<w; j++){
                if (arr[i][j] == 1 && !visited[i][j]){
                    dfs(i, j, arr);
                    cnt++;
                }
            }
        cout << cnt << "\n";
    }

    return 0;
}