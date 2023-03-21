#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // 우선순위 queue 사용
    priority_queue<int> q;
    int n;
    cin >> n;

    while (n--)
    { // n번 반복
        int a;
        cin >> a;

        if (a == 0)
        {
            if (q.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << q.top() << endl; // 저장된 queue에서 빼서 출력
                q.pop();                 // 제거
            }
        }
        else
        { // a가 0이 아닌 경우 queue에 저장
            int m;
            while (a--)
            { // m개의 선물을 넣기
                cin >> m;
                q.push(m);
            }
        }
    }
}