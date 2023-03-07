#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> josephus(int n, int k)
{
    queue<int> circle;
    vector<int> result;

    // 1번부터 n번까지 입력
    for (int i = 1; i <= n; i++)
    {
        circle.push(i);
    }

    // k번째에 도달하려면 k-1번 건너 뛰어야되므로 decrement해줌
    k--;

    while (!circle.empty())
    {
        // k번째 수가 나올때까지 앞에서 pop후 뒤로 push
        for (int i = 0; i < k; i++)
        {
            circle.push(circle.front());
            circle.pop();
        }
        result.push_back(circle.front());
        circle.pop();
    }
    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> result = josephus(n, k);

    // 출력
    cout << '<';
    const char *padding = "";
    for (int i = 0; i < n; i++)
    {
        cout << padding << result[i];
        padding = ", ";
    }
    cout << '>';
}