#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS
vector<int> tookMin(vector<int> &rumor_mongers, int n, vector<vector<int>> &nbr_graph)
{
    int cnt = 0;
    queue<int> gossip;
    queue<int> influenced;

    // 모두 처음에는 안 믿는다.
    vector<int> believed(n + 1, -1);
    vector<int> cnt_nbr_believers(n + 1, 0);

    // 유포자를 큐에 넣는다 (0으로 셋팅)
    for (int rm : rumor_mongers)
    {
        believed[rm] = 0;
        gossip.push(rm);
    }

    // 루머 유포 시작
    while (!gossip.empty())
    {
        cnt++;
        int node = gossip.front();
        gossip.pop();

        for (int j = 0; j < nbr_graph[node].size(); j++)
        {
            int next_node = nbr_graph[node][j];
            // 안 믿는 사람이지만, 여론에 따라 믿게 되는 경우
            if (believed[next_node] == -1 && ++cnt_nbr_believers[next_node] >= (nbr_graph[next_node].size() + 1) / 2)
            {
                influenced.push(next_node);
                gossip.push(next_node);
            }
        }

        // node에 의해 영향 받은 사람들이 동시에 믿게 된다.
        while (!influenced.empty())
        {
            believed[influenced.front()] = believed[node] + 1;
            influenced.pop();
        }
    }
    cout << cnt << "*\n";
    return believed;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n, m, nbr, rumor_monger;
    cin >> n;
    vector<vector<int>> nbr_graph(n + 1);
    vector<int> rumor_mongers;

    for (int i = 1; i <= n; i++)
    {
        while (true)
        {
            cin >> nbr;
            if (!nbr)
            {
                break;
            }
            nbr_graph[i].push_back(nbr);
        }
    }
    cin >> m;
    while (m--)
    {
        cin >> rumor_monger;
        rumor_mongers.push_back(rumor_monger);
    }

    // 계산
    vector<int> ans = tookMin(rumor_mongers, n, nbr_graph);

    // 출력
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
}