#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> hacked; // 컴퓨터 해킹 여부 저장

int dfs(int node, vector<vector<int>> &graph)
{                        // node 컴퓨터가 해킹할 수 있는 컴퓨터 개수 세기
    int cnt = 1;         // node가 해킹할 수 있는 컴퓨터 수
    hacked[node] = true; // true로 초기화

    for (int i = 0; i < graph[node].size(); i++)
    { // node 컴퓨터가 해킹할 수 있는 컴퓨터 탐색
        int next_node = graph[node][i];
        if (!hacked[next_node])
        { // 아직 해킹되지 않은 컴퓨터 발견
            cnt += dfs(next_node, graph);
        }
    }
    return cnt; // node 컴퓨터가 해킹할 수 있는 컴퓨터 개수 반환
}

vector<int> hack(int n, vector<vector<int>> &graph)
{                       // 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터 번호 반환
    int max_cnt = 0;    // 감염된 컴퓨터 수의 최댓값
    vector<int> result; // 컴퓨터 번호 저장

    for (int i = 1; i <= n; i++)
    {                                // i : 최초로 해킹된 컴퓨터
        hacked.assign(n + 1, false); // (탐색 시작전 전역변수 초기화 필요)
        int tmp = dfs(i, graph);     // tmp : i번 컴퓨터가 해킹한 컴퓨터 수

        if (tmp > max_cnt)
        {
            max_cnt = tmp; // 최댓값 갱신
            result = {i};  // i
        }
        else if (tmp == max_cnt) // tmp가 최댓값과 동일하다면
        {                        // 컴퓨터 번호만 push
            result.push_back(i);
        }
    }
    return result; // 컴퓨터 번호 출력
}

/*
 * [가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터 번호 구하기]
 * 그래프 탐색을 이용하여 컴퓨터별 해킹할 수 있는 컴퓨터 수를 구한다.
 */

int main()
{
    int n, m, a, b;            // n개의 번호, m줄, 신뢰하는 관계
    vector<vector<int>> graph; // 2차벡터 graph 설정

    // 입력
    cin >> n >> m;                       // 사용자 입력
    graph.assign(n + 1, vector<int>(0)); // 0으로 초기화된 이차 벡터 할당
    while (m--)                          // m번 반복
    {
        /*
         * a는 b를 신뢰한다
         * == b는 a를 감염시킬 수 있다
         */
        cin >> a >> b;
        graph[b].push_back(a); // b행에 a를 push
    }

    // 연산 & 출력
    vector<int> result = hack(n, graph); // hack의 여부를 담은 vector를 result에 저장
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' '; // 결과출력
    }
    return 0;
}