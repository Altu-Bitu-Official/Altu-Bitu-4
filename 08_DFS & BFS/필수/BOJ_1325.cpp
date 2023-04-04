#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[10001];

int bfs(int i, int n)
{
    int cnt = 0;
    vector<bool> visited(n + 1, false);
    queue<int> q;

    q.push(i);
    visited[i] = true;
    cnt++;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int i = 0; i < graph[node].size(); i++)
        {
            int next_node = graph[node][i];
            if (!visited[next_node])
            {
                q.push(next_node);
                visited[next_node] = true;
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b, count = 0;
    cin >> n >> m; // 5 4
    vector<int> res(n + 1, 0);
    while (m--)
    {
        cin >> a >> b;
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        res[i] = bfs(i, n); // 해킹가능한 컴퓨터개수 4 4 3 1 1
        count = max(count, res[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        if (count == res[i])
        {
            cout << i << " ";
        }
    }

    return 0;
}