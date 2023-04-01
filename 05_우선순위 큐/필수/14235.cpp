#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, a, v;
    cin >> n;
    // 선물 주머니
    priority_queue<int, vector<int>> pq;

    while (n--)
    {
        cin >> a;
        // 아이들을 만남.
        if (a == 0)
        {
            // 줄 선물이 없음
            if (pq.empty())
            {
                cout << -1 << '\n';
            }
            // 제일 좋은 선물 줌
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }

        // 거점지라면 그만큼 선물을 충전함
        else
        {
            while (a--)
            {
                cin >> v;
                pq.push(v);
            }
        }
    }
}