#include <iostream>
#include "vector"
#include "set"
#include "queue"

using namespace std;

int bfs(int n, int v, vector<vector<int>> &adj_list) {
    int count = 0;
    vector<bool> visited (n+1, false);
    queue<int> q;

    q.push(v);
    visited[v] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int i = 0; i < adj_list[node].size(); i++) {
            int next_node = adj_list[node][i];
            if(!visited[next_node]) {
                q.push(next_node);
                visited[next_node] = true;
                count++;
            }
        }
    }
    return count;
}

class comp{
public:
    bool operator()(const pair<int, int> &left, const pair<int, int> &right)const{
        if(left.second == right.second){
            return left.first < right.first;    // 오름차순 정렬
        }
        else{
            return left.second > right.second;  // 내림차순 정렬
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    int n1, n2;
    cin >> n >> m;

    set<pair<int, int>, comp> result;   // {노드, 감염시킬수 있는 컴퓨터 개수}를 담을 set
    vector<vector<int>> adj_list (n+1, vector<int>(0)); // 인접리스트

    // 인접리스트 구성
    while(m--){
        cin >> n1 >> n2;
        adj_list[n2].push_back(n1);
    }
    // 노드마다 감염시킬 수 있는 컴퓨터의 개수를 DFS함수로 구하고 result에 Insert
    for(int i=1; i<adj_list.size(); i++){
        result.insert({i,bfs(n, i, adj_list)});
    }
    // result를 순회하면서 결과 출력
    for(auto iter: result){
        if(iter.second == result.begin()->second){
            cout << iter.first << " ";
        }
        else{
            return 0;
        }
    }
}