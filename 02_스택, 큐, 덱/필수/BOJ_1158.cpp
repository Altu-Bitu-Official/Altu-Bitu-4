#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N, K, tmp;
    cin >> N >> K;
    queue<int> q;

    // N개의 숫자를 queue안에 push
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    cout << "<";
    while (q.size() > 1)
    { // 마지막 원소를 남길 때까지 반복
        for (int i = 0; i < K - 1; i++)
        { // k-1개의 원소를 queue의 뒤로 보냄
            tmp = q.front();
            q.push(tmp);
            q.pop();
        }
        cout << q.front() << ", "; // k-1개의 원소 다음의 원소 출력
        q.pop();                   // 제거
    }

    cout << q.front() << ">"; // 마지막 원소를 출력
    return 0;
}