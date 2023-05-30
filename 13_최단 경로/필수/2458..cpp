// 2458
// 플로이드-워셜 알고리즘 이용

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int CONNECT = 1;

void floydWarShall(int N, vector<vector<int>> &adj){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                if(adj[j][i] && adj[i][k]) {
                    adj[j][k] = CONNECT;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M, x, y;
    cin >> N >> M;
    vector<vector<int>> adj(N+1, vector<int>(N+1, 0));
    while(M--){
        cin >> x >> y;
        adj[x][y] = CONNECT;
    }
    floydWarShall(N, adj);
    // 답 얻어내기
    int answer = 0;
    for(int i = 1; i <= N; i++){
        int connected_student = 0;
        for(int j = 1; j <= N; j++) {
            if(adj[i][j] == CONNECT || adj[j][i] == CONNECT) {
                connected_student++; // 자신을 제외한 N-1명 학생이 연결돼있나?

                if(connected_student >= N-1) { // N-1명 이상이 연결되어있음
                    answer++;
                }
            }
        }
    }
    cout << answer << "\n";
    
}