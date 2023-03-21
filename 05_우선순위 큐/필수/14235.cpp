#include <iostream>
#include <queue>
using namespace std;
// 우선순위 큐 사용
// 만일 거점지라면 선물 충전 후 정렬하기
// 거점지가 아니라면 가장 큰 수를 value로
//
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    priority_queue<int> present;
    while (n--)
    {
        int a;
        cin >> a;
        if (a == 0)
        {
            if (present.empty())
            {
                // 만일 없다면 cout <<-1
                cout << -1 << "\n";
            }
            else
            {
                // 이 경우에는 큐에서 빼서 cout
                // 이 때 가장 큰 수를 탐색
                cout << present.top() << "\n";
                present.pop();
            }
        }
        else
        { // 이 경우에는 큐에 저장하는 경우
            int k;
            while (a--)
            {
                cin >> k;
                present.push(k);
            }
        }
    }
    return 0;
}