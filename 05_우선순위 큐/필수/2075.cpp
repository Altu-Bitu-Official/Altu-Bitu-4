#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    // 오름 차순
    priority_queue<int, vector<int>, greater<int>> nth_num;
    for (int i = 0; i < n * n; i++)
    { // 수를 받아오는 과정
        int k;
        cin >> k;

        if (nth_num.size() == n && nth_num.top() < k)
        {
            nth_num.pop();
            nth_num.push(k);
        }
        else if (nth_num.size() < n)
        {
            nth_num.push(k);
        }
    }

    // 만일 맨 밑 줄에서 가장 큰 수라면 그 수가 가장 큰 수
    // 그 다음 수: 맨 밑줄에서 두번째로 큰 수 또는 가장 큰 수의 위의 수
    cout << nth_num.top();
    return 0;
}