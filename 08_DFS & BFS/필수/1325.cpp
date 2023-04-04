#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> mostEfficientHack(vector<vector<int>> &relate, int n)
{
    vector<int> ans;
    int max_cnt = 0;

    // 1부터 n번 컴퓨터까지 다 시작해본다. (브루트 포스)
    for (int i = 1; i <= n; i++)
    {
        stack<int> s;
        vector<bool> visited(n + 1, false);

        s.push(i);
        visited[i] = true;
        int cnt = 1;
        while (!s.empty())
        {
            int node = s.top();
            s.pop();

            for (int j = 0; j < relate[node].size(); j++)
            {
                int next_node = relate[node][j];
                if (!visited[next_node])
                {
                    // 해킹된 컴퓨터 있을때마다 count
                    visited[next_node] = true;
                    cnt++;
                    s.push(next_node);
                }
            }
        }
        // 최종 cnt로 max 업데이트 및 새로운 list
        if (cnt > max_cnt)
        {
            max_cnt = cnt;
            ans.resize(0);
            ans.push_back(i);
        }
        else if (cnt == max_cnt)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> relate(n + 1);

    while (m--)
    {
        cin >> a >> b;
        relate[b].push_back(a);
    }

    vector<int> ans = mostEfficientHack(relate, n);

    for (int comp : ans)
    {
        cout << comp << ' ';
    }
}