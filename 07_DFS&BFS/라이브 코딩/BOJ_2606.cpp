// 2606번 바이러스
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int bfs(int n, vector<vector<int>> &adj_list)
{
    int cnt = 0;                       // 컴퓨터 개수 count
    vector<bool> hacked(n + 1, false); // 해킹여부를 선언하는 벡터
    queue<int> q;

    // 시작정점
    hacked[1] = true;
    q.push(1);

    while (!q.empty())
    {
        int node = q.front(); // 감염된 컴퓨터를 node에 선언하고
        q.pop();              // 배출

        // node와 연결된 컴퓨터 탐색
        for (int i = 0; i < adj_list[node].size(); i++)
        {
            int next_node = adj_list[node][i]; // 연결된 컴퓨터

            if (!hacked[next_node])
            {                             // 해킹이 되지 않앗다면
                hacked[next_node] = true; // 해킹처리
                cnt++;

                q.push(next_node);
            }
        }
        return cnt;
    }
}
int main()
{
    int n, e;   // 컴퓨터개수, 컴퓨터 쌍의 개수
    int n1, n2; // 컴퓨터 번호

    // 인접리스트
    vector<vector<int>> adj_list;

    cin >> n >> e;
    adj_list.assign(n + 1, vector<int>(0));

    while (n--)
    {
        cin >> n1 >> n2;
        adj_list[n1].push_back(n2);
        adj_list[n2].push_back(n1); // 양방향 처리
    }

    cout << bfs(n, adj_list);

    return 0;
}