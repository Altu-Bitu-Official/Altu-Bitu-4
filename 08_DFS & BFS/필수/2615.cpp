// 오목
#include <vector>
#include <deque>
#include <iostream>

using namespace std;
typedef pair<int, int> pi;
int ini_r, ini_c;

int win(deque<pi> stones){
    int dr[4] = {1,0,1,-1}; // 이동가능
    int dc[4] = {0,1,1,1};
    
    for (int i=0; i<4; i++){ // 가로, 세로, 대각선 탐색
        deque<pi> q = stones; // stones 복사본
        int cnt = 1, neighbor = 0;
        vector<bool> visited(q.size(),false); // fix here
        int r, c;
        
        // 첫 노드 
        visited[0] = true;
        ini_r = r = q.front().first;
        ini_c = c = q.front().second;
        q.pop_front();
        
        while (!q.empty()){ 
            
            // 처음 바둑알 선정
            int nr = r + dr[i];
            int nc = c + dc[i];
            for (int j=0; j<q.size(); j++){ // fix here
                if (!visited[j] && q[j].first == nr && q[j].second == nc){
                    neighbor = 1;
                    r = nr; c = nc;
                    visited[j] = true;
                    break;
                }
            }
            if (neighbor == 0){ // 이웃한 바둑돌이 없으면
                if (cnt == 5){ // 이전까지 이웃한 바둑돌이 5개인지 확인
                    return 1;
                }
                else{
                    cnt = 1; // 개수 초기화
                    ini_r = r = q.front().first; // 시작위치 초기화
                    ini_c = c = q.front().second;
                    q.pop_front();
                }
            }
            else{ // 이웃한 바둑돌이 있으면 cnt+1
                cnt++;
            }
            neighbor = 0; // reset neighbor flag
        }
        if (cnt == 5){
            return 1;
        }
    }
    return 0;
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    vector<vector<int>> baduk(20, vector<int> (20,0));
    deque<pi> black;
    deque<pi> white;
    
    // 입력
    for (int i=1; i<=19; i++)
        for (int j=1; j<=19; j++){
            cin >> baduk[i][j];
            if (baduk[i][j] == 1)
                black.push_back({i,j});
            else if (baduk[i][j] == 2)
                white.push_back({i,j});
        }
    if (win(black)){ 
        cout << 1 << '\n';
        cout << ini_r << " " << ini_c;
    }
    else if (win(white)){
        cout << 2 << '\n';
        cout << ini_r << " " << ini_c;
    }
    else
        cout << 0;
        
    
    return 0;
}