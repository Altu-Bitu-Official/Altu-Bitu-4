#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100000 + 1 // MAX상수 선언

int n, r, q;  // 정점 수, 루트 번호, 쿼리 수
int from, to; // 간선 입력
int q_num;    // 쿼리 번호
vector<int> connect[MAX];
int dp[MAX];
bool visited[MAX];

void Input()
{
    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> from >> to;
        connect[from].push_back(to);
        connect[to].push_back(from);
    }
}

int countSubTree(int now)
{
    if (visited[now])
    {
        return dp[now];
    }
    visited[now] = true;
    int subTreeNum = 1;
    for (int i = 0; i < connect[now].size(); i++)
    {
        int childNum = connect[now][i];
        if (visited[childNum])
        {
            continue;
        }
        else
        {
            subTreeNum += countSubTree(childNum);
        }
    }
    dp[now] = subTreeNum;
    return dp[now];
}

int main()
{
    ios_base ::sync_with_stdio(false); // 시간 단축
    cin.tie(NULL);
    cout.tie(NULL);

    Input();

    memset(visited, 0, sizeof(visited));
    memset(dp, 0, sizeof(dp));
    dp[r] = countSubTree(r); // 루트 노드로부터 자식 노드 구하기

    for (int j = 0; j < q; j++)
    {
        cin >> q_num;
        cout << dp[q_num] << '\n';
    }

    return 0;
}
