// 섬의 개수
// 테스트 케이스 o, 제출하면 시간초과
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef pair<int, int> p;

int bfs(map<p, bool> &m, vector<vector<int>> &vc){
    int cnt = 0;
    queue<p> q;
    int dr[8] = {-1,-1,-1,1,1,1,0,0};
    int dc[8] = {-1,0,1,-1,0,1,-1,1};

    for (auto i:m){
        if (!i.second){
            i.second = true;
            q.push(i.first);

            while(!q.empty()){
                int r = q.front().first;
                int c = q.front().second;
                m[{r,c}] = true;
                q.pop();

                for(int j=0; j<8; j++){
                    int nr = r + dr[j];
                    int nc = c + dc[j];

                    if (vc[nr][nc]==1 && !m[{nr,nc}]){
                        q.push({nr,nc});
                    }
                }
            }
            cnt++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int w, h;    // 행 개수 h, 열 개수 w
    while (true){ 
        vector<vector<int>> v;
        map<p, bool> ones;

        //입력
        cin >> w >> h;  
        //"0 0"입력받으면 종료
        if (!w && !h)   {break;}
        
        v.assign(h+2, vector<int>(w+2,0));
        for (int i=1; i<h+1; i++){    
            for (int j=1; j<w+1; j++){    
               cin >> v[i][j];
               if(v[i][j]==1)  { ones.insert({ {i,j}, false }); }
            }
        }

        // 연산 & 출력
        if (w==1 && h==1){
            cout << v[1][1] << "\n";
        }
        else{
            cout << bfs(ones, v) << "\n";
        }
    }

    return 0;
}