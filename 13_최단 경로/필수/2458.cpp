#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9;

//플로이드-워셜을 통해 각 점에서 다른 점으로 갈 수 있는지 확인 
void floydWarshall(int n, vector<vector<int>> &graph) {
    for (int k = 1; k <= n; k++) { //중간 정점
        for (int i = 1; i <= n; i++) { //출발 정점
            for (int j = 1; j <= n; j++) { //도착 정점
                //중간에 k를 거쳐서 i에서 j로 갈 때
                int temp = graph[i][k] + graph[k][j];
                graph[i][j] = min(graph[i][j], temp);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    //입력
    int N, M, a, b;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF)); 
    for (int i = 1; i <= N; i++) { //자기 자신과의 거리
        graph[i][i] = 0; 
    }
    while(M--){
        cin >> a >> b; //a가 작은쪽, b가 큰쪽 
        graph[a][b] = 1; //간선이 존재함 
    }
    
    //연산
    floydWarshall(N, graph);
    
    //출력 
    int ans = 0; 
    for(int i=1; i<=N; i++){
        bool flag = true; 
        for(int j=1; j<=N; j++){
            if(i == j) continue;
            else if(graph[i][j] == INF && graph[j][i] == INF){
                flag = false; //i와 j 사이의 가중치가 없는 경우 
                break;
            }
        }
        if(flag) {
            ans++;
        }
        
    }
    cout << ans; 

    return 0;
}