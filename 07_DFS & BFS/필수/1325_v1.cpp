#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> hacked; // 컴퓨터 해킹 여부 저장

int dfs(int node, vector<vector<int>> &graph) { // node 컴퓨터가 해킹할 수 있는 컴퓨터 개수 세기
    int cnt = 1; // node가 해킹할 수 있는 컴퓨터 수
    hacked[node] = true;

    for(int i = 0; i < graph[node].size(); i++) { // node 컴퓨터가 해킹할 수 있는 컴퓨터 탐색
        int next_node = graph[node][i];
        if(!hacked[next_node]) { // 아직 해킹되지 않은 컴퓨터 발견
            cnt += dfs(next_node, graph);
        }
    }
    return cnt;
}

vector<int> hack(int n, vector<vector<int>> &graph) { // 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터 번호 반환
    int max_cnt = 0; // 감염된 컴퓨터 수의 최댓값
    vector<int> result; // 컴퓨터 번호 저장

    for(int i = 1; i <= n; i++) { // i : 최초로 해킹된 컴퓨터
        hacked.assign(n+1, false); // (탐색 시작전 전역변수 초기화 필요)
        int tmp = dfs(i, graph); // tmp : i번 컴퓨터가 해킹한 컴퓨터 수

        if(tmp > max_cnt) { // 최댓값 갱신
            max_cnt = tmp;
            result = {i};
        }
        else if(tmp == max_cnt) { // 컴퓨터 번호만 push
            result.push_back(i);
        }
    }
    return result;
}

/*
 * [가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터 번호 구하기]
 * 그래프 탐색을 이용하여 컴퓨터별 해킹할 수 있는 컴퓨터 수를 구한다.
*/

int main() {
    int n, m, a, b;
    vector<vector<int>> graph;

    // 입력
    cin >> n >> m;
    graph.assign(n+1, vector<int> (0));
    while(m--) {
        /*
         * a는 b를 신뢰한다
         * == b는 a를 감염시킬 수 있다
        */
        cin >> a >> b;
        graph[b].push_back(a);
    }

    // 연산 & 출력
    vector<int> result = hack(n, graph);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}
