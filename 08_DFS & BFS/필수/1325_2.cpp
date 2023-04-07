// 효율적인 해킹
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> hacked; // 컴퓨터 해킹 여부 저장

// node 컴퓨터가 해킹할 수 있는 컴퓨터 개수 세기 - 재귀 이용
int dfs(int node, vector<vector<int>> &graph){
    int cnt = 1; 
    hacked[node] = true;
    
    for (int i=0; i<graph[node].size(); i++){
        int next_node = graph[node][i];
        if (!hacked[next_node]){
            cnt += dfs(next_node, graph);
        }
    }
    return cnt;
}

vector<int> hack(int n, vector<vector<int>> &graph){
    int max_cnt = 0; // 감염된 컴퓨터 수의 최댓값
    vector<int> result; // 컴퓨터 번호 저장
    
    for (int i=1; i<=n; i++){ // i번째 컴퓨터가 해킹가능한 컴퓨터 수
        hacked.assign(n+1, false);
        int tmp = dfs(i,graph);
        
        if (tmp > max_cnt){ // 최댓값 갱신
            max_cnt = tmp;
            result = {i};
        }
        else if (tmp == max_cnt){
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    int n, m, a, b;
    vector<vector<int>> graph;
    
    cin >> n >> m;
    graph.assign(n+1, vector<int>(0));
    
    while(m--){
        cin >> a >> b;
        graph[b].push_back(a);
    }
    
    vector<int> result = hack(n, graph);
    for (int i=0; i<result.size(); i++){
        cout << result[i] << ' ';
    }

    return 0;
}