#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int, int> pi;

void bfs(vector<vector<int>> hacking, int n){
    vector<bool> visited(n+1,false);
    int cnt = 0, max_cnt = 0;
    vector<pi> result; 
    queue<int> q;
    
    for (int i=1; i<=n; i++){
        q.push(i);
        cnt = 0;
    
        while (!q.empty()){
            int node = q.front();
            q.pop();
            visited[node] = true;
            
            for (int i = 0; i<hacking[node].size(); i++){
                if (!visited[hacking[node][i]]){
                    q.push(hacking[node][i]);
                    visited[hacking[node][i]] = true;
                    cnt++;
                }
            }
            max_cnt = max(max_cnt, cnt); // 최고 해킹 가능 컴퓨터 수 갱신
        }
        if (max_cnt == cnt){
            result.push_back({i, cnt});
        }
    }
    sort(result.begin(), result.end()); // 오름차순 정렬
    for (int i=0; i<result.size(); i++)
    if (result[i].second == max_cnt)
            cout << result[i].first << " ";
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> hacking(n+1);
    for (int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        hacking[b].push_back(a); // 컴퓨터 당 해킹가능한 컴퓨터 저장
    }
    
    bfs(hacking, n);
    
    return 0;
}
