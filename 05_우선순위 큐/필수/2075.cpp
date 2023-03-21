#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e;
    priority_queue<int, vector<int>, greater<int>> min;
    cin >> n;

    // 큐 내의 원소를 (유입 중 제일 큰) n개로 유지
    for (int i = 0; i < n * n; i++)
    {
        cin >> e;
        min.push(e);
        if (i < n)
        {
            continue;
        }
        min.pop();
    }

    // 최종 제일 큰 n개 중 제일 작은 element
    cout << min.top();
}