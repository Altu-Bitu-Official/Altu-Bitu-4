// 효율적인 해킹
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int, int> pi;

void bfs(vector<vector<int>> hacking, int n){
    
    
    int cnt = 0, max_cnt = 0;
    vector<pi> result; // 해킹가능한 (탐색한) 컴퓨터 저장
    queue<int> q;
    
    for (int i=1; i<=n; i++){ // 1번~n번 컴퓨터 각각 최대 해킹 컴퓨터 수 탐색
        q.push(i); // i번 컴퓨터 탐색
        cnt = 0; // 해킹 가능 컴퓨터 수
        vector<bool> visited(n+1, false); // 각 컴퓨터 방문여부 저장
        
        while (!q.empty()){
            int node = q.front(); // 큐의 첫번째 노드 방문
            q.pop();
            visited[node] = true;
            
            for (int i=0; i<hacking[node].size(); i++){
                if (!visited[hacking[node][i]]){ // 컴퓨터가 해킹가능한 컴퓨터들 탬색
                    q.push(hacking[node][i]);
                    visited[hacking[node][i]] = true;
                    cnt++;
                }
            }
            max_cnt = max(max_cnt, cnt); // 최고 해킹 가능 컴퓨터 수 갱신
        }  
        if (max_cnt == cnt){
            result.push_back({i, cnt}); // max_cnt를 갱신한 컴퓨터를 해킹가능한 횟수와 함께  저장
        }
    }
    sort(result.begin(), result.end()); // 오름차순 정렬
    
    for (int i=0; i<result.size(); i++)
        if (result[i].second == max_cnt) // result 중 최종까지 max_cnt를 유지한 컴퓨터 출력 
            cout << result[i].first << " "; 
}
    
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n, m, a, b;
    cin >> n >> m;
    
    vector<vector<int>> hacking;// 1~n번 컴퓨터에서 각각 해킹가능한 컴퓨터 저장
    hacking.assign(n+1, vector<int>(0));
    // 입력
    for (int i=0; i<m; i++){
        cin >> a >> b;
        hacking[b].push_back(a);
    }
    bfs(hacking, n);
    
    return 0;
}
