#include <iostream>
#include "vector"
#include "set"
#include "stack"

using namespace std;

int DFS(int n, int v, vector<vector<int>> &adj_list){
    vector<bool> visited(n+1, false);
    stack<int> s;
    int count = 1;

    s.push(v);
    visited[v] = true;

    int tmp_count = 1;
    while(!s.empty()){
        int node = s.top();
        bool child = false;

        for(int i=0; i<adj_list[node].size(); i++){
            int next_node = adj_list[node][i];
            if(!visited[next_node]){
                child = true;
                s.push(next_node);
                visited[next_node] = true;
                tmp_count++;
                break;
            }
        }
        if(!child){
            s.pop();
            count = (tmp_count > count) ? tmp_count : count;
            tmp_count--;
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

    set<pair<int, int>, comp> result;
    vector<vector<int>> adj_list (n+1, vector<int>(0));

    while(m--){
        cin >> n1 >> n2;
        adj_list[n2].push_back(n1);
    }
    for(int i=1; i<adj_list.size(); i++){
        result.insert({i,DFS(n, i, adj_list)});
    }
    for(auto iter: result){
        if(iter.second == result.begin()->second){
            cout << iter.first << " ";
        }
        else{
            return 0;
        }
    }
}