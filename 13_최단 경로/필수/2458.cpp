#include <iostream>
#include <vector>

using namespace std;
const int CONNECTED = 1;

void floydWarshall(int n, vector<vector<int>> &graph) {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(graph[i][k] && graph[k][j]) { // i가 k보다 작고, k가 j보다 작다 -> i가 j보다 작다
                    graph[i][j] = CONNECTED; // 연결 표시
                }
            }
        }
    }
}

int findStudent(int n, vector<vector<int>> &graph) { // 자기 외 n-1명의 학생들에 연결되어있으면 키를 아는 것
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(!graph[i][j] && !graph[j][i]) { // 연결되어있지 않으면
                continue;
            }
            cnt++;                       // 카운트 증가
            if(cnt == n - 1) {           // n-1명의 학생들에 연결되어있으면
                ans++;                   // 키를 아는 것
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b;

    // 입력
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));

    while(m--) {
        cin >> a >> b;
        graph[a][b] = CONNECTED; // 연결 표시
    }

    // 연산
    floydWarshall(n, graph); // 플로이드 워셜
    int ans = findStudent(n, graph); // 키가 몇 번째인지 알 수 있는 학생 수

    // 출력
    cout << ans << '\n';

    return 0;
}