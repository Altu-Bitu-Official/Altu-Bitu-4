#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> coordinate;

int DFS(vector<coordinate> &lands, vector<vector<int>> map){
    int count = 0;
    stack<coordinate> s;
    coordinate dir[8] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0,1}, {1,1}};

    for(int i=0; i<lands.size(); i++){
        if(map[lands[i].first][lands[i].second] != 1){
            continue;
        }
        s.push(lands[i]);
        map[lands[i].first][lands[i].second]++;

        while(!s.empty()){
            bool child = false;
            coordinate node = s.top();

            for(int j=0; j<8; j++){
                int nh = node.first + dir[j].first;
                int nw = node.second + dir[j].second;
                if(nh >= 0 && nh < map.size() && nw >= 0 && nw < map[1].size() && map[nh][nw] == 1) {
                    child = true;
                    s.push({nh, nw});
                    map[nh][nw]++;
                    break;
                }
            }
            if(!child){
                s.pop();
            }
        }
        count++;
    }
    return count;
}

int main() {
    int w, h; //지도의 너비와 높이
    cin >> w >> h;

    vector<vector<int>> map;
    vector<coordinate> lands;
    map.assign(h, vector<int> (w, NULL));

    for(int i = 0; i<h ; i++){
        for(int j=0; j<w; j++){
            cin >> map[i][j];
            if(map[i][j]){
                lands.push_back({i, j});
            }
        }
    }

    cout << DFS(lands,map);
}
