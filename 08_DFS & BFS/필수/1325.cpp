#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int bfs(int n, int m, vector<vector<int>> &v){
    int cnt = 0;
    vector<bool> trusted (n+1, false);
    queue<int> q;
    
    q.push(m);
    trusted[m] = true;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0; i<v[node].size(); i++){
            int next_node = v[node][i];
            if(!trusted[next_node]){
                q.push(next_node);
                trusted[next_node] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    //입력
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, n1, n2;
    cin >> n >> m;

    //인접 리스트 이용
    vector<vector<int>> v;
    v.assign(n+1, vector<int>(0));
    
    while(m--){
        cin >> n1 >> n2;
        v[n2].push_back(n1); //단방향 
    }
    

    int max = 0;
    vector<int> maxIdx(0);

    for (int i = 1; i<=n ; i++) {
        if(v[i].size() == 0) { // 연결된 컴퓨터가 없는 경우
            continue;
        }
        
        int tmp = bfs(n, i, v);

        if(tmp > max) { 
            maxIdx.clear();
            maxIdx.push_back(i);
            max = tmp;
        }
        else if(max == tmp) { // 이전 max값과 같을 때
            maxIdx.push_back(i); // maxIdx에 저장
        }
    }

    sort(maxIdx.begin(), maxIdx.end()); // 오름차순으로 정렬

    //출력
    for(int i = 0; i < maxIdx.size(); i++) {

        cout << maxIdx[i] << " "; 
    }
    
    return 0;
}