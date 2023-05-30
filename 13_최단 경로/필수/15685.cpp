#include <iostream>
#include <vector>

using namespace std;

const int MAX = 101;
bool visited[MAX][MAX];

int dx[] = { 1, 0, -1, 0 }; // 동, 북, 서, 남
int dy[] = { 0, -1, 0, 1 };

int main() {
    int N;
    cin >> N;

    vector<int> curve;

    // 드래곤 커브 그리기
    for (int i = 0; i < N; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        curve.clear();
        curve.push_back(d);

        // 각 세대별로 이전 세대를 시계방향으로 90도 회전한 후 추가
        for (int j = 0; j < g; j++) {
            int size = curve.size();
            for (int k = size - 1; k >= 0; k--) {
                curve.push_back((curve[k] + 1) % 4);
            }
        }

        // 드래곤 커브 방문 처리
        visited[y][x] = true;

        // 드래곤 커브 이동
        for (int dir : curve) {
            x += dx[dir];
            y += dy[dir];
            visited[y][x] = true;
        }
    }

    int count = 0;

    // 정사각형 개수 세기
    for (int i = 0; i < MAX - 1; i++) {
        for (int j = 0; j < MAX - 1; j++) {
            if (visited[i][j] && visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1]) {
                count++;
            }
        }
    }

    cout << count << "\n";

    return 0;
}
