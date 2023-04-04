#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> coordinate;

int DFS(vector<coordinate> lands, vector<vector<int>> map){
    int count = 0;          // 섬의 개수 count
    stack<coordinate> s;    // 깊이 우선 탐색을 위한 스택
    // 8방향을 나타내는 방향 좌표들
    coordinate dir[8] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0,1}, {1,1}};

    // 땅에 해당하는 좌표 개수만큼 for문 돌기
    for(int i=0; i<lands.size(); i++){
        // 땅이 이미 방문된 상태라면 패스
        if(map[lands[i].first][lands[i].second] != 1){
            continue;
        }
        // 탐색을 위해 스택에 현재 땅 좌표를 push
        // 탐색했다는 의미로 ++해준다.
        s.push(lands[i]);
        map[lands[i].first][lands[i].second]++;

        while(!s.empty()){
            bool child = false;
            coordinate node = s.top();

            // 현재 좌표의 8방향칸을 탐색하면서, 아직 방문하지 않은 땅이 있다면 스택에 Push하고, 방문했다는 의미로 ++해준다.
            for(int j=0; j<8; j++){
                int nh = node.first + dir[j].first;
                int nw = node.second + dir[j].second;
                if(nh >= 0 && nh < map.size() && nw >= 0 && nw < map[0].size() && map[nh][nw] == 1) {
                    child = true;
                    s.push({nh, nw});
                    map[nh][nw]++;
                    break;
                }
            }
            // 제일 깊은 곳까지 간것이므로 스택을 pop해준다.
            if(!child){
                s.pop();
            }
        }
        // 더이상 탐색가능한 땅이 없다면 고립된 것이므로 섬의 개수를 1개 늘려준다.
        count++;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int w, h;                   // 지도의 너비와 높이

    while(true){
        // 지도 크기 입력받기
        // 만약 0 0이 입력으로 들어오면 프로그램 종료
        cin >> w >> h;
        if(w==0 && h==0){
            break;
        }
        vector<vector<int>> map(h, vector<int> (w, NULL));;    // 지도
        vector<coordinate> lands;   // 땅의 위치들을 저장
        // 지도 그리기
        for(int i = 0; i<h ; i++){
            for(int j=0; j<w; j++){
                cin >> map[i][j];
                if(map[i][j]){
                    // 해당 좌표가 땅이라면 좌표를 land에 넣기
                    lands.push_back({i, j});
                }
            }
        }
        // 연산과 출력
        cout << DFS(lands,map);
    }
}