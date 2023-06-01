#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 501; // 최대 n-1개의 간선을 지나므로 n * (가중치 최대값)

void init(int n, vector<vector<int>>& graph) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF; // 그래프 초기화. 두 노드 사이 값(가중치)
        }
    }
    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0; // 자기 자신으로의 거리는 0
    }
}

void floydWarshall(int n, vector<vector<int>>& graph) {
    for (int k = 1; k <= n; k++) { // 중간 정점
        for (int i = 1; i <= n; i++) { // 출발 정점
            for (int j = 1; j <= n; j++) { // 도착 정점
                // 중간에 k를 거쳐서 i에서 j로 갈 때의 비용
                int cost = graph[i][k] + graph[k][j];
                // 더 짧은 경로 선택
                graph[i][j] = min(graph[i][j], cost);
            }
        }
    }
}

int countStudents(int student, int n, vector<vector<int>>& graph) {
    int cnt = 0;//? 
    for (int i = 1; i <= n; i++) {
        if (student != i && graph[student][i] == INF && graph[i][student] == INF) { // 상대방과의 키 우열을 모르는 경우
            return 0;//몰라요. (우열 모른단 뜻)
        }
    }
    return 1;//위에서 안 걸리면 1 리턴
}
/*
 * 키순서
 * 내 키의 순위를 안다 <-> 내가 상대방과의 키 우열을 안다 or 상대방이 나와의 키 우열을 안다
*/
int main()
{
    int n, m;//학생수, 비교횟수
    int answer = 0;//답
    vector<vector<int>> graph(INF, vector<int>(INF));//그래프선언
    // 입력
    cin >> n >> m;//입력받기
    init(n, graph); // 초기화
    while (m--) {//비교횟수만큼
        int a, b; cin >> a >> b;//a가 b보다 키 작다. 
        graph[a][b] = 1; // 키 우열을 아는 두 정점의 거리를 1이라고 하자
    }
    // 연산
    floydWarshall(n, graph);//연산
    for (int i = 1; i <= n; i++) { // 자신의 키가 몇 번째인지 알 수 있는 학생들이 몇 명인지 계산
        answer += countStudents(i, n, graph);//
    }
    // 출력
    cout << answer << '\n';
    return 0;
}
