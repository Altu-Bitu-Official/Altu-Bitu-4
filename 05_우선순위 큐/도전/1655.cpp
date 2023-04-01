#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, mid;
    priority_queue<int> l;                            // 중간값의 왼쪽
    priority_queue<int, vector<int>, greater<int>> r; // 중간값의 오른쪽

    cin >> n;

    while (n--)
    {
        cin >> m;
        if (l.empty())
        {
            l.push(m);
            cout << m << '\n';
            continue;
        }
        // 왼쪽 top보다 크면 오른쪽 큐로 이동.
        if (m > l.top())
        {
            r.push(m);
        }
        else
        {
            l.push(m);
        }
        // size가 2 이상 차이 나면, 더 큰 쪽 pop해서 다른쪽으로 넘겨줘야.

        if ((int)l.size() - (int)r.size() > 1)
        {
            r.push(l.top());
            l.pop();
        }
        else if ((int)r.size() - (int)l.size() > 1)
        {
            l.push(r.top());
            r.pop();
        }

        // 중간값 외치기 (사이즈가 더 큰 큐에서 top)
        if (l.size() > r.size())
        {
            mid = l.top();
        }
        else if (r.size() > l.size())
        {
            mid = r.top();
        }
        // 양 큐 size가 같다면, 두 top 중 작은 수
        else
        {
            mid = l.top() < r.top() ? l.top() : r.top();
        }
        cout << mid << '\n';
    }
}