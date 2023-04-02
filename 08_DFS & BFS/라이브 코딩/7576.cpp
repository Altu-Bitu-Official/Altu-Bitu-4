// 토마토
// 시간초과
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int watering(vector<vector <int>> &box, int n, int m){
    int cnt = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false)); // 오늘 익은 토마토 여부
    
    for (int i=0; i<n; i++)
            for (int j=0; j<m; j++){
                if (!visited[i][j] && box[i][j] == 1){
                    if (i!=0 && box[i-1][j] == 0){
                        box[i-1][j] = 1; cnt++;
                        visited[i-1][j] = true;
                    }
                    if (i<n-1 && box[i+1][j] == 0){
                        box[i+1][j] = 1; cnt++;
                        visited[i+1][j] = true;
                    }
                    if (j!=0 && box[i][j-1] == 0){
                        box[i][j-1] = 1; cnt++;
                        visited[i][j-1] = true;
                    }
                    if (j<m-1 && box[i][j+1] == 0){
                        box[i][j+1] = 1; cnt++;
                        visited[i][j+1] = true;
                    }
                }
            }
    return cnt;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int m, n, cnt = 0;
    cin >> m >> n;
    vector<vector <int>> box(n, vector<int>(m));
    
    // 입력
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++){
            cin >> box[i][j];
            if (box[i][j] == 0){ 
                cnt++; // 익혀야 하는 토마토 수
            }
        }
        
    
    // 토마토 익히기
    int day = 0; // 토마토 익히는데 걸리는 시간

    while (1){
        if (cnt == 0){
            cout << day;
            break;
        }
        int tomato = watering(box,n,m); // 새롭게 익은 토마토 수
        cnt -= tomato; // 남은 익혀야 하는 토마토 수
        day++;
        
        if (tomato == 0){ // 새로 익은 토마토가 없다면
            cout << -1; // 토마토가 모두 익지 못함
            break;
        }
    }
    return 0;
}