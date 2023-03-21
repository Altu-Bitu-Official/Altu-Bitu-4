#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 시간단축
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    // 오름차순으로 n개의 정수를 vector로 저장
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < n; i++) // n행번 반복
    {
        for (int k = 0; k < n; k++)
        { // n개 사용자 정의
            int num;
            cin >> num;       // 정수 num을 사용자 정의 받고
            q.push(num);      // num을 q에 넣어서 오름차순 정리
            if (q.size() > n) // q가 n개의 크기보다 커지면 top은  n+1번째로 큰 수가 됨
            {
                q.pop(); // n번째 큰 수만 필요하기에 top을 제거
            }
        }
    }
    cout << q.top(); // n번쨰 정수 출력
}
