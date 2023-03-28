#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> &base, int b)
{
    vector<int> answer(2, 2000000000);
    bool shouldContinue = false;

    // 최고높이부터 최저높이까지 루프 돌면서 하나씩 cost 구하기
    for (int std = base.front(); std >= base.back(); std--)
    {
        int cost = 0;
        int inv = b;
        for (auto it = base.begin(); it != base.end(); it++)
        {
            int curr = *it;
            if (curr == std)
            {
                continue;
            }

            // 크면 깎고 (시간X2 + 인벤토리 +)
            else if (curr > std)
            {
                inv += curr - std;
                cost += 2 * (curr - std);
            }

            // 작으면 인벤토리에서 차감 후 올리고 (시간 +)
            else
            {
                inv += curr - std;
                // 인벤토리 부족하면(inv음수) 되면 건너뛰기
                if (inv < 0)
                {
                    shouldContinue = true;
                    break;
                }
                cost += std - curr;
            }
        }

        if (shouldContinue)
        {
            shouldContinue = false;
            continue;
        }

        // cost가 더 작을시, 최종 cost & height upgrade
        if (answer[0] > cost)
        {
            answer[0] = cost;
            answer[1] = std;
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, b, h;
    cin >> n >> m >> b;
    vector<int> base;

    for (int i = 0; i < n * m; i++)
    {
        cin >> h;
        base.push_back(h);
    }

    sort(base.begin(), base.end(), greater<>());

    vector<int> answer = solution(base, b);

    cout << answer[0] << ' ' << answer[1];
}