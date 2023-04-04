// 섬의 개수
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int, int> pi;

// 섬 개수 세기
int count_island(deque<pi> island){
    stack<int> s;
    vector<bool> visited(island.size(), false); // 방문여부
    int cnt = 0; // 섬 개수
    
    while (!all_of(visited.begin(), visited.end(), [](bool i){return i == true;})){
        auto it = find_if(visited.begin(), visited.end(), [](bool i){return i == false;});
        int num = distance(visited.begin(), it);
        s.push(num);
        visited[num] = true;
        while (!s.empty()){
            int node = s.top();
            bool child = false;
            
            for (int i=0; i<island.size(); i++){
                if (!visited[i] && max(abs(island[node].first - island[i].first), abs(island[node].second - island[i].second)) == 1){
                    child = true;
                    s.push(i);
                    visited[i] = true;
                    break;
                }
            }
            if (!child)
                s.pop();
        }
        cnt++;
    }
    return cnt;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int w, h;
    vector<vector<int>> sq;
    while (1){
        // 입력
        cin >> w >> h;
        if (w == 0 & h == 0)
            break;
        sq.assign(h, vector<int>(w,0));
        deque<pi> island;
        
        for (int i=0; i<h; i++)
            for (int j=0; j<w; j++){
                cin >> sq[i][j];
                
                if (sq[i][j] == 1)
                    island.push_back({i,j});
            }   
        cout << count_island(island) << '\n';
    }
    return 0;
}
