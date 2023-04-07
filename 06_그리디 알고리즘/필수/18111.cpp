#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int evenGround(vector<vector<int>> &v, int &n, int &m, int &h) {
    int time = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int sub = v[i][j] - h; // 맞춰야 하는 높이와 현재 높이의 차이

            if(sub > 0) { // 차이가 0보다 크면 깎아야 함
                time += sub*2;
            } 
            else {        // 차이가 0보다 작으면 더해야 함
                time -= sub;
            }
        }
    }
    return time;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, b; // 세로, 가로, 인벤토리
    cin >> n >> m >> b;

    vector<vector<int>> v(n , vector<int> (m, 0)); // 이중 벡터, 0으로 초기화
    int h, sum = 0; // 땅의 높이, 높이의 합

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> h;
            v[i][j] = h;
            sum += h; // 땅 높이의 총합을 기록
        }
    }

    int small = (sum) / (n*m);   // 가능한 블록의 최소 높이
    int big = (sum+b) / (n*m); // 가능한 블록의 최대 높이
    int time = 0;

    int minTime = 987'654'321;
    int height = 0;

    for(int i = small; i <= big; i++) { // 가능한 최소 높이부터 최대 높이까지 모두 반복
        time = evenGround(v, n, m, i);

        if (time <= minTime) {
            minTime = time;
            height = i;
        }
    }
    cout << minTime << " " << height;
    return 0;
}
