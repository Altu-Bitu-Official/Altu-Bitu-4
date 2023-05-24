// 트리의 지름
#include <iostream>
#include <vector>
using namespace std;
int max_len = 0; // 트리의 최대 반지름 길이
void dfs(int node, int n, vector<int> &vertex, vector<vector<int>> &edge){
    for (int i = 0; i < edge[node].size(); i++){ // 깊이 우선 탐색
        dfs(edge[node][i], n, vertex, edge);
    }
    if (edge[node].size() >= 2){ // 자식 노드가 2개라면
        int temp_max = 0;
        for (int i = 0; i < edge[node].size(); i++){
            temp_max = max(temp_max, vertex[edge[node][i]]); // 자식노드중 가장 큰 가중치 찾기
            if (i == edge[node].size()-1){
                break;
            }
            for (int j = i+1; j < edge[node].size(); j++){
                max_len = max(max_len, vertex[edge[node][i]] + vertex[edge[node][j]]); // 자식노드 중 2개의 합이 가장 큰 경우(트리의 최대 길이) 저장 
            }
        }
        vertex[node] += temp_max; // node의 자식 노드에서 가장 큰 가중치
    }
    else if (edge[node].size() == 1){ // 자식 노드가 1개라면
        vertex[node] += vertex[edge[node][0]];
        max_len = max(max_len, vertex[edge[node][0]]); // max_len 업데이트
    }
}

int main()
{
    int n, x, y, l;
    cin >> n;
    vector<vector<int>> edge(n+1);
    vector<int> vertex(n+1,0); // 정점 별 최대 트리 반지름 길이
    for (int i = 0; i < n-1; i++){
        cin >> x >> y >> l;
        edge[x].push_back(y); // x의 자식노드에 y저장
        vertex[y] = l; // 정점y는 부모 노드로부터 연결되는데 길이l
    }
    dfs(1, n, vertex, edge);
    
    cout << max_len;
    return 0;
}